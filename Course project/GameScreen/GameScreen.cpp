#include "GameScreen.h"

GameScreen::GameScreen() {
    this->setMaximumSize(800, 800);
}

void GameScreen::addCharacterToWindow(Character PlayerCharacter, int character_number) {
    CharactersFrames.append(new CharactersWindows(PlayerCharacter, character_number));
    this->addWidget(CharactersFrames.last());
    auto *NextScreen = new QPushButton;
    NextScreen->setText("Next");
    CharactersFrames.last()->addPlayerChangeButtonToWindow(NextScreen);
    if (CharactersFrames.size() == 1) {
       CharactersFrames[0]->getCharacterNumberLabel()->setStyleSheet("color: #a6e3a1;");
        this->setCurrentIndex(this->count() - 1);
    }
    connect(CharactersFrames[CharactersFrames.size() - 1], &CharactersWindows::voteMade, this,
            &GameScreen::sendVoteMade);
    connect(CharactersFrames[CharactersFrames.size() - 1], &CharactersWindows::changeToNextPlayer, this,
            &GameScreen::turnToNextScreen);
    connect(CharactersFrames[0], &CharactersWindows::traitSent, this, &GameScreen::sendTrait);
    connect(CharactersFrames[0], &CharactersWindows::turnMade, this, &GameScreen::turnMade);
}

void GameScreen::changeTrait(const QString& traitAndNumber) {
    QString kind_of_trait = traitAndNumber.split(':')[0];
    int number = traitAndNumber.split(",")[1].split(" ")[0].toInt();
    QString trait = traitAndNumber.split(",")[0];

    if (number != CharactersFrames[0]->getCharacterNumber()) {
        int required_number;

        if (number < CharactersFrames[0]->getCharacterNumber()) {
            required_number = number;
        } else {
          required_number = number - 1;
        }

        if (kind_of_trait == "Age") {
            CharactersFrames[required_number]->getCharacterAgeButton()->setText(trait);
        }
        if (kind_of_trait == "Health") {
            CharactersFrames[required_number]->getCharacterHealthPushButton()->setText(trait);
        }
        if (kind_of_trait == "Sex") {
            CharactersFrames[required_number]->getCharacterSexPushButton()->setText(trait);
        }
        if (kind_of_trait == "Fear") {
            CharactersFrames[required_number]->getCharacterFearPushButton()->setText(trait);
        }
        if (kind_of_trait == "Package") {
            CharactersFrames[required_number]->getCharacterPackagePushButton()->setText(trait);
        }
        if (kind_of_trait == "Additional info") {
            CharactersFrames[required_number]->getCharacterAdditionalInfoPushButton()->setText(trait);
        }
        if (kind_of_trait == "Personal traits") {
            CharactersFrames[required_number]->getCharacterPersonalTraitsPushButton()->setText(trait);
        }
    }
}

void GameScreen::sendTrait(QString trait) {
    count_of_unopened_traits--;
    emit traitSent(std::move(trait));
}

void GameScreen::setTurn() {
    CharactersFrames[0]->setTurn(true);
    CharactersFrames[0]->setEnabled(true);
    CharactersFrames[0]->getCharacterAgeButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterPersonalTraitsPushButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterAdditionalInfoPushButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterPackagePushButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterFearPushButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterHealthPushButton()->setEnabled(true);
    CharactersFrames[0]->getCharacterSexPushButton()->setEnabled(true);
}

void GameScreen::enableVoteButton() {
    for (auto & CharactersFrame : CharactersFrames) {
        TimeToVote->setSingleShot(true);
        TimeToVote->start(7400);
        connect(TimeToVote, &QTimer::timeout,[=] {
            for (auto & CharactersFrame : CharactersFrames) {
                CharactersFrame->getVoteForCharacter()->setVisible(false);
            }
        });
        CharactersFrame->setEnabled(true);
        CharactersFrame->getVoteForCharacter()->setVisible(true);
        CharactersFrame->getCharacterAgeButton()->setEnabled(false);
        CharactersFrame->getCharacterPersonalTraitsPushButton()->setEnabled(false);
        CharactersFrame->getCharacterAdditionalInfoPushButton()->setEnabled(false);
        CharactersFrame->getCharacterPackagePushButton()->setEnabled(false);
        CharactersFrame->getCharacterFearPushButton()->setEnabled(false);
        CharactersFrame->getCharacterHealthPushButton()->setEnabled(false);
        CharactersFrame->getCharacterSexPushButton()->setEnabled(false);
    }
}

void GameScreen::sendVoteMade(int voted_character) {
    emit voteMade(voted_character);
    for (auto & CharactersFrame : CharactersFrames) {
        CharactersFrame->getVoteForCharacter()->setVisible(false);
    }
}

void GameScreen::changeVotes(int voted_character) {
    int current_count_of_votes = CharactersFrames[voted_character - 1]->getNumberOfVotesLabel()->text().split(" ")[3].toInt();
    current_count_of_votes++;
    current_count_of_votes %= (CharactersFrames.size() * 4 - 1);
    CharactersFrames[voted_character - 1]->getNumberOfVotesLabel()->setText("Number of votes: " + QString::number(current_count_of_votes));
}

void GameScreen::turnToNextScreen() {
    if (this->currentIndex() != this->count() - 1) {
        this->setCurrentIndex(this->currentIndex() + 1);
    } else {
        this->setCurrentIndex(0);
    }
}

