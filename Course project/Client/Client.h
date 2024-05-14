#ifndef COURSE_PROJECT_CLIENT_H
#define COURSE_PROJECT_CLIENT_H

#include "QDebug"
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTimer>
#include "QObject"
#include "QDataStream"
#include "../Models/Character.h"

const int TRAITS_PORT = 33336;
const int SERVER_PORT = 33334;
const int BROADCAST_PORT = 33333;
const int RANDOM_PORT = 33567;

class Client : public QObject {
    Q_OBJECT
protected:
    int index = -1;
    int player_number = 1;
    int current_player = 1;
    int count_of_votes = 0;
    bool is_in_game = true;
    bool had_voted = false;
    QUdpSocket *BroadcastReceiver = new QUdpSocket(this);
    QUdpSocket *TraitsSocket = new QUdpSocket(this);
    QTimer ConnectAgain;
    QTcpSocket *ServerConnector = new QTcpSocket(this);
public:
    Client();
    void deserializeJson(const QByteArray& JsonList);
public slots:
    void broadcastHandle();
    virtual void traitHandle();
    void connectToHost(const QString& ip_address);
    void sendTraitOverUdp(const QString& trait);
    void sendVote(int voted_number);
       signals:
    void characterReceived(Character, int);
    void broadcastReceived(QString);
    void traitReceived(QString);
    void madeNoTurn(int);
    void voteReceived(int);
    void turnReceived();
    void votingStarted();
    void connected();
};


#endif //COURSE_PROJECT_CLIENT_H
