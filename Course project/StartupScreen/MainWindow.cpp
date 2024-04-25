//
// Created by shosh on 4/23/24.
//


#include "MainWindow.h"

MainWindow::MainWindow() {
    QWidget *StartupWindow = new QWidget;
    QGridLayout *ButtonsLayout = new QGridLayout(StartupWindow);
    ButtonsLayout->addWidget(CreateGame,0,0);
    ButtonsLayout->addWidget(EnterGame,1,0);

    CentralScreen->insertWidget(MainScreenIndex,StartupWindow);
    CentralScreen->insertWidget(GameScreenIndex, GameWindow);
    CentralScreen->insertWidget(WaitScreenIndex, WaitWindow);

    this->setCentralWidget(CentralScreen);
    StartupWindow->setMinimumSize(500, 500);
    CentralScreen->setMinimumSize(500, 500);
    this->setMinimumSize(500,500);


    CreateGame->setText("Create a game");
    EnterGame->setText("Enter the game");


    connect(CreateGame, &QPushButton::pressed, this, &MainWindow::startGameAsHost);
    connect(EnterGame, &QPushButton::pressed, this, &MainWindow::startGameAsUser);
    this->show();
}

void MainWindow::startGameAsHost() {
    changeToGameScreen();
    GameHost = new Host;
    GameHost->hostGame();
}

void MainWindow::startGameAsUser() {
    changeToWaitScreen();
    GameClient = new Client;
    connect(GameClient, &Client::broadcastReceived, WaitWindow, &WaitScreen::AddNewHostEntry);
}

void MainWindow::changeToGameScreen() {
    CentralScreen->setCurrentIndex(GameScreenIndex);
}

void MainWindow::changeToWaitScreen() {
    CentralScreen->setCurrentIndex(WaitScreenIndex);
}


void MainWindow::SendUserConnectionRequest() {
 QUdpSocket *IpSender = new QUdpSocket;

 //Implementation of connecting user. User gets the list of all possible options, with the NAME of the user and probably ip, and chooses the server

 QTcpSocket *Connector = new QTcpSocket;
 QByteArray dgram = "Sending address";
 IpSender->writeDatagram(dgram.data(), dgram.size(), QHostAddress::Broadcast, 33333);
 connect(IpSender, &QUdpSocket::readyRead, [Connector, IpSender] {
     char *datagram_content = new char[IpSender->pendingDatagramSize()];
     QHostAddress *SenderIP = new QHostAddress;
     IpSender->readDatagram(datagram_content, IpSender->pendingDatagramSize(), SenderIP);
 });
}

