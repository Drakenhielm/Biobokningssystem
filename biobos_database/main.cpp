#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <QSqlError>

#include <databasehandler.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DatabaseHandler databaseHandler("cinema.sqlite");
    std::cout << databaseHandler.openDatabase() << std::endl;

    std::cout << QSqlError().text().toStdString() << std::endl;
    return a.exec();
}
