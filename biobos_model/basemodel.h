#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>

#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDateTime>

#include <databasehandler.h>


class BaseModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    BaseModel(const QString &tableName, QObject *parent = 0);
    BaseModel(const QString & tableName, const QString & query = QString(), QObject *parent = 0);

    //reimplemented functions
    virtual QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const;
    //bool submitAll(bool insideTransaction = true);
    virtual void refresh();
    bool deleteWhere(const QString &column, const QVariant &value);

signals:

public slots:

protected:
    //variables
    DatabaseHandler dh;
    QString tableName;
    QString filter;

private:
    void initBaseModel(const QString & tableName, const QString & query = QString());

    //hide derived functions
    //void setTable(const QString &tableName);

};

#endif // BASEMODEL_H
