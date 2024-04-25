//
// Created by shosh on 4/25/24.
//

#ifndef COURSE_PROJECT_CHARACTER_H
#define COURSE_PROJECT_CHARACTER_H

#include "QString"

class Character {
private:
    short age;
    QString sex;
    QString health;
    QString fear;
    QString personal_traits;
    QString additional_information;
    QString package;
public:
    Character(short age, QString sex, QString health, QString fear, QString personal_traits,
              QString additional_information, QString package);
};


#endif //COURSE_PROJECT_CHARACTER_H
