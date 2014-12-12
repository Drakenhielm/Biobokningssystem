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
    virtual bool removeRows(int row, int count, const QModelIndex &parent);

    //public functions
    virtual void refresh();
    void setFilter(const QString &filter, QVariant placeholder);
    void setFilter(const QString &filter, const QList<QVariant> &placeholderList  = QList<QVariant>());
    void clearFilter();
    int getRowByPrimaryKeyValue(const QVariant &pkValue) const;

protected:
    //variables
    DatabaseHandler dh;
    QString tableName;
    QString primaryKey; //name of the primarykey column in the table

    //functions
    virtual bool remove(const QVariant &pkValue);
    QString dateTimeString(QDateTime dateTime) const;

private:
    //variables
    QString lastFilterQuery; //last sql statement executed from setFilter() or clearFilter()
};

#endif // BASEMODEL_H
