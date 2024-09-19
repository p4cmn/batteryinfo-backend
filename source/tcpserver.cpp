#include "tcpserver.h"
#include <QDebug>

TCPServer::TCPServer(BatteryInfoController *batteryCtrl, PowerManagementController *powerCtrl, QObject *parent)
    : QTcpServer(parent), batteryController(batteryCtrl), powerController(powerCtrl) {}

bool TCPServer::startServer(const QHostAddress &address, quint16 port) {
  if(!this->listen(address, port)) {
    qDebug() << "Failed to start server";
    return false;
  }
  qDebug() << "The server is running at address " << address.toString() << " on port " << port;
  return true;
}

void TCPServer::stopServer() {
  if(this->isListening()) {
    this->close();
    qDebug() << "The server has stopped";
  }
}

void TCPServer::incomingConnection(qintptr socketDescriptor) {
  clientSocket = new QTcpSocket(this);
  if (!clientSocket->setSocketDescriptor(socketDescriptor)) {
    qDebug() << "Failed to set socket descriptor";
    clientSocket->deleteLater();
    return;
  }
  qDebug() << "New connection from: " << clientSocket->peerAddress().toString();
  connect(clientSocket, &QTcpSocket::readyRead, this, &TCPServer::handleClientRequest);
  connect(clientSocket, &QTcpSocket::disconnected, this, &TCPServer::onClientDisconnected);
}

void TCPServer::handleClientRequest() {
  QByteArray requestData = clientSocket->readAll();
  qDebug() << "Data received from the client: " << requestData;

  processRequest(requestData);
}

void TCPServer::onClientDisconnected() {
  qDebug() << "The client has disconnected";
  clientSocket->deleteLater();
}

void TCPServer::processRequest(const QByteArray &data) {
  QJsonParseError jsonError;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &jsonError);

  if (jsonError.error != QJsonParseError::NoError) {
    qDebug() << "JSON parsing error:" << jsonError.errorString();
    return;
  }

  if (!jsonDoc.isObject()) {
    qDebug() << "Invalid JSON format";
    return;
  }

  QJsonObject jsonObj = jsonDoc.object();
  QString action = jsonObj["action"].toString();

  if (action == "getBatteryInfo") {
    QJsonObject response;
    response["chargeLevel"] = batteryController->getChargeLevelFromModel();
    response["voltage"] = batteryController->getVoltageFromModel();
    response["maxCapacity"] = batteryController->getDesignMaxCapacityFromModel();
    response["currentCapacity"] = batteryController->getCurrentMaxCapacityFromModel();
    response["powerMode"] = static_cast<int>(batteryController->getPowerModeFromModel());
    response["dischargeTime"] = batteryController->getDischargeTimeFromModel().toString();
    response["batteryType"] = static_cast<int>(batteryController->getBatteryTypeFromModel());
    response["batteryHealth"] = static_cast<int>(batteryController->getBatteryHealthFromModel());
    response["remainingBatteryLifetime"] = batteryController->getRemainingBatteryLifetimeFromModel().toString();
    response["powerSupplyType"] = static_cast<int>(batteryController->getPowerSupplyTypeFromModel());

    QJsonDocument responseDoc(response);
    clientSocket->write(responseDoc.toJson());
  } else if (action == "sleep") {
    powerController->handleSleepRequest();
  } else if (action == "hibernate") {
    powerController->handleHibernateRequest();
  } else {
    qDebug() << "Unknown command";
  }
}
