#include "CharactersWindows.h"

CharactersWindows::CharactersWindows(Character &GivenCharacter, int number) {
    PlayerCharacter = &GivenCharacter;
    character_number = number;

    auto *ScreenLayout = new QGridLayout();
    ScreenLayout->addWidget(CreateCharacterWidget());
    this->setLayout(ScreenLayout);
    this->setFrameStyle(2);
    this->setMaximumSize(800, 800);
    this->disableTraitsButtons();
    this->show();
    connectButtonsToSignals();
}
QWidget *CharactersWindows::CreateCharacterWidget() {
    auto *CharacterWidget = new QWidget;

    NumberInGame->setFrameStyle(QFrame::Panel);
    NumberInGame->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    NumberInGame->setMinimumSize(100, 20);
    NumberInGame->setAlignment(Qt::AlignHCenter);
    NumberInGame->setText("Player number: " + QString::number(character_number));
    NumberOfVotes->setFrameStyle(QFrame::Panel);
    NumberOfVotes->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    NumberOfVotes->setMinimumSize(100, 20);
    NumberOfVotes->setAlignment(Qt::AlignHCenter);
    NumberOfVotes->setText("Number of votes: " + QString::number(number_of_votes));
    CharacterAge->setFlat(false);
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
    CharacterWidget->setMaximumSize(800, 800);

    return CharacterWidget;
}

void CharactersWindows::connectButtonsToSignals() {

    connect(CharacterAge, &QPushButton::clicked, [=] {
        emit traitSent(CharacterAge->text() + "," + QString::number(character_number) + " ");
        CharacterAge->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterAge);
    });
    connect(CharacterSex, &QPushButton::clicked, [=] {
        emit traitSent(CharacterSex->text() + "," + QString::number(character_number) + " ");
        CharacterSex->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterSex);
    });
    connect(CharacterHealth, &QPushButton::clicked, [=] {
        emit traitSent(CharacterHealth->text() + "," + QString::number(character_number) + " ");
        CharacterHealth->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterHealth);
    });
    connect(CharacterFear, &QPushButton::clicked, [=] {
        emit traitSent(CharacterFear->text() + "," + QString::number(character_number) + " ");
        CharacterFear->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterFear);
    });
    connect(CharacterPersonalTraits, &QPushButton::clicked, [=] {
        emit traitSent(CharacterPersonalTraits->text() + "," + QString::number(character_number) + " ");
        CharacterPersonalTraits->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterPersonalTraits);
    });
    connect(CharacterAdditionalInfo, &QPushButton::clicked, [=] {
        emit traitSent(CharacterAdditionalInfo->text() + "," + QString::number(character_number) + " ");
        CharacterAdditionalInfo->setEnabled(false);
        this->disableTraitsButtons();
        replaceButtonWithLabel(CharacterPersonalTraits);
    });
    connect(CharacterPackage, &QPushButton::clicked, [=] {
        emit traitSent(CharacterPackage->text() + "," + QString::number(character_number) + " ");
        CharacterPackage->setEnabled(false);
        this->disableTraitsButtons();
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

void
CharactersWindows::addPlayerChangeButtonToWindow(QPushButton *NextPlayerButton) {
    CharacterWidgetLayout->addWidget(NextPlayerButton);
    connect(NextPlayerButton, &QPushButton::pressed, this, &CharactersWindows::changeToNextPlayer);
}

void CharactersWindows::disableTraitsButtons() {
    CharacterAge->setEnabled(false);
    CharacterSex->setEnabled(false);
    CharacterHealth->setEnabled(false);
    CharacterFear->setEnabled(false);
    CharacterPersonalTraits->setEnabled(false);
    CharacterAdditionalInfo->setEnabled(false);
    CharacterPackage->setEnabled(false);
}

void CharactersWindows::enableTraitsButtons() {
    CharacterAge->setEnabled(true);
    CharacterSex->setEnabled(true);
    CharacterHealth->setEnabled(true);
    CharacterFear->setEnabled(true);
    CharacterPersonalTraits->setEnabled(true);
    CharacterAdditionalInfo->setEnabled(true);
    CharacterPackage->setEnabled(true);
}

QLabel *CharactersWindows::getCharacterNumberLabel() {
    return NumberInGame;
}

