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
    void setFilter(QString filter);

protected:
    //variables
    DatabaseHandler dh;

private:
    //variables
    QString tableName; //deleteWhere() use this to delete from a table
    QString sqlStatement; //current sql statement
    QString filter; //same as the "where clause" in a statement

    //functions
    QList<QString> fixPlaceholders(QString &str);
    void filterQuery(QSqlQuery &query, const QString &sqlStatement, const QString &filter);
};

#endif // BASEMODEL_H
