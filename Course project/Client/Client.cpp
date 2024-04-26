//
// Created by shosh on 4/25/24.
//

#include "Client.h"

Character Client::deserealizeJSON(const QByteArray& JSON) {
   QByteArrayList JSONParams = JSON.split(',');
   QString info = JSONParams[0].split(':')[1];
   short age = JSONParams[1].split(':')[1].toInt();
   QString fear = JSONParams[2].split(':')[1];
   QString health = JSONParams[3].split(':')[1];
   QString package = JSONParams[4].split(':')[1];
   QString traits = JSONParams[5].split(':')[1];
   QString sex = JSONParams[6].split(':')[1];
   emit characterReceived(Character(age, sex, health, fear, traits, info, package));
   return Character(age, sex, health, fear, traits, info, package);
}

Client::Client() {
    BroadcastReceiver->bind(33333);
    connect(BroadcastReceiver, &QUdpSocket::readyRead, this, &Client::broadcastHandle);
    connect(ServerConnector, &QTcpSocket::readyRead, [=] {
        //All that is left is deserealising that
        qDebug() << "LEEEEES GOOOOOO";
        deserealizeJSON(ServerConnector->readAll());
    });
}

void Client::broadcastHandle() {
    char *data = new char[BroadcastReceiver->pendingDatagramSize()];
    unsigned short *sender_ip = nullptr;
    QHostAddress BroadcastSender;
    BroadcastReceiver->readDatagram(data, BroadcastReceiver->pendingDatagramSize(), &BroadcastSender, sender_ip);
    qDebug() << ServerConnector->localAddress().toString();
    QString data_in_string(data);
    emit broadcastReceived(data_in_string);
}

void Client::connectToHost(const QString& ip_address) {
  ServerConnector->connectToHost(ip_address,33334);
}




