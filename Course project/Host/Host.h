//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_HOST_H
#define COURSE_PROJECT_HOST_H

#include "../Client/Client.h"
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
#include "../Middleware/Randomisation.h"
#include "QJsonObject"
#include "QJsonDocument"

class Host : public Client {
private:
    QUdpSocket *BroadcastSender = new QUdpSocket(this);
    QTcpServer *MainServer = new QTcpServer(this);
    QVector<QTcpSocket*> ClientsIpAddresses;
    int count_of_players;
public:
    QHostAddress getServerAddress();
    void createServer();
    void hostGame(int players_count);
    static QJsonObject serializeCharacterToJSON(Character *PlayerCharacter);
public slots:
    void broadcastTheHostIP();
    Character generateCharacter();
};


#endif //COURSE_PROJECT_HOST_H
