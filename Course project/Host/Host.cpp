//
// Created by shosh on 4/25/24.
//

#include "Host.h"

void Host::broadcastTheHostIP() {
    QByteArray dgram = MainServer->serverAddress().toString().toUtf8();
    BroadcastSender->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, 33333);
}

void Host::createServer() {;
    if (!MainServer->listen(QHostAddress::Any, 33334)) {
        qDebug() << QObject::tr("Unable to start the server");
    }
    QTimer *BroadcastIpTimer = new QTimer(this);
    BroadcastIpTimer->start(5000);
    connect(BroadcastIpTimer, &QTimer::timeout, this, &Host::broadcastTheHostIP);
    connect(BroadcastSender, &QUdpSocket::readyRead, [=] {

    });
    connect(MainServer, &QTcpServer::newConnection,[=] {
        qDebug() << "Nice job, you've connected your client to host";
        ClientsIpAddresses.append(MainServer->nextPendingConnection());
        Character NewUserCharacter = generateCharacter();
        QJsonDocument doc(serializeCharacterToJSON(&NewUserCharacter));
        qDebug() << doc;
        ClientsIpAddresses.last()->write(doc.toJson());
    });
}

void Host::hostGame() {
    createServer();
}

static QString readRandomStatFromFile(long random_number, QFile* FileToRead) {
    QTextStream *contents = new QTextStream(FileToRead);
    QString data;
    for (int i = 0; i < random_number % 100; i++) {
        if (!contents->atEnd()) {
            data = contents->readLine();
        } else {
            contents->seek(0);
        }
    }
    return data;
}

Character Host::generateCharacter() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    long random_int = std::rand();
    QFile *HealthState = new QFile("../Sources/health_states.txt");
    QFile *CharacterSex = new QFile("../Sources/character_sex.txt");
    QFile *Fears = new QFile("../Sources/fears.txt");
    QFile *AdditionalInfo = new QFile("../Sources/additional_info.txt");
    QFile *Packages = new QFile("../Sources/packages.txt");
    QFile *PersonalTraits = new QFile("../Sources/personal_traits.txt");

    HealthState->open(QIODevice::ReadOnly);
    CharacterSex->open(QIODevice::ReadOnly);
    Fears->open(QIODevice::ReadOnly);
    AdditionalInfo->open(QIODevice::ReadOnly);
    Packages->open(QIODevice::ReadOnly);
    PersonalTraits->open(QIODevice::ReadOnly);

    QString health = readRandomStatFromFile(random_int, HealthState);
    QString sex = readRandomStatFromFile(random_int, CharacterSex);
    QString fears = readRandomStatFromFile(random_int, Fears);
    QString additional_info = readRandomStatFromFile(random_int, AdditionalInfo);
    QString packages = readRandomStatFromFile(random_int, Packages);
    QString personal_traits = readRandomStatFromFile(random_int, PersonalTraits);
    return Character(random_int % 72 + 18, sex, health, fears, personal_traits, additional_info, packages);
}

QJsonObject Host::serializeCharacterToJSON(Character *PlayerCharacter) {
    QJsonObject recorded_object;
    recorded_object.insert("age", QJsonValue::fromVariant(PlayerCharacter->getCharacterAge()));
    recorded_object.insert("sex", QJsonValue::fromVariant(PlayerCharacter->getCharacterSex()));
    recorded_object.insert("health", QJsonValue::fromVariant(PlayerCharacter->getCharacterHealth()));
    recorded_object.insert("fear", QJsonValue::fromVariant(PlayerCharacter->getCharacterFear()));
    recorded_object.insert("personal traits", QJsonValue::fromVariant(PlayerCharacter->getCharacterPersonalTraits()));
    recorded_object.insert("additional info", QJsonValue::fromVariant(PlayerCharacter->getCharacterAdditionalInfo()));
    recorded_object.insert("package", QJsonValue::fromVariant(PlayerCharacter->getCharacterPackage()));
    return recorded_object;
}

