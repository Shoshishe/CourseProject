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

class Client : public QObject {
    Q_OBJECT
protected:
    QString name_of_player;
    QUdpSocket *BroadcastReceiver = new QUdpSocket(this);
    QUdpSocket *TraitsSocket = new QUdpSocket(this);
    QTcpSocket *ServerConnector = new QTcpSocket(this);
public:
    Client();
    Character deserealizeJSON(const QByteArray& JSON);
public slots:
    void broadcastHandle();
    void connectToHost(const QString& ip_address);
    void sendTraitOverUdp(const QString& trait);
       signals:
    void characterReceived(Character);
    void broadcastReceived(QString);
    void connected();
};


#endif //COURSE_PROJECT_CLIENT_H
