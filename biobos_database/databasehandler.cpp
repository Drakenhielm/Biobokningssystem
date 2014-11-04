#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(const QString &fileName)
    : fileName{fileName}
{
}

bool DatabaseHandler::databaseExist()
{
    QFileInfo fileInfo(fileName);
    return fileInfo.exists();
}

bool DatabaseHandler::openDatabase()
{
    bool exist = databaseExist();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(this->fileName);
    if(!db.open())
        return false;
    if(!exist)
        createDatabase();
    return true;
}

void DatabaseHandler::createDatabase()
{
    QSqlQuery query;

    //create hall table
    query.exec(QString("CREATE TABLE hall(")
               +QString("HallID INTEGER PRIMARY KEY, ")
               +QString("Name TEXT, ")
               +QString("SoundSystem TEXT, ")
               +QString("ScreenSize TEXT)"));

    //create movie table
    query.exec(QString("CREATE TABLE movie(")
               +QString("MovieID INTEGER PRIMARY KEY, ")
               +QString("Title TEXT, ")
               +QString("Playtime TEXT, ")
               +QString("AgeLimit INTEGER, ")
               +QString("Description, TEXT, ")
               +QString("Genre TEXT, ")
               +QString("Year INTEGER, ")
               +QString("MoviePoster TEXT)"));

    //create seat table
    query.exec(QString("CREATE TABLE seat(")
               +QString("SeatID INTEGER PRIMARY KEY, ")
               +QString("Row INTEGER, ")
               +QString("Column INTEGER, ")
               +QString("SeatNr INTEGER, ")
               +QString("HallID, INTEGER)"));

    //create movie table
    query.exec(QString("CREATE TABLE movie(")
               +QString("MovieID INTEGER PRIMARY KEY, ")
               +QString("Title TEXT, ")
               +QString("Playtime TEXT, ")
               +QString("AgeLimit INTEGER, ")
               +QString("Description, TEXT, ")
               +QString("Genre TEXT, ")
               +QString("Year INTEGER, ")
               +QString("MoviePoster TEXT, "));

    //create booking table
    query.exec(QString("CREATE TABLE booking(")
               +QString("BookingID INTEGER PRIMARY KEY, ")
               +QString("ShowID INTEGER, ")
               +QString("SeatID INTEGER, ")
               +QString("VisitorID INTEGER)"));

    //create visitor table
    query.exec(QString("CREATE TABLE visitor(")
               +QString("VisitorID INTEGER PRIMARY KEY, ")
               +QString("Phone TEXT)"));

}
