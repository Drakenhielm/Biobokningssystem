#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QDebug>

class CustomModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void setQuery(const QString &query);

signals:

public slots:

private:
    QList<QSqlRecord> recordList;
    QSqlQuery query;

};

#endif // CUSTOMMODEL_H
