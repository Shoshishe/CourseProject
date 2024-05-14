//
// Created by shosh on 5/11/24.
//

#ifndef COURSE_PROJECT_ENTERCOUNTSCREEN_H
#define COURSE_PROJECT_ENTERCOUNTSCREEN_H

#include "QLabel"
#include "QWidget"
#include "QLineEdit"
#include "QGridLayout"
#include "QPushButton"
#include "QMap"
#include "QFrame"
#include "../Client/Client.h"
#include "QSpinBox"

class EnterCountScreen : public QWidget {
Q_OBJECT
    QString entered_name;
    QLabel *EnterNameLabel = new QLabel;
    QSpinBox *CountOfPlayers = new QSpinBox;
    QPushButton *ConfirmEntering = new QPushButton;
    QGridLayout *ScreenLayout = new QGridLayout;
public:
    EnterCountScreen();

public slots:

    void sendCountSet();

signals:

    void countSet(int);
};


#endif //COURSE_PROJECT_ENTERCOUNTSCREEN_H
