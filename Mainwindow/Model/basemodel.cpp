#include "basemodel.h"

BaseModel::BaseModel(const QString &tableName, const QString &primaryKey, QObject *parent)
    : QSqlQueryModel(parent)
{
    this->tableName = tableName;
    this->primaryKey = primaryKey;
}

/*Everywhere a column header contains "DateTime" the value will be converted to QDateTime. */
QVariant BaseModel::data(const QModelIndex &item, int role) const
{
    QVariant value = QSqlQueryModel::data(item, role);
    if (value.isValid() && role == Qt::DisplayRole) {
        if(record().fieldName(item.column()).contains("DateTime", Qt::CaseInsensitive))
        {
            if(value.toDate() == QDate::currentDate())
                return value.toDateTime().toString("'Today' H:mm");
            if(value.toDate() == QDate::currentDate().addDays(1))
                return value.toDateTime().toString("'Tomorrow' H:mm");
            return value.toDateTime().toString("d/M/yy H:mm");
        }
    }
    return QSqlQueryModel::data(item, role);
}

bool BaseModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(row > rowCount())
        return false;
    dh.transaction();
    bool ok = true;
    for(int i = 0; i < count; i++)
    {
        QSqlRecord rec(record(row));
        if(!rec.isEmpty())
        {
            QVariant value = rec.value(primaryKey);
            if(value.isValid())
                ok = dh.remove(tableName, primaryKey, value);
        }
    }
    return ok && dh.endTransaction(ok);
}

/*Delete every row in the database where the value in column is equal to value.
 * Calls remove function from DatabaseHandler. */
bool BaseModel::removeWhere(const QString &column, const QVariant &value)
{
    return dh.remove(tableName, column, value);
}

/*Refresh model.
 * Populates the model with data from the database
 * using the specified sqlStatement and filter.*/
void BaseModel::refresh()
{
    query().exec();
    setQuery(query());
}

/*filter is the same as the where clause in a sql statement*/
void BaseModel::setFilter(const QString &filter, QVariant placeholder)
{
    QList<QVariant> list;
    list.append(placeholder);
    setFilter(filter, list);

}

void BaseModel::setFilter(const QString &filter, const QList<QVariant> &placeholderList)
{
    QSqlQuery query = this->query();
    QString sql = query.lastQuery();
    int numBefore = numOfPlaceholders(sql);
    removeFilter(sql);
    int numAfter = numOfPlaceholders(sql);
    sql.prepend("SELECT * FROM (");
    sql.append(") WHERE ");
    sql.append(filter);
    QList<QVariant> list = getBoundValues(query);
    list.erase(list.end()-(numBefore-numAfter), list.end());
    if(!placeholderList.isEmpty())
        list.append(placeholderList);
    prepareQuery(query, sql, list);
    query.exec();
    setQuery(query);
    lastFilterQuery = sql;
    qDebug() << sql;
}

void BaseModel::clearFilter()
{
    QSqlQuery query = this->query();
    QString sql = query.lastQuery();
    removeFilter(sql);
    prepareQuery(query, sql, getBoundValues(query));
    query.exec(sql);
    setQuery(query);
    lastFilterQuery.clear();
}

/*Prepare "query" with the statement from "sql" and bind parameters from "parameterList" */
void BaseModel::prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList)
{
    query.prepare(sql);
    for(int i = 0; i < parameterList.size(); i++)
    {
        query.addBindValue(parameterList.at(i));
    }
}

/*Manipulate the string by removing the part that was added by setFilter() */
void BaseModel::removeFilter(QString &query)
{
    //qDebug() << lastFilterQuery << " : " << query;
    if(query != lastFilterQuery)
        return;

    int i = QString("SELECT * FROM (").length();
    int n = query.lastIndexOf(") WHERE ") - i;
    query = query.mid(i, n);
}

/*Returns the bound values from the query in a list*/
QList<QVariant> BaseModel::getBoundValues(const QSqlQuery &query) const
{
    QList<QVariant> list;
    int i = 0;
    while(query.boundValue(i).isValid())
    {
        list.append(query.boundValue(i));
        i++;
    }
    return list;
}

/*Return the number of placeholders in a sql string*/
int BaseModel::numOfPlaceholders(const QString &sqlStr) const
{
    int i = 0;
    int count = 0;
    bool b = true;
    while(b)
    {
        i = sqlStr.indexOf(QRegExp("[:?]"), ++i); //search for next position of : or ?
        if(i == -1) // no match
            b = false;
        else //match
            count++;
    }
    return count;
}
