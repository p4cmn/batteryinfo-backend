#include "batteryinfocontroller.h"

BatteryInfoController::BatteryInfoController(BatteryInfoModel *sourceModel, BatteryInfoService *sourceService, QObject *parent)
    : QObject(parent), model(sourceModel), service(sourceService) {

  connect(service, &BatteryInfoService::batteryChargeLevelChanged, this, &BatteryInfoController::handleBatteryChargeLevelChange);
  connect(service, &BatteryInfoService::powerModeChanged, this, &BatteryInfoController::handlePowerModeChange);
  connect(service, &BatteryInfoService::batteryDischargeTimeChanged, this, &BatteryInfoController::handleDischargeTimeChange);
  connect(service, &BatteryInfoService::remainingBatteryLifetimeChanged, this, &BatteryInfoController::handleRemainingBatteryLifetimeChange);
  connect(service, &BatteryInfoService::powerSupplyTypeChanged, this, &BatteryInfoController::handlePowerSupplyTypeChange);
  connect(service, &BatteryInfoService::batteryTypeChanged, this, &BatteryInfoController::handleBatteryTypeChange);
  connect(service, &BatteryInfoService::batteryDesignMaxCapacityChanged, this, &BatteryInfoController::handleBatteryDesignMaxCapacityChange);
  connect(service, &BatteryInfoService::batteryCurrentMaxCapacityChanged, this, &BatteryInfoController::handleBatteryCurrentMaxCapacityChange);
  connect(service, &BatteryInfoService::batteryVoltageChanged, this, &BatteryInfoController::handleBatteryVoltageChange);
  connect(service, &BatteryInfoService::batteryHealthChanged, this, &BatteryInfoController::handleBatteryHealthChange);
}

int BatteryInfoController::getChargeLevelFromModel() const {
  return model->getChargeLevel();
}

double BatteryInfoController::getVoltageFromModel() const {
  return model->getVoltage();
}

double BatteryInfoController::getDesignMaxCapacityFromModel() const {
  return model->getDesignMaxCapacity();
}

double BatteryInfoController::getCurrentMaxCapacityFromModel() const {
  return model->getCurrentMaxCapacity();
}

PowerMode BatteryInfoController::getPowerModeFromModel() const {
  return model->getPowerMode();
}

QTime BatteryInfoController::getDischargeTimeFromModel() const {
  return model->getDischargeTime();
}

BatteryType BatteryInfoController::getBatteryTypeFromModel() const {
  return model->getBatteryType();
}

BatteryHealth BatteryInfoController::getBatteryHealthFromModel() const {
  return model->getBatteryHealth();
}

QTime BatteryInfoController::getRemainingBatteryLifetimeFromModel() const {
  return model->getRemainingBatteryLifetime();
}

PowerSupplyType BatteryInfoController::getPowerSupplyTypeFromModel() const {
  return model->getPowerSupplyType();
}


void BatteryInfoController::handleBatteryChargeLevelChange(int level) {
  model->setChargeLevel(level);
}

void BatteryInfoController::handlePowerModeChange(PowerMode powerMode) {
  model->setPowerMode(powerMode);
}

void BatteryInfoController::handleDischargeTimeChange(const QTime& time) {
  model->setDischargeTime(time);
}

void BatteryInfoController::handleRemainingBatteryLifetimeChange(const QTime& lifetime) {
  model->setRemainingBatteryLifetime(lifetime);
}

void BatteryInfoController::handlePowerSupplyTypeChange(PowerSupplyType type) {
  model->setPowerSupplyType(type);
}

void BatteryInfoController::handleBatteryTypeChange(BatteryType type) {
  model->setBatteryType(type);
}

void BatteryInfoController::handleBatteryDesignMaxCapacityChange(double capacity) {
  model->setDesignMaxCapacity(capacity);
}

void BatteryInfoController::handleBatteryCurrentMaxCapacityChange(double capacity) {
  model->setCurrentMaxCapacity(capacity);
}

void BatteryInfoController::handleBatteryVoltageChange(double voltage) {
  model->setVoltage(voltage);
}

void BatteryInfoController::handleBatteryHealthChange(BatteryHealth health) {
  model->setBatteryHealth(health);
}
