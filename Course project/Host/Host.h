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
#include "QHostAddress"
#include "QDataStream"

class Host : public QObject {
private:
    QUdpSocket *BroadcastSender = new QUdpSocket(this);
    QTcpServer *MainServer = new QTcpServer(this);
public:
    void createServer();
    void hostGame();
    Host();
public slots:
    void broadcastTheHostIP();
};


#endif //COURSE_PROJECT_HOST_H
