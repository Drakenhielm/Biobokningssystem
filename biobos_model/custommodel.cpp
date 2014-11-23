#include "custommodel.h"

CustomModel::CustomModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int CustomModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return recordList.size();
}

int CustomModel::columnCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    if(recordList.size() <= 0)
        return 0;

    QSqlRecord record = recordList.first();
        if(record.isEmpty())
            return 0;
    return record.count();
}

QVariant CustomModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= recordList.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        QSqlRecord record = recordList.at(index.row());
        return record.value(index.column());
    }
    return QVariant();
}

void CustomModel::setQuery(const QString &queryStr)
{
    QSqlQuery query(queryStr);
    //beginInsertRows(QModelIndex(), 0, 255);

    while(query.next())
    {
        //qDebug() << query.value(0);
        recordList.append(query.record());
    }

    //endInsertRows();
}
