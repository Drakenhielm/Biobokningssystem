#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDriver>
#include <QSqlError>
#include <iterator>

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

    bool remove(const QString &tableName, const QString &where, const QVariant &placeholder);
    bool remove(const QString &tableName, const QString &where, const QList<QVariant> &parameterList = QList<QVariant>());

    int  insert(const QString &tableName, const QMap<QString, QVariant> &values);

    bool edit(const QString &tableName, const QMap<QString, QVariant> &values,
              const QString &where, const QVariant &wherePlaceholder);
    bool edit(const QString &tableName, const QMap<QString, QVariant> &values,
              const QString &where, const QList<QVariant> &wherePlaceholders = QList<QVariant>());

    void addFilter(QSqlQuery &query, const QString &filter, const QVariant &filterPlaceholder);
    void addFilter(QSqlQuery &query, const QString &filter, const QList<QVariant> &filterPlaceholders = QList<QVariant>());

    void removeLastFilter(QSqlQuery &query);

private:
    //variables
    const QString fileName;
    QSqlDatabase db;

    //functions
    void prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &placeholderList);
    QList<QVariant> getBoundValues(const QSqlQuery &query) const;
    int numOfPlaceholders(const QString &sqlStr) const;
};

#endif // DATABASEHANDLER_H

