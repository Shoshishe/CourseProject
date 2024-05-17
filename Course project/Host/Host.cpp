#include "Host.h"

void Host::broadcastTheHostIP() {
    QByteArray dgram = MainServer->serverAddress().toString().toUtf8() + " ";
    BroadcastSender->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, BROADCAST_PORT);
}

void Host::createServer() {
    if (!MainServer->listen(QHostAddress::Any, SERVER_PORT)) {
        BroadcastIpTimer->stop();
        qDebug() << QObject::tr("Unable to start the server");
        errorMessage = new QErrorMessage();
        errorMessage->showMessage("Unable to start the server");
        emit startFailure();
    } else {
        BroadcastIpTimer->start(5000);
        connect(BroadcastIpTimer, &QTimer::timeout, this, &Host::broadcastTheHostIP);
        TraitsSocket->disconnect();
        connect(TraitsSocket, &QUdpSocket::readyRead, this, &Host::traitHandle);
        connect(MainServer, &QTcpServer::newConnection, [=] {
            ClientsSockets.append(MainServer->nextPendingConnection());
            Character NewUserCharacter = generateCharacter();
            QJsonObject CharacterObject = serializeCharacterToJSON(&NewUserCharacter);
            CharacterObject.insert("number", QJsonValue::fromVariant(ClientsSockets.size()));
            QJsonDocument CharacterDocument(CharacterObject);
            ClientsSockets.last()->write(CharacterDocument.toJson());

            auto *AddEmptyCharactersTimer = new QTimer;
            AddEmptyCharactersTimer->setSingleShot(true);
            AddEmptyCharactersTimer->start(100);
            Character EmptyCharacter = generateEmptyCharacter();
            QJsonObject EmptyCharacterObject = serializeCharacterToJSON(&EmptyCharacter);
            QJsonDocument EmptyCharacterDocument;
            for (int i = 0; i < ClientsSockets.size() - 1; i++) {
                EmptyCharacterObject.insert("number", QJsonValue::fromVariant(i + 1));
                EmptyCharacterDocument = QJsonDocument(EmptyCharacterObject);
                ClientsSockets.last()->write(EmptyCharacterDocument.toJson());

                EmptyCharacterObject.insert("number", QJsonValue::fromVariant(ClientsSockets.size()));
                EmptyCharacterDocument = QJsonDocument(EmptyCharacterObject);
                ClientsSockets[i]->write(EmptyCharacterDocument.toJson());
            }

            if (ClientsSockets.size() == count_of_players) {
                connect(AddEmptyCharactersTimer, &QTimer::timeout, [=] {
                    BroadcastIpTimer->stop();
                    for (auto &ClientTcpSocket: ClientsSockets) {
                        ClientTcpSocket->disconnectFromHost();
                    }
                });
                emit everyoneIsInGame();
            }
        });
    }
}

void Host::hostGame(int players_count) {
    count_of_players = players_count;
    createServer();
}


static QString readRandomStatFromFile(long random_number, QFile* FileToRead) {
    auto *contentsStream = new QTextStream(FileToRead);
    QString data;
    int count_of_lines = 0;
    while (!contentsStream->atEnd()) {
        contentsStream->readLine();
        count_of_lines++;
    }
    contentsStream->seek(0);
    for (int i = 0; i <= random_number % count_of_lines; i++) {
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
    auto *HealthStateFile = new QFile("../Sources/health_states.txt");
    auto *CharacterSexFile = new QFile("../Sources/character_sex.txt");
    auto *FearsFile = new QFile("../Sources/fears.txt");
    auto *AdditionalInfoFile = new QFile("../Sources/additional_info.txt");
    auto *PackagesFile = new QFile("../Sources/packages.txt");
    auto *PersonalTraitsFile = new QFile("../Sources/personal_traits.txt");

    HealthStateFile->open(QIODevice::ReadOnly);
    CharacterSexFile->open(QIODevice::ReadOnly);
    FearsFile->open(QIODevice::ReadOnly);
    AdditionalInfoFile->open(QIODevice::ReadOnly);
    PackagesFile->open(QIODevice::ReadOnly);
    PersonalTraitsFile->open(QIODevice::ReadOnly);

    QString health = readRandomStatFromFile(random_int, HealthStateFile);
    QString sex = readRandomStatFromFile(random_int, CharacterSexFile);
    QString fears = readRandomStatFromFile(random_int, FearsFile);
    QString additional_info = readRandomStatFromFile(random_int, AdditionalInfoFile);
    QString packages = readRandomStatFromFile(random_int, PackagesFile);
    QString personal_traits = readRandomStatFromFile(random_int, PersonalTraitsFile);
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

QTcpServer *Host::getMainServer() {
    return MainServer;
}




