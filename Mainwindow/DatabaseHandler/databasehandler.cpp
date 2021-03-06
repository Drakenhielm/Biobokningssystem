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
    QSqlQuery query(db);

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

//Starts a database transaction
bool DatabaseHandler::transaction()
{
    return db.transaction();
}

//End a database transaction.
bool DatabaseHandler::endTransaction(bool ok)
{
    if(ok == true)
    {
        //commit all changes to the database
        return db.commit();
    }
    else
    {
        //remove all changes to the database since the transaction started
        return db.rollback();
    }
}

/*Remove rows from a database table*/
bool DatabaseHandler::remove(const QString &tableName, const QString &where, const QVariant &placeholder)
{
    QList<QVariant> list;
    list.append(placeholder);

    return remove(tableName, where, list);
}

/*Remove rows from a database table*/
bool DatabaseHandler::remove(const QString &tableName, const QString &where, const QList<QVariant> &parameterList)
{
    QSqlQuery query(db);

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

/*Insert a new row into a table in the database.
 * tableName represent the name of the table and
 * the QMap has the values to insert where the key is the name of the column
 * and the value is the value to insert. */
int DatabaseHandler::insert(const QString &tableName, const QMap<QString, QVariant> &values)
{
    QSqlQuery query(db);
    QString sqlStr = QString("INSERT INTO %1(").arg(tableName);
    QString valStr;
    QString fieldName;
    QList<QVariant> parameterList;

    QMap<QString, QVariant>::const_iterator it = values.cbegin();
    for(; it != values.cend(); it++) //navigate through all pairs in the map
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
          const QString &where, const QVariant &wherePlaceholder)
{
    QList<QVariant> list;
    list.append(wherePlaceholder);
    return edit(tableName, values, where, list);
}

bool DatabaseHandler::edit(const QString &tableName, const QMap<QString, QVariant> &values,
          const QString &where, const QList<QVariant> &wherePlaceholders)
{
    QSqlQuery query(db);
    QString sqlStr = QString("UPDATE %1 SET ").arg(tableName);
    QList<QVariant> placeholderList;
    QMap<QString, QVariant>::const_iterator it = values.cbegin();
    for(; it != values.cend(); it++) //navigate through all pairs in the map
    {
        QString fieldName = it.key(); //name of the column
        sqlStr += fieldName + " = ?, ";
        placeholderList.append(it.value()); //inserted value
    }
    sqlStr.remove(sqlStr.size()-2, 2); //remove the last: ", "

    //where part
    sqlStr += QString(" WHERE ") + where;
    placeholderList.append(wherePlaceholders);

    //prepare
    prepareQuery(query, sqlStr, placeholderList);

    //execute query
    if(!query.exec())
    {
        qDebug() << "Could not edit. The database reported an error: "
                 << db.lastError().text();
        qDebug() << sqlStr;
        return false;
    }
    return true;
}

/*filter is the where part in a sql statement.
 * The output sql statement will be like this: "SELECT * FROM (original query) WHERE filter". */
void DatabaseHandler::addFilter(QSqlQuery &query, const QString &filter, const QList<QVariant> &filterPlaceholders)
{
    QString sql = query.lastQuery();

    //add filter
    sql.prepend("SELECT * FROM (");
    sql.append(") WHERE ");
    sql.append(filter);

    //get all placeholders and insert them in a QList
    QList<QVariant> placeholderList = getBoundValues(query);
    if(!filterPlaceholders.isEmpty())
        placeholderList.append(filterPlaceholders);

    //prepare query
    prepareQuery(query, sql, placeholderList);
}

void DatabaseHandler::addFilter(QSqlQuery &query, const QString &filter, const QVariant &filterPlaceholder)
{
    QList<QVariant> list;
    list.append(filterPlaceholder);
    addFilter(query, filter, list);
}

/*Remove the last filter that was added by addFilter. */
void DatabaseHandler::removeLastFilter(QSqlQuery &query)
{
    QString sql = query.lastQuery();

    int numBefore = numOfPlaceholders(sql);

    int p = QString("SELECT * FROM (").length();
    int n = sql.lastIndexOf(") WHERE ") - p;
    sql = sql.mid(p, n); //removes last filter from sql string

    int numAfter = numOfPlaceholders(sql);

    QList<QVariant> list = getBoundValues(query); //all placeholders from the last query
    list.erase(list.end()-(numBefore-numAfter), list.end()); //erase placeholders from the filter part

    prepareQuery(query, sql, list);
}

/*Prepare "query" with the statement from "sql" and bind parameters from "parameterList" */
void DatabaseHandler::prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &placeholderList)
{
    query.prepare(sql);
    for(int i = 0; i < placeholderList.size(); i++)
    {
        query.addBindValue(placeholderList.at(i));
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
