#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", parent)
{
}

int MovieModel::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year)
{
    /*QMap<int, QVariant> values;
    values.insert(Title, title);
    values.insert(PlayTime, playTime);
    values.insert(AgeLimit, ageLimit);
    values.insert(Description, description);
    values.insert(Genre, genre);
    values.insert(Year, year);
    return insertRow(values, submit);*/
    QSqlRecord record = this->record();
    record.setValue(Title, title);
    record.setValue(PlayTime, "playTime");
    record.setValue(AgeLimit, ageLimit);
    record.setValue(Description, description);
    record.setValue(Genre, genre);
    record.setValue(Year, year);
    //insertRecord(0, record);
    return insertRow(record);
}


