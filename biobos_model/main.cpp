#include "mainwindow.h"
#include <QApplication>
#include "DatabaseHandler/databasehandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseHandler dh;
    dh.openDatabase();
    if(!dh.databaseComplete())
        dh.createDatabase();

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
