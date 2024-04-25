//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_CLIENT_H
#define COURSE_PROJECT_CLIENT_H

#include <QTcpSocket>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTimer>
#include "QObject"
#include "QDataStream"

class Client : public QObject {
    Q_OBJECT
private:
    QUdpSocket *BroadcastReceiver = new QUdpSocket(this);
    QTcpSocket *ServerConnector = new QTcpSocket(this);
public:
    Client();
public slots:
    void broadcastHandle();
       signals:
    void broadcastReceived(QString);
};


#endif //COURSE_PROJECT_CLIENT_H
