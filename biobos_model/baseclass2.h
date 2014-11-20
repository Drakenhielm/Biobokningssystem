#ifndef BaseModel2_H
#define BaseModel2_H

#include <QSqlQueryModel>
#include <QSqlError>

#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>

#include <databasehandler.h>


class BaseModel2 : public QSqlQueryModel
{
    Q_OBJECT
public:
    BaseModel2(const QString &query, QObject *parent = 0);

    //reimplemented functions
    bool insertRow(int row, const QModelIndex & parent = QModelIndex());
    virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
    //bool removeRow(int row, const QModelIndex & parent = QModelIndex());
    //virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());
    bool deleteWhere(const QString &column, const QVariant &value);
    //void setFilter(const QString & filter);
    //void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
signals:

public slots:

protected:
    //variables
    DatabaseHandler dh;
    //functions

    //hide derived function - (maybe not good looking)
    void setQuery(const QString & query);

private:
    //variables
    QSqlQuery sqlQuery;
    //functions


};

#endif // BaseModel2_H
