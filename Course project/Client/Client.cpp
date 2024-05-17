#include "Client.h"


void Client::deserializeJson(const QByteArray& JsonList) {
    QByteArrayList Object = JsonList.split('{');
    for (const auto & Json : Object) {
        if (!Json.isEmpty()) {
            QByteArrayList JsonParams = Json.split(',');
            QString info = JsonParams[0].split(':')[1];
            short age = JsonParams[1].split(':')[1].toShort();
            QString fear = JsonParams[2].split(':')[1];
            QString health = JsonParams[3].split(':')[1];
            if (index == 0) {
                player_number = JsonParams[4].split(':')[1].toInt();
            }
            int sendedCharacterNumber = JsonParams[4].split(':')[1].toInt();
            QString package = JsonParams[5].split(':')[1];
            QString traits = JsonParams[6].split(':')[1];
            QString sex = JsonParams[7].split(':')[1].chopped(2);
            emit characterReceived(Character(age, sex, health, fear, traits, info, package), sendedCharacterNumber);
        }
        index++;
    }
}

Client::Client() {
    BroadcastReceiver->bind(BROADCAST_PORT,QUdpSocket::ShareAddress);
    TraitsSocket->bind(TRAITS_PORT, QUdpSocket::ShareAddress);
    TraitsSocket->open(QIODevice::ReadWrite);
    connect(BroadcastReceiver, &QUdpSocket::readyRead, this, &Client::broadcastHandle);
    connect(TraitsSocket, &QUdpSocket::readyRead,this, &Client::traitHandle);
    connect(ServerConnector, &QTcpSocket::readyRead, [=] {
        QByteArray data = ServerConnector->readAll();
            deserializeJson(data);
    });
}

void Client::broadcastHandle() {
    char *data = new char[BroadcastReceiver->pendingDatagramSize() + 1];
    unsigned short *sender_ip = nullptr;
    QHostAddress BroadcastSender;
    BroadcastReceiver->readDatagram(data, BroadcastReceiver->pendingDatagramSize(), &BroadcastSender, sender_ip);
    QString data_in_string(data);
    emit broadcastReceived(data_in_string.split(" ")[0]);
}

void Client::connectToHost(const QString& ip_address) {
   ServerConnector->connectToHost(QHostAddress(ip_address),SERVER_PORT);
}

void Client::sendTraitOverUdp(const QString& trait) {
    QByteArray data = trait.toUtf8();
    TraitsSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, TRAITS_PORT);
}

void Client::traitHandle() {
    char *data = new char[TraitsSocket->pendingDatagramSize() + 1];
    unsigned short *sender_ip = nullptr;
    QHostAddress BroadcastSender;
    TraitsSocket->readDatagram(data, TraitsSocket->pendingDatagramSize(), &BroadcastSender, sender_ip);
    QString data_in_string(data);
    bool ok;
    if (data_in_string.split(",").size() > 1) {
        int senderNumber = data_in_string.split(",")[1].split(" ")[0].toInt(&ok);
        if (ok) {
            current_player = senderNumber;
        }
        emit traitReceived(data_in_string);
        if (senderNumber + 1 == player_number) {
            emit turnReceived();
        }
    }
    else if (data_in_string.split(" ")[0] == "voting") {
        emit votingStarted();
    } else if (data_in_string.split(" ")[0] == "vote") {
        if (data_in_string.split(" ")[1].toInt() == player_number) {
            count_of_votes++;
            emit voteReceived(data_in_string.split(" ")[1].toInt());
        } else {
            emit voteReceived(data_in_string.split(" ")[1].toInt());
        }
    }
}

void Client::sendVote(int voted_number) {
    QByteArray data = ("vote " + QString::number(voted_number) + " ").toUtf8();
    TraitsSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, TRAITS_PORT);
    had_voted = true;
}






