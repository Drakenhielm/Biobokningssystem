#include "basemodel.h"

BaseModel::BaseModel(const QString &tableName, QObject *parent)
{
    initBaseModel(tableName, QString());
}

BaseModel::BaseModel(const QString &tableName, const QString &query, QObject *parent)
    : QSqlRelationalTableModel(parent)
{
    initBaseModel(tableName, QString());
}

void BaseModel::initBaseModel(const QString & tableName, const QString & query)
{
    setTable(tableName);
    if(!query.isEmpty())
        QSqlQueryModel::setQuery(query);
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void BaseModel::setTable(const QString &tableName)
{
    QSqlRelationalTableModel::setTable(tableName);
}

void BaseModel::setQuery(const QSqlQuery &query)
{
    QSqlRelationalTableModel::setQuery(query);
}
