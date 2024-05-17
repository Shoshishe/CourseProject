#include <QApplication>
#include "QFile"
#include <QObject>
#include "MainWindow/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *Main = new MainWindow();
    Main->setMaximumSize(800, 800);
    QFile stylesFile("../Styles/styles.qss");
    stylesFile.open(QIODevice::ReadOnly);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
    return QApplication::exec();
}
