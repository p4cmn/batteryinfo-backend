#include "powermanagementservice.h"
#include <windows.h>
#include <powrprof.h>

PowerManagementService::PowerManagementService(QObject *parent)
    : QObject(parent) {}

void PowerManagementService::enterSleepMode() {
  SetSuspendState(FALSE, FALSE, FALSE);
}

void PowerManagementService::enterHibernateMode() {
  SetSuspendState(TRUE, FALSE, FALSE);
}
