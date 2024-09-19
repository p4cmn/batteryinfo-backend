#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class TCPServer: public QTcpServer{
  Q_OBJECT

private:
  QTcpSocket* clientSocket;

public:
  explicit TCPServer(QObject* parent = nullptr);
  bool startServer(const QHostAddress& address = QHostAddress::LocalHost, quint16 port = 8080);
  void stopServer();

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private slots:
  void handleClientRequest();
  void onClientDisconnected();

};

#endif // TCPSERVER_H
