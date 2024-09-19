#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent): QObject(parent) {}

bool TCPServer::startServer(const QHostAddress &address, quint16 port) {
  if(this->listen(address, port)) {
    qDebug() << "Failed to start server";
    return false;
  }
  qDebug() << "The server is running at address " << address.toString() << " on port " << port;
  return true;
}

void TCPServer::stopServer() {
  if(this->isListening()) {
    this->close();
    QDebug() << "The server has stopped";
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
  QString response = "Server Response: Data received";
  clientSocket->write(response.toUtf8()); // Отправляем ответ клиенту
  clientSocket->flush();
}

void TCPServer::onClientDisconnected() {
  qDebug() << "The client has disconnected";
  clientSocket->deleteLater();
}
