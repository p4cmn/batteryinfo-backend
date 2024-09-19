#ifndef POWERMANAGEMENTSERVICE_H
#define POWERMANAGEMENTSERVICE_H

#include <QObject>

class PowerManagementService : public QObject {
  Q_OBJECT

public:
  explicit PowerManagementService(QObject *parent = nullptr);

  void enterSleepMode();
  void enterHibernateMode();
};

#endif // POWERMANAGEMENTSERVICE_H
