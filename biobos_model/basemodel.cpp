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

bool BaseModel::submitAll(bool insideTransaction)
{
    if(insideTransaction)
    {
        database().transaction();
        if(QSqlTableModel::submitAll())
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
    return QSqlTableModel::submitAll();
}

bool BaseModel::insertRow(const QMap<int, QVariant> & values, bool submit)
{
    //qDebug() << "Insert into table:" << tableName();
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
        //qDebug() << it.key() << ", " << it.value();
    }
    insertRecord(-1, record);
}

bool BaseModel::insertRows(const QList<QMap<int, QVariant> > &values, bool submit)
{
    bool ok = true;
    for(QList<QMap<int, QVariant> >::const_iterator it = values.cbegin(); it != values.cend(); it++)
    {
        ok = insertRow(*it, false);
    }
    return ok;
}

bool BaseModel::deleteWhere(const QString &column, const QVariant &value)
{
    QSqlQuery query;
    query.prepare(QString("DELETE FROM %1 WHERE %2 = :val").arg(tableName()).arg(column));
    query.bindValue(":val", value);
    bool ok = query.exec();
    qDebug() << query.lastError().text();
    return ok;
}

void BaseModel::setTable(const QString &tableName)
{
    QSqlRelationalTableModel::setTable(tableName);
}

/*QString query = selectStatement();
    if (query.isEmpty())
        return false;

    revertAll();
    QSqlQuery qu(query, d->db);
    setQuery(qu);

    if (!qu.isActive() || lastError().isValid()) {
        // something went wrong - revert to non-select state
        d->initRecordAndPrimaryIndex();
        return false;
    }
    return true;*/
