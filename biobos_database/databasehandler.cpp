#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{
}

bool DatabaseHandler::databaseExist()
{
    return false;
}

void DatabaseHandler::createDatabase()
{

}

bool DatabaseHandler::openDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cinema.db");
    return db.open();
}
