#include <QApplication>
#include <QPushButton>
#include <QtNetwork/QTcpServer>
#include <QMainWindow>
#include <QObject>
#include "StartupScreen/MainWindow.h"
#include <QTcpSocket>
#include <QUdpSocket>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow *Main = new MainWindow();
    return QApplication::exec();
}
