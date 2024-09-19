#ifndef POWERMANAGEMENTCONTROLLER_H
#define POWERMANAGEMENTCONTROLLER_H

#include <QObject>
#include "powermanagementservice.h"

class PowerManagementController : public QObject {
  Q_OBJECT

private:
  PowerManagementService *service;

public:
  explicit PowerManagementController(PowerManagementService *service, QObject *parent = nullptr);

public slots:
  void handleSleepRequest();
  void handleHibernateRequest();
};

#endif // POWERMANAGEMENTCONTROLLER_H
