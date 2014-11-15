#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <basemodel.h>

#include <QDebug>
#include <QSqlError>

class MovieModel : public BaseModel
{
public:
    MovieModel(QObject *parent = 0);

    bool insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                     const QString & genre, int year);
};

#endif // MOVIEMODEL_H
