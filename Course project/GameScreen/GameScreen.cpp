#include "GameScreen.h"

GameScreen::GameScreen() {
    this->setLayout(ScreenLayout);
}

void GameScreen::addCharacterToWindow(Character PlayerCharacter) {
  CharactersFrames.append(new CharactersWindows(PlayerCharacter));
  ScreenLayout->addWidget(CharactersFrames.last(), ScreenLayout->rowCount() - 1, ScreenLayout->columnCount());
  if (CharactersFrames.size() == 1) {
      connect(CharactersFrames[0], &CharactersWindows::traitSent, this, &GameScreen::traitSent);
  }
}
