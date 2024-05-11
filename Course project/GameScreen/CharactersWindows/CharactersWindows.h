//
// Created by shosh on 4/26/24.
//

#ifndef COURSE_PROJECT_CHARACTERSWINDOWS_H
#define COURSE_PROJECT_CHARACTERSWINDOWS_H

#include "QFrame"
#include "../../Models/Character.h"
#include "QLabel"
#include "QWidget"
#include "QPushButton"
#include "QVBoxLayout"
#include "QGridLayout"

class CharactersWindows: public QFrame {
    Q_OBJECT
    Character *PlayerCharacter = nullptr;
    QPushButton *CharacterAge = new QPushButton;
    QPushButton *CharacterSex = new QPushButton;
    QPushButton *CharacterHealth = new QPushButton;
    QPushButton *CharacterFear = new QPushButton;
    QPushButton *CharacterPersonalTraits = new QPushButton;
    QPushButton *CharacterAdditionalInfo = new QPushButton;
    QPushButton *CharacterPackage = new QPushButton;
public:
    QWidget *CreateCharacterWidget();
    CharactersWindows(Character &GivenCharacter);
    void connectButtonsToSignals();
    signals:
    void traitSent(QString);
};


#endif //COURSE_PROJECT_CHARACTERSWINDOWS_H
