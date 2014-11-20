#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDriver>
#include <QSqlError>
#include <QFileInfo>

//temp for debugging
#include <QDebug>
#include <iostream>
#include <iomanip>

class DatabaseHandler
{
public:
    DatabaseHandler();

    //functions
    bool openDatabase();
    bool databaseComplete();
    void createDatabase();

    const QSqlDatabase getDatabase() { return db; }

    bool transaction();
    bool endTransaction(bool ok);

    bool remove(const QString &tableName, const QString &column, const QVariant &value);
    int  insert(const QString &tableName, const QSqlRecord &record);

private:
    //variables
    const QString fileName;
    QSqlDatabase db;
    //functions
};

#endif // DATABASEHANDLER_H

