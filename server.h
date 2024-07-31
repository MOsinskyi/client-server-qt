#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QTime>

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

    quint16 nextBlockSize;

};
#endif // SERVER_H
