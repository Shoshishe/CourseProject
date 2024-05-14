//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_HOST_H
#define COURSE_PROJECT_HOST_H

#include "../Client/Client.h"
#include "QElapsedTimer"
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
    Q_OBJECT
private:
    QUdpSocket *BroadcastSender = new QUdpSocket(this);
    QTcpSocket *VotesFinder = new QTcpSocket(this);
    QTcpServer *MainServer = new QTcpServer(this);
    QVector<QTcpSocket *> ClientsIpAddresses;
    QTimer *stopVoting = new QTimer;
    int count_of_players;
    int player_with_the_most_votes;
    int max_votes = 0;
public:
    QHostAddress getServerAddress();

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
};


#endif //COURSE_PROJECT_HOST_H
