#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", "MovieID", parent)
{
    setQuery("SELECT * FROM movie ORDER BY Title");
}

int MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    QList<QPair<QString, QVariant> > values;
    values.append(qMakePair(QString("Title"), title));
    values.append(qMakePair(QString("PlayTime"), playTime));
    values.append(qMakePair(QString("AgeLimit"), ageLimit));
    values.append(qMakePair(QString("Description"), description));
    values.append(qMakePair(QString("Genre"), genre));
    values.append(qMakePair(QString("Year"), year));
    values.append(qMakePair(QString("MoviePoster"), imagePath));
    return dh.insert("movie", values);
}

bool MovieModel::editMovie(int movieID, const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, const QString &imagePath)
{
    QList<QPair<QString, QVariant> > values;
    values.append(qMakePair(QString("MovieID"), movieID));
    values.append(qMakePair(QString("Title"), title));
    values.append(qMakePair(QString("PlayTime"), playTime));
    values.append(qMakePair(QString("AgeLimit"), ageLimit));
    values.append(qMakePair(QString("Description"), description));
    values.append(qMakePair(QString("Genre"), genre));
    values.append(qMakePair(QString("Year"), year));
    values.append(qMakePair(QString("MoviePoster"), imagePath));
    return dh.edit("movie", values, "MovieID", movieID);
}
