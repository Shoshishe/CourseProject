//
// Created by shosh on 4/26/24.
//

#include "CharactersWindows.h"

CharactersWindows::CharactersWindows(Character &GivenCharacter) {
 PlayerCharacter = &GivenCharacter;
    this->setFrameStyle(1);
    QLabel *It_works = new QLabel;
    QLabel *PlaceHolder = new QLabel("It works, trust me");
    QGridLayout *ScreenLayout = new QGridLayout();
    this->setLayout(ScreenLayout);
    ScreenLayout->addWidget(PlaceHolder, 0, 0);
    this->show();
}
