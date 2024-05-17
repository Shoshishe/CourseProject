#include "MainWindow.h"

MainWindow::MainWindow() {
    auto *StartupWindow = new QWidget;
    auto *ButtonsLayout = new QGridLayout(StartupWindow);
    ButtonsLayout->addWidget(CreateGame, 0, 0);
    ButtonsLayout->addWidget(EnterGame, 1, 0);
    ButtonsLayout->addWidget(Help, 2, 0);

    GameWindows->setMaximumSize(800, 800);
    CentralScreen->insertWidget(MainScreenIndex, StartupWindow);
    CentralScreen->insertWidget(GameScreenIndex, GameWindows);
    CentralScreen->insertWidget(WaitScreenIndex, WaitWindow);
    CentralScreen->insertWidget(EnterNameScreenIndex, EnterCountWindow);

    this->setCentralWidget(CentralScreen);
    StartupWindow->setMinimumSize(500, 500);
    StartupWindow->setMaximumSize(800, 800);
    CentralScreen->setMinimumSize(500, 500);
    CentralScreen->setMaximumSize(800, 800);
    this->setMinimumSize(500, 500);
    this->setMaximumSize(800, 800);

    CreateGame->setText("Create a game");
    EnterGame->setText("Enter the game");
    Help->setText("Help");


    connect(CreateGame, &QPushButton::pressed, this, &MainWindow::startGameAsHost);
    connect(EnterGame, &QPushButton::pressed, this, &MainWindow::startGameAsUser);
    connect(Help, &QPushButton::pressed, this, &MainWindow::showHelp);
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
        connect(GameHost, &Host::startFailure, [=] {
           this->disconnect();
           GameHost->disconnect();
           this->changeToMainScreen();
        });
        GameHost->hostGame(count);

        connect(GameHost, &Host::giveTurnToHost, GameWindows, &GameScreen::setTurn);
        connect(GameHost, &Client::characterReceived, GameWindows, &GameScreen::addCharacterToWindow);
        connect(GameHost, &Client::characterReceived, [=] {
            connect(GameWindows, &GameScreen::traitSent, GameHost, &Client::sendTraitOverUdp);
            connect(GameHost, &Client::traitReceived, GameWindows, &GameScreen::changeTrait);

            connect(GameHost, &Client::turnReceived, GameWindows, &GameScreen::setTurn);
            connect(GameHost, &Client::votingStarted, GameWindows, &GameScreen::enableVoteButton);
            connect(GameWindows, &GameScreen::voteMade, GameHost, &Client::sendVote);
            connect(GameHost, &Client::voteReceived, GameWindows, &GameScreen::changeVotes);

            connect(GameHost, &Host::everyoneIsInGame, [=] {
                GameWindows->setTurn();
            });
        });
        GameHost->connectToHost(GameHost->getServerAddress().toString());
    });
}

void MainWindow::startGameAsUser() {
    GameClient = new Client;
    connect(GameClient, &Client::broadcastReceived, WaitWindow, &WaitScreen::addNewHostEntry);
    WaitWindow->setUserAsWaiting(GameClient);
    changeToWaitScreen();
    connect(GameClient, &Client::connected, [=] {
        this->changeToGameScreen();
    });
    connect(GameClient, &Client::characterReceived, GameWindows, &GameScreen::addCharacterToWindow);
    connect(GameClient, &Client::characterReceived, [=] {
        connect(GameWindows, &GameScreen::traitSent, GameClient, &Client::sendTraitOverUdp);
        connect(GameClient, &Client::traitReceived, GameWindows, &GameScreen::changeTrait);

        connect(GameClient, &Client::turnReceived, GameWindows, &GameScreen::setTurn);
        connect(GameClient, &Client::votingStarted, GameWindows, &GameScreen::enableVoteButton);
        connect(GameWindows, &GameScreen::voteMade, GameClient, &Client::sendVote);
        connect(GameClient, &Client::voteReceived, GameWindows, &GameScreen::changeVotes);
    });
}

void MainWindow::changeToGameScreen() {
    this->setMaximumSize(800, 800);
    CentralScreen->setCurrentIndex(GameScreenIndex);
}

void MainWindow::changeToWaitScreen() {
    CentralScreen->setCurrentIndex(WaitScreenIndex);
}

void MainWindow::changeToEnterCountScreen() {
    CentralScreen->setCurrentIndex(EnterNameScreenIndex);
}

void MainWindow::changeToMainScreen() {
    CentralScreen->setCurrentIndex(MainScreenIndex);
}

void MainWindow::showHelp() {
    auto *HelpText = new QTextEdit;
    HelpText->setText("Shelter is a game for a company of 4 or more people. You have a list of traits, that you show to people each round. After a trait has been"
                      "revealed, player has time to prove that he is worthy enough to stay in the Shelter, and after every player revealed his stats, the voting starts, during"
                      "which people choose whom has to leave the shelter, based on the given knowledge. "
                      "As for the computer variant, players have to reside on the same LAN to connect to each other. Host chooses the required count of players. The game starts only when the required amount of people had connected"
                      "After that, client and host share the same functionality. Players can send their traits, when they get they turn, and watch shown traits of other players. After the last player voted, you have a little amount of time o make decision"
                      "and vote for a person. The game is considered ended when all the traits have been shown, and no one has more to offer.");
    HelpText->show();
}

