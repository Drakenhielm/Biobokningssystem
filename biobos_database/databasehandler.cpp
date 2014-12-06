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

/*bool DatabaseHandler::remove(const QString &tableName, const QString &column, const QVariant &value)
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
}*/

bool DatabaseHandler::remove(const QString &tableName, const QString &where, const QVariant &parameter)
{
    QList<QVariant> list;
    list.append(parameter);
    return remove(tableName, where, list);
}

bool DatabaseHandler::remove(const QString &tableName, const QString &where, const QList<QVariant> &parameterList)
{
    QSqlQuery query;
    QString sql = QString("DELETE FROM %1 WHERE %2").arg(tableName).arg(where);
    prepareQuery(query, sql, parameterList);
    if(!query.exec())
    {
        qDebug() << "Could not remove. The database reported an error: "
                 << db.lastError().text();
        return false;
    }
    return true;
}

int DatabaseHandler::insert(const QString &tableName, const QMap<QString, QVariant> &values)
{
    QSqlQuery query;
    QString sqlStr = QString("INSERT INTO %1(").arg(tableName);
    QString valStr;
    QString fieldName;
    QList<QVariant> parameterList;

    QMap<QString, QVariant>::const_iterator it = values.cbegin();
    for(it; it != values.cend(); it++) //navigate through all pairs in the map
    {
        fieldName = it.key(); //name of the column
        sqlStr += fieldName + QString(", ");
        valStr += "?, ";
        parameterList.append(it.value()); //inserted value
    }
    sqlStr.remove(sqlStr.size()-2, 2); //remove the last: ", "
    valStr.remove(valStr.size()-2, 2); //remove the last: ", "
    sqlStr += QString(") VALUES(") + valStr + ')';

    //prepare query
    prepareQuery(query, sqlStr, parameterList);

    //execute query
    if(!query.exec())
    {
        qDebug() << "Could not insert. The database reported an error: "
                 << db.lastError().text();
        qDebug() << sqlStr;
        return -1;
    }

    return query.lastInsertId().toInt();
}

bool DatabaseHandler::edit(const QString &tableName, const QMap<QString, QVariant> &values,
          const QString &where, const QVariant &whereParameter)
{
    QList<QVariant> list;
    list.append(whereParameter);
    return edit(tableName, values, where, list);
}

bool DatabaseHandler::edit(const QString &tableName, const QMap<QString, QVariant> &values,
          const QString &where, const QList<QVariant> &whereParameters)
{
    QSqlQuery query;
    QString sqlStr = QString("UPDATE %1 SET ").arg(tableName);
    QList<QVariant> parameterList;
    QMap<QString, QVariant>::const_iterator it = values.cbegin();
    for(it; it != values.cend(); it++) //navigate through all pairs in the map
    {
        QString fieldName = it.key(); //name of the column
        sqlStr += fieldName + " = ?, ";
        parameterList.append(it.value()); //inserted value
    }
    sqlStr.remove(sqlStr.size()-2, 2); //remove the last: ", "

    //where part
    sqlStr += QString(" WHERE ") + where;
    parameterList.append(whereParameters);

    //prepare
    prepareQuery(query, sqlStr, parameterList);

    //execute query
    if(!query.exec())
    {
        qDebug() << "Could not edit. The database reported an error: "
                 << db.lastError().text();
        return false;
    }
    return true;
}

/*Prepare "query" with the statement from "sql" and bind parameters from "parameterList" */
void DatabaseHandler::prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList)
{
    query.prepare(sql);
    for(int i = 0; i < parameterList.size(); i++)
    {
        query.addBindValue(parameterList.at(i));
    }
}

/*Return the number of placeholders in a sql string
 * or in other words how many times ':' or '?' appears in the string. */
int DatabaseHandler::numOfPlaceholders(const QString &sqlStr) const
{
    int count = 0;
    int i = 0;
    bool b = true;
    while(b)
    {
        i = sqlStr.indexOf(QRegExp("[:?]"), ++i); //search for next position of : or ?
        if(i == -1) // no match
            b = false;
        else //match
            count++;
    }
    return count;
}

/*Returns the bound values from the query in a list*/
QList<QVariant> DatabaseHandler::getBoundValues(const QSqlQuery &query) const
{
    QList<QVariant> list;
    int i = 0;
    while(query.boundValue(i).isValid())
    {
        list.append(query.boundValue(i));
        i++;
    }
    return list;
}
