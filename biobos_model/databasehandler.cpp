#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
    : fileName("cinema.sqlite")
{
}

/*Open a connection to the database.
 * Returns true if it opened succesfully otherwise false.*/
bool DatabaseHandler::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);
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
    query.exec("CREATE TABLE IF NOT EXISTS hall("
               "HallID INTEGER PRIMARY KEY, "
               "Name TEXT, "
               "SoundSystem TEXT, "
               "ScreenSize TEXT)");

    //create movie table
    query.exec("CREATE TABLE IF NOT EXISTS movie("
               "MovieID INTEGER PRIMARY KEY, "
               "Title TEXT, "
               "Playtime TEXT, "
               "AgeLimit INTEGER, "
               "Description TEXT, "
               "Genre TEXT, "
               "Year INTEGER, "
               "MoviePoster TEXT)");

    //create seat table
    query.exec("CREATE TABLE IF NOT EXISTS seat("
               "SeatID INTEGER PRIMARY KEY, "
               "Row INTEGER, "
               "Column INTEGER, "
               "SeatNr INTEGER, "
               "HallID INTEGER)");

    //create show table
    query.exec("CREATE TABLE IF NOT EXISTS show("
               "ShowID INTEGER PRIMARY KEY, "
               "DateTime TEXT, "
               "Price REAL, "
               "ThreeD INTEGER, "
               "Subtitles INTEGER, "
               "Language TEXT, "
               "MovieID INTEGER, "
               "HallID TEXT)");

    //create booking table
    query.exec("CREATE TABLE IF NOT EXISTS booking("
               "BookingID INTEGER PRIMARY KEY, "
               "ShowID INTEGER, "
               "SeatID INTEGER, "
               "VisitorID INTEGER)");

    //create visitor table
    query.exec("CREATE TABLE IF NOT EXISTS visitor("
               "VisitorID INTEGER PRIMARY KEY, "
               "Phone TEXT)");

}


bool DatabaseHandler::transaction()
{
    return db.transaction();
}

bool DatabaseHandler::endTransaction(bool ok)
{
    if(ok)
    {
        return db.commit();
    }
    else
    {
        db.rollback();
        return false;
    }
}

bool DatabaseHandler::remove(const QString &tableName, const QString &column, const QVariant &value)
{
    QSqlQuery query;
    query.prepare(QString("DELETE FROM %1 WHERE %2 = :val").arg(tableName, column));
    query.bindValue(":val", value);
    if(!query.exec())
    {
        qDebug() << "The database reported an error: "
                 << db.lastError().text();
        return false;
    }
    return true;
}

int DatabaseHandler::insert(const QString &tableName, const QSqlRecord &record)
{
    QSqlQuery query;
    QString sqlStr = QString("INSERT INTO %1(").arg(tableName);
    QString valStr;
    QString fieldName;
    for(int i = 0; i < record.count(); i++)
    {
        fieldName = record.fieldName(i);
        sqlStr += fieldName + QString(", ");
        valStr += "?, ";
    }
    sqlStr.remove(sqlStr.size()-2, 2);
    valStr.remove(valStr.size()-2, 2);
    sqlStr += QString(") VALUES(") + valStr + ')';
    query.prepare(sqlStr);
    for(int i = 0; i < record.count(); i++)
    {
        query.bindValue(i, record.value(i));
    }
    qDebug() << sqlStr;
    if(!query.exec())
    {
        qDebug() << "The database reported an error: "
                 << db.lastError().text();
        return -1;
    }
    return query.lastInsertId().toInt();
}
