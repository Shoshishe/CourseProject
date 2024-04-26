//
// Created by shosh on 4/26/24.
//

#ifndef COURSE_PROJECT_CHARACTERSWINDOWS_H
#define COURSE_PROJECT_CHARACTERSWINDOWS_H

#include "QFrame"
#include "../../Models/Character.h"
#include "QLabel"
#include "QGridLayout"

class CharactersWindows: public QFrame {
 QWidget *CharacterWidget = new QWidget(this);
 Character *PlayerCharacter = nullptr;
public:
 CharactersWindows(Character &GivenCharacter);
};


#endif //COURSE_PROJECT_CHARACTERSWINDOWS_H
