#include "databasehandler.h"

DatabaseHandler::DatabaseHandler(const QString &fileName)
    : fileName{fileName}
{
}

/*Open a connection to the database.
 * Returns true if it opened succesfully otherwise false.*/
bool DatabaseHandler::openDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(this->fileName);
    return db.open();
}

/*Check if the sqlite-file and all tables exists.*/
bool DatabaseHandler::databaseComplete()
{
    QStringList list = QSqlDatabase::database().tables();
    return list.contains("hall")
            && list.contains("movie")
            && list.contains("seat")
            && list.contains("show")
            && list.contains("booking")
            && list.contains("visitor");
}

/*Create all missing tables in the database.*/
void DatabaseHandler::createDatabase()
{
    QSqlQuery query;

    //create hall table
    query.exec(QString("CREATE TABLE IF NOT EXISTS hall(")
               +QString("HallID INTEGER PRIMARY KEY, ")
               +QString("Name TEXT, ")
               +QString("SoundSystem TEXT, ")
               +QString("ScreenSize TEXT)"));

    //create movie table
    query.exec(QString("CREATE TABLE IF NOT EXISTS movie(")
               +QString("MovieID INTEGER PRIMARY KEY, ")
               +QString("Title TEXT, ")
               +QString("Playtime TEXT, ")
               +QString("AgeLimit INTEGER, ")
               +QString("Description TEXT, ")
               +QString("Genre TEXT, ")
               +QString("Year INTEGER, ")
               +QString("MoviePoster TEXT)"));

    //create seat table
    query.exec(QString("CREATE TABLE IF NOT EXISTS seat(")
               +QString("SeatID INTEGER PRIMARY KEY, ")
               +QString("Row INTEGER, ")
               +QString("Column INTEGER, ")
               +QString("SeatNr INTEGER, ")
               +QString("HallID INTEGER)"));

    //create show table
    query.exec(QString("CREATE TABLE IF NOT EXISTS show(")
               +QString("ShowID INTEGER PRIMARY KEY, ")
               +QString("DateTime TEXT, ")
               +QString("Price REAL, ")
               +QString("ThreeD INTEGER, ")
               +QString("Subtitles INTEGER, ")
               +QString("Language TEXT, ")
               +QString("MovieID INTEGER, ")
               +QString("HallID TEXT)"));

    //create booking table
    query.exec(QString("CREATE TABLE IF NOT EXISTS booking(")
               +QString("BookingID INTEGER PRIMARY KEY, ")
               +QString("ShowID INTEGER, ")
               +QString("SeatID INTEGER, ")
               +QString("VisitorID INTEGER)"));

    //create visitor table
    query.exec(QString("CREATE TABLE IF NOT EXISTS visitor(")
               +QString("VisitorID INTEGER PRIMARY KEY, ")
               +QString("Phone TEXT)"));

}
