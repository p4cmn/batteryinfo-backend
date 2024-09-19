#include "powermanagementcontroller.h"

PowerManagementController::PowerManagementController(PowerManagementService *service, QObject *parent)
    : QObject(parent), service(service) {}

void PowerManagementController::handleSleepRequest() {
  service->enterSleepMode();
}

void PowerManagementController::handleHibernateRequest() {
  service->enterHibernateMode();
}
