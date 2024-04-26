//
// Created by shosh on 4/26/24.
//

#include "CharactersWindows.h"

CharactersWindows::CharactersWindows(Character &GivenCharacter) {
    PlayerCharacter = &GivenCharacter;
    QGridLayout *ScreenLayout = new QGridLayout();
    ScreenLayout->addWidget(CreateCharacterWidget());
    this->setLayout(ScreenLayout);
    this->setFrameStyle(1);
    this->show();
}

QWidget *CharactersWindows::CreateCharacterWidget() {
    QWidget *CharacterWidget = new QWidget;
    QVBoxLayout *CharacterWidgetLayout = new QVBoxLayout;

    QLabel *CharacterAge = new QLabel;
    CharacterAge->setText("Age: " + QString::number(PlayerCharacter->getCharacterAge()));
    QLabel *CharacterSex = new QLabel;
    CharacterSex->setText("Sex: " + PlayerCharacter->getCharacterSex());
    QLabel *CharacterHealth = new QLabel;
    CharacterHealth->setText("Health: " + PlayerCharacter->getCharacterHealth());
    QLabel *CharacterFear = new QLabel;
    CharacterFear->setText("Fear: " + PlayerCharacter->getCharacterFear());
    QLabel *CharacterPersonalTraits = new QLabel;
    CharacterPersonalTraits->setText("Personal traits: " + PlayerCharacter->getCharacterPersonalTraits());
    QLabel *CharacterAdditionalInfo = new QLabel;
    CharacterAdditionalInfo->setText("Additional info: " + PlayerCharacter->getCharacterAdditionalInfo());
    QLabel *CharacterPackage = new QLabel;
    CharacterPackage->setText("Package: " + PlayerCharacter->getCharacterPackage());

    CharacterWidgetLayout->addWidget(CharacterAge);
    CharacterWidgetLayout->addWidget(CharacterSex);
    CharacterWidgetLayout->addWidget(CharacterHealth);
    CharacterWidgetLayout->addWidget(CharacterFear);
    CharacterWidgetLayout->addWidget(CharacterPersonalTraits);
    CharacterWidgetLayout->addWidget(CharacterAdditionalInfo);
    CharacterWidgetLayout->addWidget(CharacterPackage);

    CharacterWidget->setLayout(CharacterWidgetLayout);

    return CharacterWidget;
}
