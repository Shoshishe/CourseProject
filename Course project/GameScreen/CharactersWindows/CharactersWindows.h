//
// Created by shosh on 4/26/24.
//

#ifndef COURSE_PROJECT_CHARACTERSWINDOWS_H
#define COURSE_PROJECT_CHARACTERSWINDOWS_H

#include "QFrame"
#include "../../Models/Character.h"
#include "QLabel"
#include "QWidget"
#include "QVBoxLayout"
#include "QGridLayout"

class CharactersWindows: public QFrame {
 Character *PlayerCharacter = nullptr;
public:
    QWidget *CreateCharacterWidget();
    CharactersWindows(Character &GivenCharacter);
};


#endif //COURSE_PROJECT_CHARACTERSWINDOWS_H
