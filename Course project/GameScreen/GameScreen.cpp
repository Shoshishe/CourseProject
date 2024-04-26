#include "GameScreen.h"

GameScreen::GameScreen() {
 ScreenLayout->addWidget(PlaceHolder,0,0);
 this->setLayout(ScreenLayout);
}

void GameScreen::addCharacterToWindow(Character PlayerCharacter) {
  CharactersFrames.append(new CharactersWindows(PlayerCharacter));
  ScreenLayout->addWidget(CharactersFrames.last(), ScreenLayout->rowCount() - 1, ScreenLayout->columnCount());
}
