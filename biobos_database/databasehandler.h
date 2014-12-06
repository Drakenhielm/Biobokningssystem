#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDriver>
#include <QSqlError>
#include <iterator>

#include "sqlhandler.h"

//temp for debugging
#include <QDebug>

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

    //old
    //bool remove(const QString &tableName, const QString &column, const QVariant &value);
    //int  insert(const QString &tableName, const QList<QPair<QString, QVariant> > &record);
    //bool edit(const QString &tableName, const QList<QPair<QString, QVariant> > &record,
    //          const QString &whereColumn, const QVariant &whereValue);

    bool remove(const QString &tableName, const QString &where, const QVariant &parameter);
    bool remove(const QString &tableName, const QString &where, const QList<QVariant> &parameterList = QList<QVariant>());

    int  insert(const QString &tableName, const QMap<QString, QVariant> &values);

    bool edit(const QString &tableName, const QMap<QString, QVariant> &values,
              const QString &where, const QVariant &whereParameter);
    bool edit(const QString &tableName, const QMap<QString, QVariant> &values,
              const QString &where, const QList<QVariant> &whereParameters = QList<QVariant>());

private:
    //variables
    const QString fileName;
    QSqlDatabase db;
    SqlHandler sh;

    //functions
    void prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList);
    QList<QVariant> getBoundValues(const QSqlQuery &query) const;
    int numOfPlaceholders(const QString &sqlStr) const;
};

#endif // DATABASEHANDLER_H

