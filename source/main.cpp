#include <QCoreApplication>
#include "TCPServer.h"
#include "batteryinfomodel.h"
#include "batteryinfoservice.h"
#include "batteryinfocontroller.h"
#include "powermanagementservice.h"
#include "powermanagementcontroller.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  BatteryInfoModel batteryModel;

  BatteryInfoService batteryService;
  PowerManagementService powerService;

  BatteryInfoController batteryController(&batteryModel, &batteryService);
  PowerManagementController powerController(&powerService);

  TCPServer server(&batteryController, &powerController);
  if (server.startServer(QHostAddress::LocalHost, 9090)) {
    qDebug() << "The server has been launched successfully";
  } else {
    qDebug() << "Error starting server";
    return -1;
  }

  return a.exec();
}
