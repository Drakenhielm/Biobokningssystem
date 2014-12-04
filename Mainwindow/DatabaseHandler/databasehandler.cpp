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
            && list.contains("seatbooking");
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
               "SeatType INTEGER, "
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
               "HallID INTEGER)");

    //create booking table
    query.exec("CREATE TABLE IF NOT EXISTS booking("
               "BookingID INTEGER PRIMARY KEY, "
               "ShowID INTEGER, "
               "Phone TEXT)");

    //create seatbooking table
    query.exec("CREATE TABLE IF NOT EXISTS seatbooking("
               "SeatBookingID INTEGER PRIMARY KEY, "
               "BookingID INTEGER, "
               "SeatID INTEGER)");

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
        return db.rollback();
    }
}

bool DatabaseHandler::remove(const QString &tableName, const QString &column, const QVariant &value)
{
    QSqlQuery query;
    QString sql = QString("DELETE FROM %1 WHERE %2 = ?").arg(tableName).arg(column);
    query.prepare(sql);
    query.bindValue(0, value);
    if(!query.exec())
    {
        qDebug() << "Could not remove. The database reported an error: "
                 << db.lastError().text();
        return false;
    }
    return true;
}

int DatabaseHandler::insert(const QString &tableName, const QList<QPair<QString, QVariant> > &record)
{
    QSqlQuery query;
    QString sqlStr = QString("INSERT INTO %1(").arg(tableName);
    QString valStr;
    QString fieldName;
    for(int i = 0; i < record.size(); i++)
    {
        fieldName = record.at(i).first;
        sqlStr += fieldName + QString(", ");
        valStr += "?, ";
    }
    sqlStr.remove(sqlStr.size()-2, 2);
    valStr.remove(valStr.size()-2, 2);
    sqlStr += QString(") VALUES(") + valStr + ')';
    query.prepare(sqlStr);
    for(int i = 0; i < record.size(); i++)
    {
        query.bindValue(i, record.at(i).second);
    }
    if(!query.exec())
    {
        qDebug() << "Could not insert. The database reported an error: "
                 << db.lastError().text();
        qDebug() << sqlStr;
        return -1;
    }

    return query.lastInsertId().toInt();
}

bool DatabaseHandler::edit(const QString &tableName, const QList<QPair<QString, QVariant> > &record,
          const QString &whereColumn, const QVariant &whereValue)
{
    QSqlQuery query;
    QString sqlStr = QString("UPDATE %1 SET ").arg(tableName);
    for(int i = 0; i < record.size(); i++)
    {
        QString fieldName = record.at(i).first;
        sqlStr += fieldName + " = ?, ";
    }
    sqlStr.remove(sqlStr.size()-2, 2);
    sqlStr += QString(" WHERE ") + whereColumn + " = " + whereValue.toString();
    query.prepare(sqlStr);
    for(int i = 0; i < record.size(); i++)
    {
        query.bindValue(i, record.at(i).second);
    }
    if(!query.exec())
    {
        qDebug() << "Could not edit. The database reported an error: "
                 << db.lastError().text();
        return false;
    }
    return true;
}
