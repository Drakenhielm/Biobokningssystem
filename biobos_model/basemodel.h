#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>

#include <QDebug>
#include <QSqlRecord>
#include <QSqlQuery>

#include <databasehandler.h>


class BaseModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    BaseModel(const QString &tableName, QObject *parent = 0);
    BaseModel(const QString & tableName, const QString & query = QString(), QObject *parent = 0);

    //reimplemented functions
    bool submitAll(bool insideTransaction = true);
    bool insertRow(const QSqlRecord &record);
    bool insertRows(const QList<QMap<int, QVariant> > & values, bool submit = true);
    bool deleteWhere(const QString &column, const QVariant &value);

signals:

public slots:

protected:
    //variables
    DatabaseHandler dh;

private:
    void initBaseModel(const QString & tableName, const QString & query = QString());
    //hide derived functions
    void setTable(const QString &tableName);

};

#endif // BASEMODEL_H
