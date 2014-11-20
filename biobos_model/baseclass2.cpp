#include "baseclass2.h"

BaseModel2::BaseModel2(const QString &query, QObject *parent)
    : QSqlQueryModel(parent)
{
    setQuery(query);
}

/*bool BaseModel2::submitAll(bool insideTransaction)
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
}*/

bool BaseModel2::insertRow(int row, const QModelIndex & parent)
{
    //return dh.insert("movie", record) == 1;
    return false;
}

bool BaseModel2::insertRows(int row, int count, const QModelIndex &parent)
{
    bool ok = true;
    beginInsertRows(parent, row, count+row-1);
    endInsertRows();
    return ok;
}

bool BaseModel2::deleteWhere(const QString &column, const QVariant &value)
{
    return dh.remove(QString("movie"), column, value);
}

void BaseModel2::setQuery(const QString & query)
{
    QSqlQueryModel::setQuery(query);
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
