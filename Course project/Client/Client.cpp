//
// Created by shosh on 4/25/24.
//

#include "Client.h"

Client::Client() {
    qDebug() << BroadcastReceiver->bind(33333);
    connect(BroadcastReceiver, &QUdpSocket::readyRead, this, &Client::broadcastHandle);
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


