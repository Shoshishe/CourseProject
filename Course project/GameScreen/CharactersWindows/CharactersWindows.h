//
// Created by shosh on 4/26/24.
//

#ifndef COURSE_PROJECT_CHARACTERSWINDOWS_H
#define COURSE_PROJECT_CHARACTERSWINDOWS_H

#include "QDebug"
#include "QFrame"
#include "QIcon"
#include "../../Models/Character.h"
#include "QLabel"
#include "QWidget"
#include "QPushButton"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QSizePolicy"

class CharactersWindows : public QFrame {
Q_OBJECT
    QVBoxLayout *CharacterWidgetLayout = new QVBoxLayout;
    Character *PlayerCharacter = nullptr;
    int character_number;
    int number_of_votes = 0;
    bool is_turn = true;
    QPushButton *CharacterAge = new QPushButton;
    QPushButton *CharacterSex = new QPushButton;
    QPushButton *CharacterHealth = new QPushButton;
    QPushButton *CharacterFear = new QPushButton;
    QPushButton *CharacterPersonalTraits = new QPushButton;
    QPushButton *CharacterAdditionalInfo = new QPushButton;
    QPushButton *CharacterPackage = new QPushButton;
    QPushButton *VoteForCharacter = new QPushButton;
    QLabel *NumberInGame = new QLabel;
    QLabel *NumberOfVotes = new QLabel;
public:
    QWidget *CreateCharacterWidget();

    CharactersWindows(Character &GivenCharacter, int number);

    void addPlayerChangeButtonToWindow(QPushButton *NextPlayerButton);

    void connectButtonsToSignals();

    int getCharacterNumber() const;

    QPushButton* getCharacterAgeButton();

    QPushButton* getCharacterSexPushButton();

    QPushButton* getCharacterHealthPushButton();

    QPushButton* getCharacterFearPushButton();

    QPushButton* getCharacterPersonalTraitsPushButton();

    QPushButton* getCharacterAdditionalInfoPushButton();

    QPushButton* getCharacterPackagePushButton();

    QPushButton* getVoteForCharacter();

    QLabel* getCharacterNumberLabel();

    QLabel* getNumberOfVotesLabel();

    void setTurn(bool is_true);

    void replaceButtonWithLabel(QPushButton *button);

    void disableTraitsButtons();

    void enableTraitsButtons();

signals:

    void traitSent(QString);

    void turnMade();

    void voteMade(int);

    void changeToNextPlayer();

};


#endif //COURSE_PROJECT_CHARACTERSWINDOWS_H
