#ifndef COURSE_PROJECT_MAINWINDOW_H
#define COURSE_PROJECT_MAINWINDOW_H

#include "../Client/Client.h"
#include "../Host/Host.h"
#include "../EnterCountScreen/EnterCountScreen.h"
#include "../GameScreen/GameScreen.h"
#include "../WaitScreen/WaitScreen.h"
#include "QDebug"
#include "QGridLayout"
#include "QMainWindow"
#include "QPushButton"
#include "QStackedWidget"
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QTimer>
#include <QUdpSocket>
#include "QWidget"


enum ScreenIndexes {
    MainScreenIndex = 0, GameScreenIndex = 1, WaitScreenIndex = 2, EnterNameScreenIndex = 3
};

class MainWindow : public QMainWindow {
private:
    QStackedWidget *CentralScreen = new QStackedWidget(this);
    QPushButton *CreateGame = new QPushButton(this);
    QPushButton *EnterGame = new QPushButton(this);
    QPushButton *Help = new QPushButton(this);

    GameScreen* GameWindows = new GameScreen;
    WaitScreen *WaitWindow = new WaitScreen;
    EnterCountScreen *EnterCountWindow = new EnterCountScreen();

    Host *GameHost = nullptr;
    Client *GameClient = nullptr;

public:
    MainWindow();

    void changeToGameScreen();

    void changeToWaitScreen();

    void changeToEnterCountScreen();

    void changeToMainScreen();

public slots:

    void startGameAsUser();

    void startGameAsHost();

    static void showHelp();
};


#endif //COURSE_PROJECT_MAINWINDOW_H
