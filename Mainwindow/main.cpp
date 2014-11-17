#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::string movie;
    // movie is used to test textbrowser (HTML) module.

    return a.exec();
}
