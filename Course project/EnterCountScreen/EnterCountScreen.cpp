#include "EnterCountScreen.h"

EnterCountScreen::EnterCountScreen() {
    this->setLayout(ScreenLayout);
    EnterNameLabel->setText("Enter the count of players needed");
    ConfirmEntering->setText("Enter");
    ScreenLayout->addWidget(EnterNameLabel, 0, 3, 1, 1, Qt::AlignHCenter);
    ScreenLayout->addWidget(CountOfPlayers, 1, 0, 1, 7);
    ScreenLayout->addWidget(ConfirmEntering, 1, 8, 1, 1);
    auto *spacer = new QWidget;
    spacer->setFixedSize(100, 250);
    ScreenLayout->addWidget(spacer);

    CountOfPlayers->setRange(4, 12);
    connect(ConfirmEntering, &QPushButton::pressed, this, &EnterCountScreen::sendCountSet);
}

void EnterCountScreen::sendCountSet() {
    emit countSet(CountOfPlayers->value());
}
