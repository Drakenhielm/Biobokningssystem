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

    //reimplemented public functions
    virtual QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const;
    virtual bool removeRows(int row, int count, const QModelIndex &parent);
    //virtual void sort(int column, Qt::SortOrder order);

    //public functions
    void refresh();
    bool removeWhere(const QString &column, const QVariant &value);
    void setFilter(const QString &filter);
    void clearFilter();

protected:
    //variables
    DatabaseHandler dh;

private:
    //variables
    QString tableName; //deleteWhere() use this to delete from a table
    QString lastFilterQuery; //last sql statement selected by setFilter() or clearFilter()

    //functions
    void prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList);
    void removeFilter(QString &sqlStr);
    QList<QVariant> getBoundValues(const QSqlQuery &query) const;
};

#endif // BASEMODEL_H
