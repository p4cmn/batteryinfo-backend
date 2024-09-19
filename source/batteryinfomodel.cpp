#include "batteryinfomodel.h"


BatteryInfoModel::BatteryInfoModel(QObject *parent)
    : QObject(parent)
{}

double BatteryInfoModel::getVoltage() const {
  return voltage;
}

int BatteryInfoModel::getChargeLevel() const {
  return chargeLevel;
}

double BatteryInfoModel::getDesignMaxCapacity() const {
  return designMaxCapacity;
}

PowerMode BatteryInfoModel::getPowerMode() const {
  return powerMode;
}

QTime BatteryInfoModel::getDischargeTime() const {
  return dischargeTime;
}

double BatteryInfoModel::getCurrentMaxCapacity() const {
  return currentMaxCapacity;
}

BatteryType BatteryInfoModel::getBatteryType() const {
  return batteryType;
}

BatteryHealth BatteryInfoModel::getBatteryHealth() const {
  return batteryHealth;
}

QTime BatteryInfoModel::getRemainingBatteryLifetime() const {
  return remainingBatteryLifetime;
}

PowerSupplyType BatteryInfoModel::getPowerSupplyType() const {
  return powerSupplyType;
}

template <typename T>
void BatteryInfoModel::updateValue(T &member, const T &value, void (BatteryInfoModel::*signal)(T)) {
  if (member != value) {
    member = value;
    emit (this->*signal)(value);
  }
}

template <typename T>
void BatteryInfoModel::updateValue(T &member, const T &value, void (BatteryInfoModel::*signal)(const T&)) {
  if (member != value) {
    member = value;
    emit (this->*signal)(value);
  }
}

void BatteryInfoModel::setVoltage(double voltage) {
  updateValue(this->voltage, voltage, &BatteryInfoModel::voltageChanged);
}

void BatteryInfoModel::setChargeLevel(int level) {
  updateValue(this->chargeLevel, level, &BatteryInfoModel::chargeLevelChanged);
}

void BatteryInfoModel::setDesignMaxCapacity(double capacity) {
  updateValue(this->designMaxCapacity, capacity, &BatteryInfoModel::designMaxCapacityChanged);
}

void BatteryInfoModel::setBatteryType(BatteryType type) {
  updateValue(this->batteryType, type, &BatteryInfoModel::batteryTypeChanged);
}

void BatteryInfoModel::setPowerMode(PowerMode mode) {
  updateValue(this->powerMode, mode, &BatteryInfoModel::powerModeChanged);
}

void BatteryInfoModel::setDischargeTime(const QTime& time) {
  updateValue(this->dischargeTime, time, &BatteryInfoModel::dischargeTimeChanged);
}

void BatteryInfoModel::setCurrentMaxCapacity(double capacity) {
  updateValue(this->currentMaxCapacity, capacity, &BatteryInfoModel::currentMaxCapacityChanged);
}

void BatteryInfoModel::setBatteryHealth(BatteryHealth health) {
  updateValue(this->batteryHealth, health, &BatteryInfoModel::batteryHealthChanged);
}

void BatteryInfoModel::setRemainingBatteryLifetime(const QTime& lifetime) {
  updateValue(this->remainingBatteryLifetime, lifetime, &BatteryInfoModel::remainingBatteryLifetimeChanged);
}

void BatteryInfoModel::setPowerSupplyType(PowerSupplyType type) {
  updateValue(this->powerSupplyType, type, &BatteryInfoModel::powerSupplyTypeChanged);
}
