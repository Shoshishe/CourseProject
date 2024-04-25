//
// Created by shosh on 4/25/24.
//

#include "Character.h"

#include <utility>

Character::Character(short age, QString sex, QString health, QString fear, QString personal_traits,
                     QString additional_information, QString package) {
 this->age = age;
 this->sex = std::move(sex);
 this->health = std::move(health);
 this->fear = std::move(fear);
 this->personal_traits = std::move(personal_traits);
 this->additional_information = std::move(additional_information);
 this->package = std::move(package);
}