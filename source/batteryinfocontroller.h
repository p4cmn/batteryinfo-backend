#ifndef BATTERYINFOCONTROLLER_H
#define BATTERYINFOCONTROLLER_H

#include <QObject>
#include <QTime>
#include "batteryinfomodel.h"
#include "batteryinfoservice.h"

class BatteryInfoController : public QObject {
  Q_OBJECT

private:
  BatteryInfoModel *model;
  BatteryInfoService *service;

public:
  explicit BatteryInfoController(BatteryInfoModel *sourceModel, BatteryInfoService *sourceService, QObject *parent = nullptr);

  int getChargeLevelFromModel() const;
  double getVoltageFromModel() const;
  double getDesignMaxCapacityFromModel() const;
  double getCurrentMaxCapacityFromModel() const;
  PowerMode getPowerModeFromModel() const;
  QTime getDischargeTimeFromModel() const;
  BatteryType getBatteryTypeFromModel() const;
  BatteryHealth getBatteryHealthFromModel() const;
  QTime getRemainingBatteryLifetimeFromModel() const;
  PowerSupplyType getPowerSupplyTypeFromModel() const;

private slots:
  void handleBatteryChargeLevelChange(int level);
  void handlePowerModeChange(PowerMode powerMode);
  void handleDischargeTimeChange(const QTime& time);
  void handleRemainingBatteryLifetimeChange(const QTime& lifetime);
  void handlePowerSupplyTypeChange(PowerSupplyType type);
  void handleBatteryTypeChange(BatteryType type);
  void handleBatteryDesignMaxCapacityChange(double capacity);
  void handleBatteryCurrentMaxCapacityChange(double capacity);
  void handleBatteryVoltageChange(double voltage);
  void handleBatteryHealthChange(BatteryHealth health);
};

#endif // BATTERYINFOCONTROLLER_H
