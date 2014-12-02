#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDriver>
#include <QSqlError>

//temp for debugging
#include <QDebug>

class DatabaseHandler
{
public:
    DatabaseHandler();

    typedef QList<QPair<QString, QVariant> > DatabaseRecord;

    //functions
    bool openDatabase();
    bool databaseComplete();
    void createDatabase();

    const QSqlDatabase getDatabase() { return db; }

    bool transaction();
    bool endTransaction(bool ok);

    bool remove(const QString &tableName, const QString &column, const QVariant &value);
    int  insert(const QString &tableName, const QList<QPair<QString, QVariant> > &record);
    bool edit(const QString &tableName, const QList<QPair<QString, QVariant> > &record,
              const QString &whereColumn, const QString &whereValue);

private:
    //variables
    const QString fileName;
    QSqlDatabase db;
    //functions
};

#endif // DATABASEHANDLER_H

