#ifndef COURSE_PROJECT_GAMESCREEN_H
#define COURSE_PROJECT_GAMESCREEN_H

#include "QLabel"
#include "QGridLayout"
#include "QWidget"
#include "QDebug"
#include "QVector"
#include "CharactersWindows/CharactersWindows.h"

class GameScreen : public QWidget {
    Q_OBJECT
    QGridLayout *ScreenLayout = new QGridLayout;
    QVector<CharactersWindows*> CharactersFrames;
public:
    GameScreen();
public slots:
    void addCharacterToWindow(Character PlayerCharacter);
    signals:
    void traitSent(QString);
};


#endif //COURSE_PROJECT_GAMESCREEN_H
