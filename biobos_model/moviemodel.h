#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <basemodel.h>

#include <QDebug>
#include <QSqlError>

class MovieModel : public BaseModel
{
public:
    enum Column {MovieID = 0, Title = 1, PlayTime = 2, AgeLimit = 3, Description = 4, Genre = 5, Year = 6, MoviePoster = 7};

    MovieModel(QObject *parent = 0);

    bool insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                     const QString & genre, int year, bool submit = true);
};

#endif // MOVIEMODEL_H
