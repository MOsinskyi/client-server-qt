#include "server.h"

Server::Server()
{
    (this->listen(QHostAddress::Any, 2323) ? qDebug() << "start..." : qDebug() << "error!");
}

void Server::sendToClient(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << str;
    socket->write(data);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::destroyed, socket, &QTcpSocket::deleteLater);

    sockets.push_back(socket);
    qDebug() << "connected socket: " << socketDescriptor;
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);

    if(in.status() == QDataStream::Ok){
        QString str;
        in >> str;
        qDebug() << "read...";
    }
    else{
        qDebug() << "QDataStream error!";
    }
}

