#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include "batteryinfocontroller.h"
#include "powermanagementcontroller.h"

class TCPServer : public QTcpServer {
  Q_OBJECT

private:
  BatteryInfoController *batteryController;
  PowerManagementController *powerController;

public:
  explicit TCPServer(BatteryInfoController *batteryCtrl, PowerManagementController *powerCtrl, QObject *parent = nullptr);
  bool startServer(const QHostAddress &address = QHostAddress::LocalHost, quint16 port = 33334);
  void stopServer();

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private slots:
  void handleClientRequest();
  void onClientDisconnected();

private:
  QTcpSocket *clientSocket;
  void processRequest(const QByteArray &data);
};

#endif // TCPSERVER_H
