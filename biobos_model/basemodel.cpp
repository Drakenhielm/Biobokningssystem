#include "basemodel.h"

BaseModel::BaseModel(const QString &tableName, QObject *parent)
    : QSqlQueryModel(parent)
{
    this->tableName = tableName;
}

BaseModel::BaseModel(const QString &tableName, const QString &displayQuery, QObject *parent)
    : QSqlQueryModel(parent)
{
    this->tableName = tableName;
    this->sqlStatement = displayQuery;
    setQuery(displayQuery);
}

/*Everywhere a columnheader contains "DateTime" the value will be converted to QDateTime. */
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

/*Delete every row in the database where the value in column is equal to value. */
bool BaseModel::deleteWhere(const QString &column, const QVariant &value)
{
    return dh.remove(tableName, column, value);
}

/*Refresh model.
 * Populates the model with data from the database
 * using the specified sqlStatement and filter.*/
void BaseModel::refresh()
{
    query().exec();
    //setQuery(query());
}

/*filter is the same as the where clause in a sql statement*/
void BaseModel::setFilter(const QString &filter)
{
    QSqlQuery query = this->query();
    QString sql = query.lastQuery();
    removeFilter(sql);
    sql.prepend("SELECT * FROM (");
    sql.append(") WHERE ");
    sql.append(filter);
    qDebug() << sql;
    query.prepare(sql);
    //QList<QVariant> list = query().boundValues().values();
    //int numOfBoundValues = query().boundValues().size();
    int i = 0;
    while(query.boundValue(i).isValid())
    {
        query.bindValue(i, query.boundValue(i));
        qDebug() << i << ": "
                 << query.boundValue(i);
        i++;
    }
    //this->query().boundValues()
    //query.exec();
    setQuery(query);
    lastFilterQuery = this->query().lastQuery();
    qDebug() << lastFilterQuery;
    qDebug() << this->query().executedQuery();
    /*if(!currentFilter.isEmpty())
        clearFilter();
    //QList<QString> list = fixPlaceholders(filter);
    currentFilter = filter;
    QString queryStr = query().executedQuery();
    if(filterFlag)
    {
        //queryStr.lastIndexOf("WHERE")
        //queryStr.remove(0, QString("SELECT * FROM( ").length());
        //queryStr.remove(queryStr.length()-)Qt::MatchFlag
    }
    //QMap<QString, QMap> map;
    //map.insert();
    query().prepare(queryStr);*/
}

void BaseModel::clearFilter()
{
    QSqlQuery query = this->query();
    QString sql = query.lastQuery();
    removeFilter(sql);

    lastFilterQuery = this->query().lastQuery();
}

/*Put placeholders (?) evrywhere inside two single quotation marks and
 * return a list with the values.
 * Example: "id = '437'" transforms to "id = '?'"
 *          and the returned list contains 437.*/
QList<QString> BaseModel::fixPlaceholders(QString &str)
{
    QList<QString> list;
    int start = 0;
    int end = 0;
    bool cont = true;
    while(cont)
    {
        start = str.indexOf('\'', start);
        end = str.indexOf('\'', start+1);
        if(start != -1 && end != -1)
        {
            list.append(str.mid(start+1, end-start-1));
            str.replace(start, end-start+1, QString('?'));
            cont = true;
        }
        else if(start != -1 || end != -1)
        {
            cont = false;
        }
        else
        {
            cont = false;
        }
    }
    return list;
}

/*Set a query to the referenced QSqlQuery using the sqlStatement and the filter*/
void BaseModel::filterQuery(QSqlQuery &query, const QString &sqlStr, const QString &filter)
{
    QString tmpSqlStmt = sqlStr;
    QString tmpFilter = filter;
    QList<QString> list = fixPlaceholders(tmpFilter);
    if(list.isEmpty())
        return;

    tmpSqlStmt.prepend("SELECT * FROM (");
    tmpSqlStmt.append(") WHERE ");
    tmpSqlStmt.append(tmpFilter);

    query.prepare(tmpSqlStmt);
    for(int i = 0; i < list.size(); i++)
    {
        query.bindValue(i, list.at(i));
    }
    query.exec();
}

void BaseModel::getLastExecutedQuery(QSqlQuery &query)
{
    //QString query = query().executedQuery();

}

void BaseModel::removeFilter(QString &query)
{
    if(query != lastFilterQuery)
        return;

    int i = QString("SELECT * FROM (").length();
    int n = query.lastIndexOf(") WHERE ") - i;
    query = query.mid(i, n);
}