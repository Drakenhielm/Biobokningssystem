#ifndef SQLGENERATOR_H
#define SQLGENERATOR_H

#include <QString>
#include <QList>
#include <QVariant>
#include <QSqlQuery>

class SqlHandler
{
public:
    SqlHandler();

    QString insertStatement(const QString &tableName, const QList<QPair<QString, QVariant> > &record);
    QString deleteStatement(const QString &tableName, const QString &where);
    QString updateStatement(const QString &tableName, const QString &where);

    void prepareQuery(QSqlQuery &query, const QString &sql, const QList<QVariant> &parameterList);
    QList<QVariant> getBoundValues(const QSqlQuery &query) const;
    int numOfPlaceholders(const QString &sqlStr) const;
};

#endif // SQLGENERATOR_H
