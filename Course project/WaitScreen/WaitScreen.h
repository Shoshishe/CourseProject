//
// Created by shosh on 4/24/24.
//

#ifndef COURSE_PROJECT_WAITSCREEN_H
#define COURSE_PROJECT_WAITSCREEN_H

#include "QLabel"
#include "QWidget"
#include "QGridLayout"
#include "QPushButton"
#include "QMap"
#include "QFrame"
#include "../Client/Client.h"

class WaitScreen : public QWidget {
private:
    QLabel *PlaceHolder = new QLabel("Waiting...");
    QGridLayout *ScreenLayout = new QGridLayout();
    Client *WaitingUser = nullptr;
public:
    void setUserAsWaiting(Client *User);
    WaitScreen();
public slots:
    void AddNewHostEntry(const QString& ip_address);
};


#endif //COURSE_PROJECT_WAITSCREEN_H
