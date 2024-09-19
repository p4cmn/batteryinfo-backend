#ifndef BATTERYINFOMODEL_H
#define BATTERYINFOMODEL_H

#include <QTime>
#include <QObject>
#include "powermode.h"
#include "batterytype.h"
#include "batteryhealth.h"
#include "powersupplytype.h"

class BatteryInfoModel : public QObject {
  Q_OBJECT

private:
  double voltage{0.0};
  int chargeLevel{0};
  double designMaxCapacity{0.0};
  PowerMode powerMode{PowerMode::Undefined};
  QTime dischargeTime{QTime(0, 0)};
  double currentMaxCapacity{0.0};
  BatteryType batteryType{BatteryType::Undefined};
  QTime remainingBatteryLifetime{QTime(0, 0)};
  BatteryHealth batteryHealth{BatteryHealth::Undefined};
  PowerSupplyType powerSupplyType{PowerSupplyType::Undefined};

  template <typename T>
  void updateValue(T &member, const T &value, void (BatteryInfoModel::*signal)(T));

  template <typename T>
  void updateValue(T &member, const T &value, void (BatteryInfoModel::*signal)(const T&));

public:
  explicit BatteryInfoModel(QObject* parent = nullptr);

  double getVoltage() const;
  int getChargeLevel() const;
  double getDesignMaxCapacity() const;
  PowerMode getPowerMode() const;
  QTime getDischargeTime() const;
  double getCurrentMaxCapacity() const;
  BatteryType getBatteryType() const;
  BatteryHealth getBatteryHealth() const;
  QTime getRemainingBatteryLifetime() const;
  PowerSupplyType getPowerSupplyType() const;

  void setVoltage(double voltage);
  void setChargeLevel(int level);
  void setDesignMaxCapacity(double capacity);
  void setBatteryType(BatteryType type);
  void setPowerMode(PowerMode mode);
  void setDischargeTime(const QTime& time);
  void setCurrentMaxCapacity(double capacity);
  void setBatteryHealth(BatteryHealth health);
  void setRemainingBatteryLifetime(const QTime& lifetime);
  void setPowerSupplyType(PowerSupplyType type);

signals:
  void voltageChanged(double voltage);
  void chargeLevelChanged(int chargeLevel);
  void designMaxCapacityChanged(double capacity);
  void powerModeChanged(PowerMode mode);
  void dischargeTimeChanged(const QTime& time);
  void currentMaxCapacityChanged(double capacity);
  void batteryTypeChanged(BatteryType type);
  void batteryHealthChanged(BatteryHealth health);
  void remainingBatteryLifetimeChanged(const QTime& lifetime);
  void powerSupplyTypeChanged(PowerSupplyType type);
};

#endif // BATTERYINFOMODEL_H
