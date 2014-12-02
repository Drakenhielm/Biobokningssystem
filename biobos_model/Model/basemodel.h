#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDateTime>
#include "../DatabaseHandler/databasehandler.h"
#include <QDebug>

class BaseModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    BaseModel(const QString &tableName, const QString &primaryKey, QObject *parent = 0);

    //reimplemented public functions
    virtual QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const;
    virtual bool removeRows(int row, int count, const QModelIndex &parent);
    //virtual void sort(int column, Qt::SortOrder order);

    //public functions
    virtual void refresh();
    //virtual bool removeWhere(const QString &column, const QVariant &value);
    void setFilter(const QString &filter, QVariant placeholder);
    void setFilter(const QString &filter, const QList<QVariant> &placeholderList  = QList<QVariant>());
    void clearFilter();

protected:
    //variables
    DatabaseHandler dh;
    QString tableName;
    QString primaryKey; //name of the primarykey column in the table

    //functions
    virtual bool remove(const QVariant &pkValue);

private:
    //variables
    QString lastFilterQuery; //last sql statement executed by setFilter() or clearFilter()

    //functions
    void prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList);
    void removeFilter(QString &sqlStr);
    QList<QVariant> getBoundValues(const QSqlQuery &query) const;
    int numOfPlaceholders(const QString &sqlStr) const;
};

#endif // BASEMODEL_H
