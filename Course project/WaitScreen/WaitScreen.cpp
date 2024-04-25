//
// Created by shosh on 4/24/24.
//

#include "WaitScreen.h"

WaitScreen::WaitScreen() {
 this->setLayout(ScreenLayout);
 ScreenLayout->addWidget(PlaceHolder, 0, 0);
}

void WaitScreen::AddNewHostEntry(const QString& ip_address) {
    QLabel *IpAddressLabel = new QLabel(this);
    QPushButton *connect_to_the_game = new QPushButton;
    IpAddressLabel->setText(ip_address);
    ScreenLayout->addWidget(IpAddressLabel, ScreenLayout->rowCount() + 1, 0);
}
