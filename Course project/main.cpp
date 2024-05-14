#include <QApplication>
#include <QObject>
#include "StartupScreen/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *Main = new MainWindow();
    return QApplication::exec();
}
