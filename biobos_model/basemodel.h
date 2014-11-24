#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDateTime>
#include <databasehandler.h>
#include <QDebug>

class BaseModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    BaseModel(const QString &tableName, QObject *parent = 0);
    BaseModel(const QString &tableName, const QString &displayQuery = QString(), QObject *parent = 0);

    //reimplemented public functions
    virtual QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const;
    virtual void refresh();
    //virtual void sort(int column, Qt::SortOrder order);

    //public functions
    bool deleteWhere(const QString &column, const QVariant &value);
    void setFilter(const QString &filter);
    void clearFilter();

protected:
    //variables
    DatabaseHandler dh;

private:
    //variables
    QString tableName; //deleteWhere() use this to delete from a table
    QString sqlStatement; //current sql statement
    QString currentFilter; //same as the "where clause" in a statement
    QString lastFilterQuery;
    bool filterFlag;

    //functions
    void prepareQuery(const QString &sql, QSqlQuery &query);
    void filterQuery(QSqlQuery &query, const QString &sqlStr, const QString &filter);
    void getLastExecutedQuery(QSqlQuery &query);
    void removeFilter(QString &sqlStr);
};

#endif // BASEMODEL_H
