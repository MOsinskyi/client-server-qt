#include "server.h"

Server::Server()
{
    (this->listen() ? qDebug() << "start..." : qDebug() << "error:" << this->errorString());

    qDebug() << "IP Adress: " << this->serverAddress().toString() << "Port: " << this->serverPort();

    nextBlockSize = 0;
}

void Server::sendToClient(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(version);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    for (int i = 0; i < sockets.size(); i++){
        sockets[i]->write(data);
    }
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
    in.setVersion(version);

    if(in.status() == QDataStream::Ok){
        for(;;) {
            if (nextBlockSize == 0) {
                qDebug() << "next block size = 0";
                if (socket->bytesAvailable() < 2){
                    qDebug() << "date < 2; break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "next block size = " << nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize){
                qDebug() << "data not full; break";
                break;
            }

            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << str;
            sendToClient(str);
            break;
        }
    }
    else{
        qDebug() << "QDataStream error!";
    }
}

