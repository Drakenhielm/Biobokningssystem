#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>

#include <QDebug>
#include <QSqlRecord>


class BaseModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    BaseModel(const QString &tableName, QObject *parent = 0);
    BaseModel(const QString & tableName, const QString & query = QString(), QObject *parent = 0);

    //reimplemented functions
    bool insertRow(const QMap<int, QVariant> & values, bool submit = true);
    bool insertRows(const QList<QMap<int, QVariant> > & values, bool submit = true);
    bool removeRow(int row, bool submit = true);

signals:

public slots:

private:
    void initBaseModel(const QString & tableName, const QString & query = QString());

    bool startTransaction();
    bool endTransaction();

    //hide derived functions
    void setTable(const QString &tableName);

};

#endif // BASEMODEL_H
