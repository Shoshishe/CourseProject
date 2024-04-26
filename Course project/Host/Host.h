//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_HOST_H
#define COURSE_PROJECT_HOST_H

#include <QTcpSocket>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTimer>
#include "QObject"
#include "QFile"
#include "QHostAddress"
#include "QDataStream"
#include "QMap"
#include "cstdlib"
#include "ctime"
#include "../Models/Character.h"
#include "QJsonObject"
#include "QJsonDocument"

class Host : public QObject {
private:
    QUdpSocket *BroadcastSender = new QUdpSocket(this);
    QTcpServer *MainServer = new QTcpServer(this);
    QVector<QTcpSocket*> ClientsIpAddresses;
public:
    void createServer();
    void hostGame();
    QJsonObject serializeChraracterToJSON(Character *PlayerCharacter);
    Host();
public slots:
    void broadcastTheHostIP();
    Character generateCharacter();
};


#endif //COURSE_PROJECT_HOST_H
