#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", parent)
{
}

bool MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year, bool submit)
{
    QMap<int, QVariant> values;
    values.insert(Title, title);
    values.insert(PlayTime, playTime);
    values.insert(AgeLimit, ageLimit);
    values.insert(Description, description);
    values.insert(Genre, genre);
    values.insert(Year, year);
    return insertRow(values, submit);
}


