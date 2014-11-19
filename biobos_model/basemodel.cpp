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

bool BaseModel::insertRow(const QSqlRecord &record)
{
    return dh.insert("movie", record) == 1;
}

bool BaseModel::insertRows(const QList<QMap<int, QVariant> > &values, bool submit)
{
    bool ok = true;
    /*for(QList<QMap<int, QVariant> >::const_iterator it = values.cbegin(); it != values.cend(); it++)
    {
        ok = insertRow(*it, false);
    }*/
    return ok;
}

bool BaseModel::deleteWhere(const QString &column, const QVariant &value)
{
    return dh.remove(QString("movie"), column, value);
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
