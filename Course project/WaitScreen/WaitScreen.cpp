#include "WaitScreen.h"

void WaitScreen::addNewHostEntry(const QString& host_address) {
    auto *ConnectionFrame = new QFrame;
    ConnectionFrame->setFrameStyle(1);
    auto *ConnectionWindow = new QWidget(ConnectionFrame);
    auto *ConnectionWindowLayout = new QGridLayout(ConnectionWindow);
    auto *IpAddressLabel = new QLabel(this);
    auto ip_address = host_address.split(" ")[0];
    IpAddressLabel->setText(host_address);
    auto *ConnectToTheGame = new QPushButton(this);
    ConnectToTheGame->setText("Enter the game of this host");
    ConnectionWindowLayout->addWidget(IpAddressLabel, 0, 0);
    ConnectionWindowLayout->addWidget(ConnectToTheGame, 1, 0);

    connect(ConnectToTheGame, &QPushButton::pressed, [=] {
        WaitingUser->connectToHost(ip_address);
        emit WaitingUser->connected();
    });
    if (ScreenLayout->rowCount() > 1) {
        ScreenLayout->removeItem(ScreenLayout->itemAtPosition(ScreenLayout->rowCount() - 1, 0));
    }
    ScreenLayout->addWidget(ConnectionFrame, ScreenLayout->rowCount(), 0);
}

WaitScreen::WaitScreen() {
    this->setLayout(ScreenLayout);
    ScreenLayout->addWidget(PlaceHolder, 0, 0);
}

void WaitScreen::setUserAsWaiting(Client *User) {
 WaitingUser = User;
}
