#include "moviemodel.h"

MovieModel::MovieModel(QObject *parent)
    : BaseModel("movie", "select * from movie", parent)
{
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
    /*QSqlRecord record = this->record();
    record.setValue(Title, title);
    record.setValue(PlayTime, "playTime");
    record.setValue(AgeLimit, ageLimit);
    record.setValue(Description, description);
    record.setValue(Genre, genre);
    record.setValue(Year, year);
    //insertRecord(0, record);
    return -1;*/
}


