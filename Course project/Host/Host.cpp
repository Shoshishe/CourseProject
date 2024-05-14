#include "Host.h"

void Host::broadcastTheHostIP() {
    QByteArray dgram = MainServer->serverAddress().toString().toUtf8() + " ";
    BroadcastSender->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, BROADCAST_PORT);
}

void Host::createServer() {
    if (!MainServer->listen(QHostAddress::Any, SERVER_PORT)) {
        qDebug() << QObject::tr("Unable to start the server");
    }
    VotesFinder->bind(RANDOM_PORT);

    auto *BroadcastIpTimer = new QTimer(this);
    BroadcastIpTimer->start(5000);
    //Turn into a field of class and move upside.
    connect(BroadcastIpTimer, &QTimer::timeout, this, &Host::broadcastTheHostIP);
    TraitsSocket->disconnect();
    connect(TraitsSocket, &QUdpSocket::readyRead, this, &Host::traitHandle);
    VotesFinder->open(QIODevice::ReadWrite);
    connect(VotesFinder, &QTcpSocket::readyRead, this,[=] {
       qDebug() << "oho";
    });
    connect(MainServer, &QTcpServer::newConnection,[=] {
        ClientsIpAddresses.append(MainServer->nextPendingConnection());
        Character NewUserCharacter = generateCharacter();
        QJsonObject CharacterObject = serializeCharacterToJSON(&NewUserCharacter);
        CharacterObject.insert("number",QJsonValue::fromVariant(ClientsIpAddresses.size()));
        QJsonDocument CharacterDocument(CharacterObject);
        ClientsIpAddresses.last()->write(CharacterDocument.toJson());

        auto *AddEmptyCharactersTimer = new QTimer;
        AddEmptyCharactersTimer->setSingleShot(true);
        AddEmptyCharactersTimer->start(100);
            Character EmptyCharacter = generateEmptyCharacter();
            QJsonObject EmptyCharacterObject = serializeCharacterToJSON(&EmptyCharacter);
            QJsonDocument EmptyCharacterDocument;
            for (int i = 0; i < ClientsIpAddresses.size() - 1; i++) {
                EmptyCharacterObject.insert("number", QJsonValue::fromVariant(i + 1));
                EmptyCharacterDocument = QJsonDocument(EmptyCharacterObject);
                ClientsIpAddresses.last()->write(EmptyCharacterDocument.toJson());

                EmptyCharacterObject.insert("number", QJsonValue::fromVariant(ClientsIpAddresses.size()));
                EmptyCharacterDocument = QJsonDocument(EmptyCharacterObject);
                ClientsIpAddresses[i]->write(EmptyCharacterDocument.toJson());
            }

        if (ClientsIpAddresses.size() == count_of_players) {
            connect(AddEmptyCharactersTimer, &QTimer::timeout, [=] {
            BroadcastIpTimer->stop();
            for (auto &ClientsIpAddress : ClientsIpAddresses) {
                ClientsIpAddress->disconnectFromHost();
            }
            });
        }
    });
}

void Host::hostGame(int players_count) {
    count_of_players = players_count;
    createServer();
}

//TODO: FIND OUT THE WAY TO DELETE MOST VOTED CHARACTER

static QString readRandomStatFromFile(long random_number, QFile* FileToRead) {
    auto *contentsStream = new QTextStream(FileToRead);
    QString data;
    for (int i = 0; i < random_number % 100; i++) {
        if (!contentsStream->atEnd()) {
            data = contentsStream->readLine();
        } else {
            contentsStream->seek(0);
        }
    }
    return data;
}

Character Host::generateCharacter() {
    unsigned int random_int = MurmurHash2(salt, salt_length);
    random_int = xorShift(random_int);
    auto *HealthState = new QFile("../Sources/health_states.txt");
    auto *CharacterSex = new QFile("../Sources/character_sex.txt");
    auto *Fears = new QFile("../Sources/fears.txt");
    auto *AdditionalInfo = new QFile("../Sources/additional_info.txt");
    auto *Packages = new QFile("../Sources/packages.txt");
    auto *PersonalTraits = new QFile("../Sources/personal_traits.txt");

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

QHostAddress Host::getServerAddress() {
    return MainServer->serverAddress();
}

Character Host::generateEmptyCharacter() {
    QString Empty = "UNKNOWN";
    return Character(-1, Empty, Empty, Empty, Empty, Empty, Empty);
}

void Host::traitHandle() {
    Client::traitHandle();
    if (this->current_player == count_of_players && !stopVoting->isActive()) {
        startVoting();
    }
}

void Host::startVoting() {
    stopVoting->setSingleShot(true);
    stopVoting->start(7500);
    connect(stopVoting, &QTimer::timeout, this, &Host::sendVotingEnd);
    QByteArray data = "voting ";
    TraitsSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, TRAITS_PORT);
}

void Host::sendVotingEnd() {
    emit giveTurnToHost();
}




