#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", parent)
{
    setQuery("SELECT * FROM movie");
}

int MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year)
{
    QList<QPair<QString, QVariant> > values;
    values.append(qMakePair(QString("Title"), title));
    values.append(qMakePair(QString("PlayTime"), playTime));
    values.append(qMakePair(QString("AgeLimit"), ageLimit));
    values.append(qMakePair(QString("Description"), description));
    values.append(qMakePair(QString("Genre"), genre));
    values.append(qMakePair(QString("Year"), year));
    return dh.insert("movie", values);
}


