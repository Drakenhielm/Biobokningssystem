#include "mainwindow.h"
#include <QApplication>
#include <databasehandler.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*DatabaseHandler dh("movietest.sqlite");
    dh.openDatabase();
    if(!dh.databaseComplete())
        dh.createDatabase();*/

    MainWindow w;
    w.show();

    return a.exec();
}
