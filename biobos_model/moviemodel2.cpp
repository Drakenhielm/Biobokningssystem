#include "moviemodel2.h"

MovieModel2::MovieModel2(QObject *parent)
    : BaseModel2("select * from movie", parent)
{
}

int MovieModel2::insertMovie(const QString & title, int playTime, int ageLimit, const QString & description,
                 const QString & genre, int year)
{
    QSqlRecord record = this->record();
    record.setValue(Title, title);
    record.setValue(PlayTime, "playTime");
    record.setValue(AgeLimit, ageLimit);
    record.setValue(Description, description);
    record.setValue(Genre, genre);
    record.setValue(Year, year);
    if(dh.insert("movie", record) > 0)
        insertRows(0, 1);
    return 1;
}
