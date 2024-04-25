//
// Created by shosh on 4/24/24.
//

#ifndef COURSE_PROJECT_WAITSCREEN_H
#define COURSE_PROJECT_WAITSCREEN_H

#include "QLabel"
#include "QWidget"
#include "QGridLayout"
#include "QPushButton"

class WaitScreen : public QWidget {
private:
    QLabel *PlaceHolder = new QLabel("Waiting...");
    QGridLayout *ScreenLayout = new QGridLayout();
public:
    WaitScreen();
public slots:
    void AddNewHostEntry(const QString& ip_address);
};


#endif //COURSE_PROJECT_WAITSCREEN_H
