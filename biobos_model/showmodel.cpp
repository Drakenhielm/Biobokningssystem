#include "showmodel.h"

ShowModel::ShowModel(QObject *parent)
    : BaseModel("show", parent)
{
    setJoinMode(QSqlRelationalTableModel::LeftJoin);
    //setRelation(MovieID, QSqlRelation("movie", "MovieID", "Title"));
    setRelation(HallID, QSqlRelation("hall", "HallID", "Name"));
}

bool ShowModel::insertShow(const QDateTime & dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    QSqlRecord record = this->record();
    record.setValue(DateTime, dateTime.toString("d MMM yy"));
    record.setValue(Price, price);
    record.setValue(ThreeD, threeD);
    record.setValue(Subtitles, subtitles);
    record.setValue(Language, language);
    record.setValue(MovieID, movieID);
    record.setValue(HallID, hallID);
    qDebug() << dh.insert("show", record);
    return true;
}
