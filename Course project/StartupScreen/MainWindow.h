#ifndef COURSE_PROJECT_MAINWINDOW_H
#define COURSE_PROJECT_MAINWINDOW_H

#include "../Client/Client.h"
#include "../Host/Host.h"
#include "../EnterCountcreen/EnterCountScreen.h"
#include "../GameScreen/GameScreen.h"
#include "../WaitScreen/WaitScreen.h"
#include "QDebug"
#include "QGridLayout"
#include "QMainWindow"
#include "QPushButton"
#include "QStackedWidget"
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QUdpSocket>
#include "QWidget"


enum ScreenIndexes {MainScreenIndex = 0, GameScreenIndex = 1, WaitScreenIndex = 2, EnterNameScreenIndex = 3};

class MainWindow: public QMainWindow {
private:
    QStackedWidget *CentralScreen = new QStackedWidget(this);
    QPushButton *CreateGame = new QPushButton(this);
    QPushButton *EnterGame = new QPushButton(this);

    GameScreen *GameWindow = new GameScreen;
    WaitScreen *WaitWindow = new WaitScreen;
    EnterCountScreen *EnterCountWindow = new EnterCountScreen();

    Host *GameHost = nullptr;
    Client *GameClient = nullptr;

public:
    MainWindow();
    void changeToGameScreen();
    void changeToWaitScreen();
    void changeToEnterCountScreen();
public slots:
    void startGameAsUser();
    void startGameAsHost();
};


#endif //COURSE_PROJECT_MAINWINDOW_H
