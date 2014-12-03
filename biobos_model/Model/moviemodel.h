#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include "basemodel.h"

#include <QDebug>
#include <QSqlError>

class MovieModel : public BaseModel
{
public:
    enum Column
    {
        MovieID = 0,
        Title = 1,
        PlayTime = 2,
        AgeLimit = 3,
        Description = 4,
        Genre = 5,
        Year = 6,
        MoviePoster = 7
    };

    MovieModel(QObject *parent = 0);

    int insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                     const QString & genre, int year, const QString &imagePath);
    int editMovie(int row, const QString & title, int playTime, int ageLimit, const QString & description,
                     const QString & genre, int year, const QString &imagePath);

    int getMovieID(int row) const { return data(index(row, MovieID)).toInt(); }
    QString getTitle(int row) const { return data(index(row, Title)).toString(); }
    int getPlayTime(int row) const { return data(index(row, PlayTime)).toInt(); }
    int getAgeLimit(int row) const { return data(index(row, AgeLimit)).toInt(); }
    QString getDescription(int row) const { return data(index(row, Description)).toString(); }
    QString getGenre(int row) const { return data(index(row, Genre)).toString(); }
    int getYear(int row) const { return data(index(row, Year)).toInt(); }
    QString getMoviePoster(int row) const { return data(index(row, MoviePoster)).toString(); }

private:
    QList<QPair<QString, QVariant> > toList() const;
};

#endif // MOVIEMODEL_H
