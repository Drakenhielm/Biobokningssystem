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
    //setEditStrategy(OnManualSubmit);
}

QVariant BaseModel::data(const QModelIndex &item, int role) const
{
    /*QVariant value = QSqlRelationalTableModel::data(item, role);
    if (value.isValid() && role == Qt::DisplayRole) {
        if(value.type() == QVariant::String)
        {
            return "Hello";//value.toDateTime().toString("d-MMM-yy");
        }
    }*/
    return QSqlRelationalTableModel::data(item, role);
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

bool BaseModel::deleteWhere(const QString &column, const QVariant &value)
{
    return dh.remove(tableName(), column, value);
}

void BaseModel::setTable(const QString &tableName)
{
    QSqlRelationalTableModel::setTable(tableName);
}
