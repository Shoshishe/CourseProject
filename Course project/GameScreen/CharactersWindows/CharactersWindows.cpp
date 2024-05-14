#include "CharactersWindows.h"

CharactersWindows::CharactersWindows(Character &GivenCharacter, int number) {
    PlayerCharacter = &GivenCharacter;
    character_number = number;
    auto *ScreenLayout = new QGridLayout();
    ScreenLayout->addWidget(CreateCharacterWidget());
    this->setLayout(ScreenLayout);
    this->setFrameStyle(2);
    this->setEnabled(false);
    this->show();
    connectButtonsToSignals();
}

QWidget *CharactersWindows::CreateCharacterWidget() {
    auto *CharacterWidget = new QWidget;

    NumberInGame->setFrameStyle(QFrame::Panel);
    NumberInGame->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    NumberInGame->setMinimumSize(100, 20);
    NumberInGame->setAlignment(Qt::AlignHCenter);
    NumberInGame->setText(QString::number(character_number));
    NumberOfVotes->setFrameStyle(QFrame::Panel);
    NumberOfVotes->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    NumberOfVotes->setMinimumSize(100, 20);
    NumberOfVotes->setAlignment(Qt::AlignHCenter);
    NumberOfVotes->setText("Number of votes: " + QString::number(number_of_votes));
    CharacterAge->setText("Age: " + QString::number(PlayerCharacter->getCharacterAge()));
    CharacterSex->setText("Sex: " + PlayerCharacter->getCharacterSex());
    CharacterHealth->setText("Health: " + PlayerCharacter->getCharacterHealth());
    CharacterFear->setText("Fear: " + PlayerCharacter->getCharacterFear());
    CharacterPersonalTraits->setText("Personal traits: " + PlayerCharacter->getCharacterPersonalTraits());
    CharacterAdditionalInfo->setText("Additional info: " + PlayerCharacter->getCharacterAdditionalInfo());
    CharacterPackage->setText("Package: " + PlayerCharacter->getCharacterPackage());
    VoteForCharacter->setText("Vote for");
    VoteForCharacter->setVisible(false);

    CharacterWidgetLayout->addWidget(NumberInGame);
    CharacterWidgetLayout->addWidget(CharacterAge);
    CharacterWidgetLayout->addWidget(CharacterSex);
    CharacterWidgetLayout->addWidget(CharacterHealth);
    CharacterWidgetLayout->addWidget(CharacterFear);
    CharacterWidgetLayout->addWidget(CharacterPersonalTraits);
    CharacterWidgetLayout->addWidget(CharacterAdditionalInfo);
    CharacterWidgetLayout->addWidget(CharacterPackage);
    CharacterWidgetLayout->addWidget(NumberOfVotes);
    CharacterWidgetLayout->addWidget(VoteForCharacter);

    CharacterWidget->setLayout(CharacterWidgetLayout);

    return CharacterWidget;
}

void CharactersWindows::connectButtonsToSignals() {

    connect(CharacterAge, &QPushButton::clicked, [=] {
        emit traitSent(CharacterAge->text() + "," + QString::number(character_number) + " ");
        CharacterAge->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterAge);
       // CharacterAge->setStyleSheet("background-color: #a6e3a1; color: #11111b");
       // This sets the button as invisible: CharacterAge->setFlat(true);
    });
    connect(CharacterSex, &QPushButton::clicked, [=] {
        emit traitSent(CharacterSex->text() + "," + QString::number(character_number) + " ");
        CharacterSex->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterSex);
    });
    connect(CharacterHealth, &QPushButton::clicked, [=] {
        emit traitSent(CharacterHealth->text() + "," + QString::number(character_number) + " ");
        CharacterHealth->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterHealth);
    });
    connect(CharacterFear, &QPushButton::clicked, [=] {
        emit traitSent(CharacterFear->text() + "," + QString::number(character_number) + " ");
        CharacterFear->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterFear);
    });
    connect(CharacterPersonalTraits, &QPushButton::clicked, [=] {
        emit traitSent(CharacterPersonalTraits->text() + "," + QString::number(character_number) + " ");
        CharacterPersonalTraits->setEnabled(false);
        replaceButtonWithLabel(CharacterPersonalTraits);
    });
    connect(CharacterAdditionalInfo, &QPushButton::clicked, [=] {
        emit traitSent(CharacterAdditionalInfo->text() + "," + QString::number(character_number) + " ");
        CharacterAdditionalInfo->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterPersonalTraits);
    });
    connect(CharacterPackage, &QPushButton::clicked, [=] {
        emit traitSent(CharacterPackage->text() + "," + QString::number(character_number) + " ");
        CharacterPackage->setEnabled(false);
        this->setEnabled(false);
        replaceButtonWithLabel(CharacterPackage);
    });

    connect(VoteForCharacter, &QPushButton::clicked, [=] {
        emit voteMade(getCharacterNumber());
    });
}


QPushButton *CharactersWindows::getCharacterAgeButton() {
    return CharacterAge;
}

QPushButton *CharactersWindows::getCharacterSexPushButton() {
    return CharacterSex;
}

QPushButton *CharactersWindows::getCharacterHealthPushButton() {
    return CharacterHealth;
}

QPushButton *CharactersWindows::getCharacterFearPushButton() {
    return CharacterFear;
}

QPushButton *CharactersWindows::getCharacterPersonalTraitsPushButton() {
    return CharacterPersonalTraits;
}

QPushButton *CharactersWindows::getCharacterAdditionalInfoPushButton() {
    return CharacterAdditionalInfo;
}

QPushButton *CharactersWindows::getCharacterPackagePushButton() {
    return CharacterPackage;
}

int CharactersWindows::getCharacterNumber() const {
    return character_number;
}

void CharactersWindows::setTurn(bool is_true) {
  is_true = is_true;
}

QPushButton *CharactersWindows::getVoteForCharacter() {
    return VoteForCharacter;
}

QLabel *CharactersWindows::getNumberOfVotesLabel() {
    return NumberOfVotes;
}

void CharactersWindows::replaceButtonWithLabel(QPushButton *button) {
    auto* StatsLabel = new QLabel;
    StatsLabel->setFrameStyle(QFrame::Panel);
    StatsLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    StatsLabel->setMinimumSize(100, 20);
    StatsLabel->setAlignment(Qt::AlignHCenter);
    StatsLabel->setText(button->text());
    CharacterWidgetLayout->replaceWidget(button,StatsLabel);
    button->setText("");
    button->setVisible(false);
}

