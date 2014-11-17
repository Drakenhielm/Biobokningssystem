#include "basemodel.h"

BaseModel::BaseModel(const QString &tableName, QObject *parent)
    : QSqlRelationalTableModel(parent)
{
    initBaseModel(tableName, QString());
}

BaseModel::BaseModel(const QString &tableName, const QString &query, QObject *parent)
    : QSqlRelationalTableModel(parent)
{
    initBaseModel(tableName, query);
}

void BaseModel::initBaseModel(const QString & tableName, const QString & query)
{
    setTable(tableName);
    if(!query.isEmpty())
        QSqlQueryModel::setQuery(query);
    setEditStrategy(OnManualSubmit);
}

bool BaseModel::insertRow(const QMap<int, QVariant> & values, bool submit)
{
    qDebug() << "Insert into table:" << tableName();
    /*if(submit && editStrategy() == OnManualSubmit)
    {
        startTransaction();
    }

    int rowCount = this->rowCount();
    qDebug() << rowCount;
    if(!QSqlTableModel::insertRows(rowCount, 1))
    {
        qDebug() << "insertRows" << lastError().text();
        return false;
    }

    bool ok = true;
    for(QMap<int, QVariant>::const_iterator it = values.cbegin(); it != values.cend(); it++)
    {
        ok = setData(index(rowCount, it.key()), it.value());
        qDebug() << it.key() << ", " << it.value();
    }

    if(submit && editStrategy() == OnManualSubmit)
    {
        return endTransaction();
    }
    else
    {
        return ok;
    }*/
    QSqlRecord record = this->record();
    for(QMap<int, QVariant>::const_iterator it = values.cbegin(); it != values.cend(); it++)
    {
        record.setValue(it.key(), it.value());
        qDebug() << it.key() << ", " << it.value();
    }
    insertRecord(-1, record);
}

bool BaseModel::insertRows(const QList<QMap<int, QVariant> > &values, bool submit)
{
    qDebug() << "Insert rows into table:" << tableName();
    if(submit && editStrategy() == OnManualSubmit)
    {
        startTransaction();
    }

    bool ok = true;
    for(QList<QMap<int, QVariant> >::const_iterator it = values.cbegin(); it != values.cend(); it++)
    {
        ok = insertRow(*it, false);
    }

    if(submit && editStrategy() == OnManualSubmit)
    {
        return endTransaction();
    }
    else
    {
        return ok;
    }
}

bool BaseModel::removeRow(int row, bool submit)
{
    qDebug() << "Delete row:" << row;
    if(submit && editStrategy() == OnManualSubmit)
    {
        startTransaction();
    }

    bool ok = QSqlTableModel::removeRow(row);

    if(submit && editStrategy() == OnManualSubmit)
    {
        return endTransaction();
    }
    else
    {
        return ok;
    }
}

bool BaseModel::startTransaction()
{
    return this->database().transaction();
}

bool BaseModel::endTransaction()
{
    if(submitAll())
    {
        return database().commit();
    }
    else
    {
        database().rollback();
        qDebug() << "The database reported an error: "
                 << lastError().text();
        return false;
    }
}

void BaseModel::setTable(const QString &tableName)
{
    QSqlRelationalTableModel::setTable(tableName);
}
