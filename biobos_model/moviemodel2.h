#ifndef MovieModel2_H
#define MovieModel2_H

#include <baseclass2.h>

#include <QDebug>
#include <QSqlError>

class MovieModel2 : public BaseModel2
{
public:
    enum Column {MovieID = 0, Title = 1, PlayTime = 2, AgeLimit = 3, Description = 4, Genre = 5, Year = 6, MoviePoster = 7};

    MovieModel2(QObject *parent = 0);

    int insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                     const QString & genre, int year);
};

#endif // MovieModel2_H
