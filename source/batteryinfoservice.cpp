#include "batteryinfoservice.h"
#include <QDebug>

BatteryInfoService::BatteryInfoService(QObject* parent)
    : QObject(parent), wasCharging(false) {
  connect(&timer, &QTimer::timeout, this, &BatteryInfoService::fetchBatteryInfo);
  timer.start(1000);
}

void BatteryInfoService::fetchBatteryInfo() {
  SYSTEM_POWER_STATUS systemPowerStatus;
  if (GetSystemPowerStatus(&systemPowerStatus)) {
    updateBatteryInfo(systemPowerStatus);
  }

  HDEVINFO hdev = getBatteryDeviceHandle();
  if (hdev == INVALID_HANDLE_VALUE) return;

  for (int idev = 0; idev < 100; idev++) {
    SP_DEVICE_INTERFACE_DATA did;
    did.cbSize = sizeof(did);

    if (SetupDiEnumDeviceInterfaces(hdev, nullptr, &GUID_DEVCLASS_BATTERY, idev, &did)) {
      HANDLE hBattery = getBatteryHandle(hdev, did);
      if (hBattery != INVALID_HANDLE_VALUE) {
        BATTERY_QUERY_INFORMATION bqi;

	if (getBatteryTag(hBattery, bqi)) {
	  fetchBatteryDetails(hBattery, bqi);
	  fetchBatteryStatus(hBattery, bqi);
	}
	CloseHandle(hBattery);
      }
    } else if (GetLastError() == ERROR_NO_MORE_ITEMS) {
      break;
    }
  }
  SetupDiDestroyDeviceInfoList(hdev);
}

void BatteryInfoService::updateBatteryInfo(const SYSTEM_POWER_STATUS &systemPowerStatus) {
  emit batteryChargeLevelChanged(systemPowerStatus.BatteryLifePercent);

  PowerMode mode = convertToPowerMode(systemPowerStatus.Reserved1);
  emit powerModeChanged(mode);

  QTime remainingTime = convertBatteryLifeTimeToQTime(systemPowerStatus.BatteryLifeTime);
  emit remainingBatteryLifetimeChanged(remainingTime);

  PowerSupplyType type = convertToPowerSupplyType(systemPowerStatus.ACLineStatus);
  emit powerSupplyTypeChanged(type);

  updateChargingStatus(systemPowerStatus);
}

void BatteryInfoService::updateChargingStatus(const SYSTEM_POWER_STATUS &systemPowerStatus) {
  bool isCharging = (systemPowerStatus.ACLineStatus == 1);

  if (isCharging) {
    dischargeTimer.invalidate();
    emit batteryDischargeTimeChanged(QTime(0, 0, 0));
    wasCharging = true;
  } else if (!isCharging && wasCharging) {
    dischargeTimer.start();
    wasCharging = false;
  }

  if (dischargeTimer.isValid()) {
    QTime dischargeTime(0, 0, 0);
    dischargeTime = dischargeTime.addMSecs(dischargeTimer.elapsed());
    emit batteryDischargeTimeChanged(dischargeTime);
  }
}

QTime BatteryInfoService::convertBatteryLifeTimeToQTime(DWORD batteryFullLifeTime) {
  if (batteryFullLifeTime == (DWORD)-1) {
    return QTime();
  }
  int hours = batteryFullLifeTime / 3600;
  int minutes = (batteryFullLifeTime % 3600) / 60;
  int seconds = batteryFullLifeTime % 60;
  return QTime(hours, minutes, seconds);
}

PowerSupplyType BatteryInfoService::convertToPowerSupplyType(BYTE acLineStatus) {
  switch (acLineStatus) {
    case 0: return PowerSupplyType::DirectCurrent;
    case 1: return PowerSupplyType::AlternatingCurrent;
    case 255: return PowerSupplyType::Unknown;
    default: return PowerSupplyType::Undefined;
  }
}

PowerMode BatteryInfoService::convertToPowerMode(BYTE reserved) {
  switch (reserved) {
    case 0: return PowerMode::Ordinary;
    case 1: return PowerMode::Saving;
    default: return PowerMode::Undefined;
  }
}

BatteryType BatteryInfoService::convertToBatteryType(const QString &batteryTypeStr) {
  if (batteryTypeStr == "PbAc") return BatteryType::LeadAcid;
  if (batteryTypeStr == "LIon") return BatteryType::LithiumIon;
  if (batteryTypeStr == "Li-I") return BatteryType::LithiumIon;
  if (batteryTypeStr == "NiCd") return BatteryType::NickelCadmium;
  if (batteryTypeStr == "NiMH") return BatteryType::NickelMetalHydride;
  if (batteryTypeStr == "NiZn") return BatteryType::NickelZinc;
  if (batteryTypeStr == "RAM") return BatteryType::RechargeableAlkalineManganese;
  return BatteryType::Undefined;
}

BatteryHealth BatteryInfoService::convertToBatteryHealth(DWORD batteryHealthFlag) {
  switch (batteryHealthFlag) {
    case BATTERY_CHARGING: return BatteryHealth::Charging;
    case BATTERY_CRITICAL: return BatteryHealth::Critical;
    case BATTERY_DISCHARGING: return BatteryHealth::Discharging;
    case BATTERY_POWER_ON_LINE: return BatteryHealth::PowerOnLine;
    default: return BatteryHealth::Undefined;
  }
}

HDEVINFO BatteryInfoService::getBatteryDeviceHandle() {
  HDEVINFO hdev = SetupDiGetClassDevs(&GUID_DEVCLASS_BATTERY, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
  if (hdev == INVALID_HANDLE_VALUE) {
    emit batteryHealthChanged(BatteryHealth::Undefined);
  }
  return hdev;
}

HANDLE BatteryInfoService::getBatteryHandle(HDEVINFO hdev, SP_DEVICE_INTERFACE_DATA &did) {
  DWORD cbRequired = 0;
  SetupDiGetDeviceInterfaceDetail(hdev, &did, nullptr, 0, &cbRequired, nullptr);

  if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
    PSP_DEVICE_INTERFACE_DETAIL_DATA pdidd = (PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LPTR, cbRequired);
    if (pdidd) {
      pdidd->cbSize = sizeof(*pdidd);
      if (SetupDiGetDeviceInterfaceDetail(hdev, &did, pdidd, cbRequired, &cbRequired, nullptr)) {
        HANDLE hBattery = CreateFile(pdidd->DevicePath, GENERIC_READ | GENERIC_WRITE,
                                     FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        LocalFree(pdidd);
        return hBattery;
      }
      LocalFree(pdidd);
    }
  }
  return INVALID_HANDLE_VALUE;
}

bool BatteryInfoService::getBatteryTag(HANDLE hBattery, BATTERY_QUERY_INFORMATION &bqi) {
  DWORD dwOut;
  DWORD dwWait = 0;
  return DeviceIoControl(hBattery, IOCTL_BATTERY_QUERY_TAG, &dwWait, sizeof(dwWait),
                         &bqi.BatteryTag, sizeof(bqi.BatteryTag), &dwOut, nullptr) && bqi.BatteryTag;
}

void BatteryInfoService::fetchBatteryDetails(HANDLE hBattery, BATTERY_QUERY_INFORMATION &bqi) {
  DWORD dwOut;
  BATTERY_INFORMATION bi;
  bqi.InformationLevel = BatteryInformation;

  if (DeviceIoControl(hBattery, IOCTL_BATTERY_QUERY_INFORMATION, &bqi, sizeof(bqi),
                      &bi, sizeof(bi), &dwOut, nullptr)) {

    BatteryType batteryType = convertToBatteryType(QString::fromLatin1(reinterpret_cast<const char*>(bi.Chemistry), 4));
    emit batteryTypeChanged(batteryType);
    emit batteryDesignMaxCapacityChanged(static_cast<double>(bi.DesignedCapacity));
    emit batteryCurrentMaxCapacityChanged(static_cast<double>(bi.FullChargedCapacity));
  }
}

void BatteryInfoService::fetchBatteryStatus(HANDLE hBattery, BATTERY_QUERY_INFORMATION &bqi) {
  DWORD dwOut;
  BATTERY_WAIT_STATUS bws;
  bws.BatteryTag = bqi.BatteryTag;

  BATTERY_STATUS bs;
  if (DeviceIoControl(hBattery, IOCTL_BATTERY_QUERY_STATUS, &bws, sizeof(bws),
                      &bs, sizeof(bs), &dwOut, nullptr)) {
    emit batteryVoltageChanged(static_cast<double>(bs.Voltage));
    BatteryHealth health = convertToBatteryHealth(bs.PowerState);
    emit batteryHealthChanged(health);
  }
}
