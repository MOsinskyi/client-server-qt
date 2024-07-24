#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;

    void sendToClient(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

private:
    QVector <QTcpSocket*> sockets;
    QByteArray data;

};
#endif // SERVER_H
