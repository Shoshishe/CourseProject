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
    connectButtonsToSignals();
}

QWidget *CharactersWindows::CreateCharacterWidget() {
    QWidget *CharacterWidget = new QWidget;
    QVBoxLayout *CharacterWidgetLayout = new QVBoxLayout;

    CharacterAge->setText("Age: " + QString::number(PlayerCharacter->getCharacterAge()));
    CharacterSex->setText("Sex: " + PlayerCharacter->getCharacterSex());
    CharacterHealth->setText("Health: " + PlayerCharacter->getCharacterHealth());
    CharacterFear->setText("Fear: " + PlayerCharacter->getCharacterFear());
    CharacterPersonalTraits->setText("Personal traits: " + PlayerCharacter->getCharacterPersonalTraits());
    CharacterAdditionalInfo->setText("Additional info: " + PlayerCharacter->getCharacterAdditionalInfo());
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

void CharactersWindows::connectButtonsToSignals() {

    connect(CharacterAge, &QPushButton::pressed, [=] {
        emit traitSent(CharacterAge->text());
    });
    connect(CharacterSex, &QPushButton::pressed, [=] {
        emit traitSent(CharacterSex->text());
    });
    connect(CharacterHealth, &QPushButton::pressed, [=] {
        emit traitSent(CharacterHealth->text());
    });
    connect(CharacterFear, &QPushButton::pressed, [=] {
        emit traitSent(CharacterFear->text());
    });
    connect(CharacterPersonalTraits, &QPushButton::pressed, [=] {
        emit traitSent(CharacterPersonalTraits->text());
    });
    connect(CharacterAdditionalInfo, &QPushButton::pressed, [=] {
        emit traitSent(CharacterAdditionalInfo->text());
    });
    connect(CharacterPackage, &QPushButton::pressed, [=] {
        emit traitSent(CharacterPackage->text());
    });

}
