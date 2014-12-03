#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", "MovieID", parent)
{
    setQuery("SELECT * FROM movie ORDER BY Title");
}

int MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    return dh.insert("movie", toList(title, playTime, ageLimit, description, genre, year, imagePath));
}

int MovieModel::editMovie(int row, const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    return dh.edit("movie", toList(title, playTime, ageLimit, description, genre, year, imagePath, row),
                   primaryKey,
                   getMovieID(row));
}

QList<QPair<QString, QVariant> > MovieModel::toList(int row, const QString & title,
    int playTime, int ageLimit, const QString & description,
    const QString & genre, int year, const QString &imagePath) const
{
    QList<QPair<QString, QVariant> > values;
    //if()
    values.append(qMakePair(QString("Title"), title));
    values.append(qMakePair(QString("PlayTime"), playTime));
    values.append(qMakePair(QString("AgeLimit"), ageLimit));
    values.append(qMakePair(QString("Description"), description));
    values.append(qMakePair(QString("Genre"), genre));
    values.append(qMakePair(QString("Year"), year));
    values.append(qMakePair(QString("MoviePoster"), ));
    return values;
}
