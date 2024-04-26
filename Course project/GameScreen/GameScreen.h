//
// Created by shosh on 4/23/24.
//

#ifndef COURSE_PROJECT_GAMESCREEN_H
#define COURSE_PROJECT_GAMESCREEN_H

#include "QLabel"
#include "QWidget"
#include "QDebug"
#include "QVector"
#include "CharactersWindows/CharactersWindows.h"

class GameScreen : public QWidget {
    QLabel *PlaceHolder = new QLabel("There should be something");
    QVector<CharactersWindows*> CharactersFrames;
public:
    GameScreen();
public slots:
    void addCharacterToWindow(Character PlayerCharacter);
};


#endif //COURSE_PROJECT_GAMESCREEN_H
