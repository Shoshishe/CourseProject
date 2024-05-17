//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_HOST_H
#define COURSE_PROJECT_HOST_H

#include "cstdlib"
#include "ctime"
#include <QDataStream>
#include <QErrorMessage>
#include <QFile>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QUdpSocket>
#include "../Client/Client.h"
#include "../Middleware/Randomisation.h"
#include "../Models/Character.h"

class Host : public Client {
    Q_OBJECT
private:
    QUdpSocket *BroadcastSender = new QUdpSocket(this);
    QTcpServer *MainServer = new QTcpServer(this);
    QVector<QTcpSocket *> ClientsSockets;
    QTimer *stopVoting = new QTimer;
    QTimer *BroadcastIpTimer = new QTimer;
    QErrorMessage *errorMessage = new QErrorMessage;
    int count_of_players;
public:
    QHostAddress getServerAddress();

    QTcpServer* getMainServer();

    void createServer();

    void hostGame(int players_count);

    static QJsonObject serializeCharacterToJSON(Character *PlayerCharacter);



public slots:

    void sendVotingEnd();

    void traitHandle() override;

    void broadcastTheHostIP();

    static Character generateCharacter();

    static Character generateEmptyCharacter();

    void startVoting();

    signals:

    void giveTurnToHost();

    void everyoneIsInGame();

    void startFailure();
};


#endif //COURSE_PROJECT_HOST_H
