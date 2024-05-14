#include "MainWindow.h"

MainWindow::MainWindow() {
    auto *StartupWindow = new QWidget;
    auto *ButtonsLayout = new QGridLayout(StartupWindow);
    ButtonsLayout->addWidget(CreateGame, 0, 0);
    ButtonsLayout->addWidget(EnterGame, 1, 0);

    CentralScreen->insertWidget(MainScreenIndex, StartupWindow);
    CentralScreen->insertWidget(GameScreenIndex, GameWindow);
    CentralScreen->insertWidget(WaitScreenIndex, WaitWindow);
    CentralScreen->insertWidget(EnterNameScreenIndex, EnterCountWindow);

    this->setCentralWidget(CentralScreen);
    StartupWindow->setMinimumSize(500, 500);
    CentralScreen->setMinimumSize(500, 500);
    this->setMinimumSize(500, 500);


    CreateGame->setText("Create a game");
    EnterGame->setText("Enter the game");


    connect(CreateGame, &QPushButton::pressed, this, &MainWindow::startGameAsHost);
    connect(EnterGame, &QPushButton::pressed, this, &MainWindow::startGameAsUser);
    this->show();
}

void MainWindow::startGameAsHost() {
    this->setFixedSize(500, 400);
    changeToEnterCountScreen();
    connect(EnterCountWindow, &EnterCountScreen::countSet, [=](int count) {
        this->setMinimumSize(500, 500);
        this->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        changeToGameScreen();
        GameHost = new Host;
        GameHost->hostGame(count);

        connect(GameHost, &Host::giveTurnToHost, GameWindow, &GameScreen::setTurn);
        connect(GameHost, &Client::characterReceived, GameWindow, &GameScreen::addCharacterToWindow);
        connect(GameHost, &Client::characterReceived, [=] {
            connect(GameWindow, &GameScreen::traitSent, GameHost, &Client::sendTraitOverUdp);
            connect(GameHost, &Client::traitReceived, GameWindow, &GameScreen::changeTrait);

            connect(GameHost, &Client::turnReceived, GameWindow, &GameScreen::setTurn);
            connect(GameHost, &Client::votingStarted, GameWindow, &GameScreen::enableVoteButton);
            connect(GameWindow, &GameScreen::voteMade, GameHost, &Client::sendVote);
            connect(GameHost, &Client::voteReceived, GameWindow, &GameScreen::changeVotes);

            //TODO: START GAME ONLY WHEN EVERYONE ARRIVES
            GameWindow->setTurn();
        });
        GameHost->connectToHost(GameHost->getServerAddress().toString());
    });
}

void MainWindow::startGameAsUser() {
    GameClient = new Client;
    connect(GameClient, &Client::broadcastReceived, WaitWindow, &WaitScreen::AddNewHostEntry);
    WaitWindow->setUserAsWaiting(GameClient);
    changeToWaitScreen();
    connect(GameClient, &Client::connected, [=] {
        this->changeToGameScreen();
    });
    connect(GameClient, &Client::characterReceived, GameWindow, &GameScreen::addCharacterToWindow);
    connect(GameClient, &Client::characterReceived, [=] {
        connect(GameWindow, &GameScreen::traitSent, GameClient, &Client::sendTraitOverUdp);
        connect(GameClient, &Client::traitReceived, GameWindow, &GameScreen::changeTrait);

        connect(GameClient, &Client::turnReceived, GameWindow, &GameScreen::setTurn);
        connect(GameClient, &Client::votingStarted, GameWindow, &GameScreen::enableVoteButton);
        connect(GameWindow, &GameScreen::voteMade, GameClient, &Client::sendVote);
        connect(GameClient, &Client::voteReceived, GameWindow, &GameScreen::changeVotes);
        connect(GameClient, &Client::madeNoTurn, [=](int player) {
            qDebug() << player;
        });
    });
}

void MainWindow::changeToGameScreen() {
    CentralScreen->setCurrentIndex(GameScreenIndex);
}

void MainWindow::changeToWaitScreen() {
    CentralScreen->setCurrentIndex(WaitScreenIndex);
}

void MainWindow::changeToEnterCountScreen() {
    CentralScreen->setCurrentIndex(EnterNameScreenIndex);
}

