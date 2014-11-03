#include <QCoreApplication>
#include <iostream>
#include <iomanip>

#include <databasehandler.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DatabaseHandler databaseHandler;
    if(!databaseHandler.databaseExist())
        databaseHandler.createDatabase();
    std::cout << databaseHandler.openDatabase() << std::endl;
    return a.exec();
}
