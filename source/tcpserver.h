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
  bool startServer(const QHostAddress &address = QHostAddress::LocalHost, quint16 port = 8089);
  void stopServer();

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private slots:
  void handleClientRequest();  // Обработка запроса от клиента
  void onClientDisconnected(); // Обработка отключения клиента

private:
  QTcpSocket *clientSocket;    // Сокет для подключения клиента
  void processRequest(const QByteArray &data); // Обработка JSON запроса
};

#endif // TCPSERVER_H
