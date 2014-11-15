#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QSqlRelationalTableModel>

class BaseModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit BaseModel(QObject *parent = 0);

signals:

public slots:

};

#endif // BASEMODEL_H
