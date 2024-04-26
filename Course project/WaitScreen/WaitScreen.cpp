#include "WaitScreen.h"

void WaitScreen::AddNewHostEntry(const QString& ip_address) {
    QFrame *ConnectionFrame = new QFrame;
    ConnectionFrame->setFrameStyle(1);
    QWidget *ConnectionWindow = new QWidget(ConnectionFrame);
    QGridLayout *ConnectionWindowLayout = new QGridLayout(ConnectionWindow);
    QLabel *IpAddressLabel = new QLabel(this);
    IpAddressLabel->setText(ip_address);
    QPushButton *ConnectToTheGame = new QPushButton(this);
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
