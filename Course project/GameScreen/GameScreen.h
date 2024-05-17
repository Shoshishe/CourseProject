#ifndef COURSE_PROJECT_GAMESCREEN_H
#define COURSE_PROJECT_GAMESCREEN_H

#include "QDebug"
#include "QGridLayout"
#include "QLabel"
#include "QStackedWidget"
#include "QTimer"
#include "QVector"
#include "QWidget"
#include "CharactersWindows/CharactersWindows.h"

class GameScreen : public QStackedWidget {
Q_OBJECT
    int count_of_unopened_traits = 7;
    QGridLayout *ScreenLayout = new QGridLayout;
    QVector<CharactersWindows *> CharactersFrames;
    QPushButton *VoteForCharacter = new QPushButton;
    QTimer *TimeToVote = new QTimer;
public:
    GameScreen();

public slots:

    void addCharacterToWindow(Character PlayerCharacter, int character_number);

    void changeTrait(const QString &);

    void sendTrait(QString trait);

    void sendVoteMade(int voted_character);

    void setTurn();

    void enableVoteButton();

    void changeVotes(int voted_character);

    void turnToNextScreen();

signals:

    void traitSent(QString);

    void turnMade();

    void voteMade(int);


};


#endif //COURSE_PROJECT_GAMESCREEN_H
