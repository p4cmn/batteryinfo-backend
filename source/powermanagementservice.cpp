#include "powermanagementservice.h"
#include <windows.h>
#include <powrprof.h>

#pragma comment(lib, "PowrProf.lib")

PowerManagementService::PowerManagementService(QObject *parent)
    : QObject(parent) {}

void PowerManagementService::enterSleepMode() {
  SetSuspendState(FALSE, FALSE, FALSE);
}

void PowerManagementService::enterHibernateMode() {
  SetSuspendState(TRUE, FALSE, FALSE);
}
