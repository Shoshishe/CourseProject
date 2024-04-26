#ifndef COURSE_PROJECT_MAINWINDOW_H
#define COURSE_PROJECT_MAINWINDOW_H

#include "QMainWindow"
#include "QPushButton"
#include "QGridLayout"
#include "QStackedWidget"
#include "QWidget"
#include "../GameScreen/GameScreen.h"
#include "../WaitScreen/WaitScreen.h"
#include "../Host/Host.h"
#include "../Client/Client.h"
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTimer>


enum ScreenIndexes {MainScreenIndex = 0, GameScreenIndex = 1, WaitScreenIndex = 2};

class MainWindow: public QMainWindow {
private:
    QStackedWidget *CentralScreen = new QStackedWidget;
    QPushButton *CreateGame = new QPushButton(this);
    QPushButton *EnterGame = new QPushButton(this);

    GameScreen *GameWindow = new GameScreen;
    WaitScreen *WaitWindow = new WaitScreen;

    Host *GameHost = nullptr;
    Client *GameClient = nullptr;

public:
    MainWindow();
    void changeToGameScreen();
    void changeToWaitScreen();
public slots:
    void startGameAsUser();
    void startGameAsHost();
};


#endif //COURSE_PROJECT_MAINWINDOW_H
