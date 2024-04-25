//
// Created by shosh on 4/25/24.
//

#include "Host.h"

void Host::broadcastTheHostIP() {
    QByteArray dgram = MainServer->serverAddress().toString().toUtf8();
    BroadcastSender->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, 33333);
//    connect(BroadcastSender, &QUdpSocket::readyRead, [=] {
//        char *datagram_content = new char[BroadcastSender->pendingDatagramSize()];
//        QHostAddress *SenderIP = new QHostAddress;
//        BroadcastSender->readDatagram(datagram_content, BroadcastSender->pendingDatagramSize(), SenderIP);
//    });
}

void Host::createServer() {

    //TODO ADD TCP CONNECTIONS

    if (!MainServer->listen(QHostAddress::Any, 33334)) {
        qDebug() << QObject::tr("Unable to start the server");
    }
    QTimer *BroadcastIpTimer = new QTimer(this);
    BroadcastIpTimer->start(5000);
    connect(BroadcastIpTimer, &QTimer::timeout, this, &Host::broadcastTheHostIP);
    connect(MainServer, &QTcpServer::newConnection,[=] {
        qDebug() << "Nice job, you've connected your client to host";
     });


    //This part will be for connecting. That means, if user had chosen you, you connect him to server and the game. broadcasting your IP is a separate story;
    connect(BroadcastSender, &QUdpSocket::readyRead, [=] {
        char *datagram_content = new char[BroadcastSender->pendingDatagramSize()];
        QHostAddress *SenderIP = new QHostAddress;
//        qDebug() << BroadcastSender->readDatagram(datagram_content, BroadcastSender->pendingDatagramSize(), SenderIP);
//        qDebug() << datagram_content;
//        qDebug() << SenderIP;
    });
}

void Host::hostGame() {
    createServer();
    QUdpSocket *TestBroadcast = new QUdpSocket;
    QByteArray dgram = "hellooo";
    TestBroadcast->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, 33333);
}

Host::Host() {

}
