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
    GameWindow->addCharacterToWindow(GameHost->generateCharacter());
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
}

void MainWindow::changeToGameScreen() {
    CentralScreen->setCurrentIndex(GameScreenIndex);
}

void MainWindow::changeToWaitScreen() {
    CentralScreen->setCurrentIndex(WaitScreenIndex);
}

