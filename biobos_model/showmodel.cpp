#include "showmodel.h"

ShowModel::ShowModel(QObject *parent)
    : BaseModel("show",
                /*QString("select show.* COUNT(seat.HallID) AS Sittplatser"
                             "from show"
                             "LEFT JOIN seat ON seat.HallID = show.HallID"
                             "GROUP BY show.ShowID"),*/
                parent)
{
}

int ShowModel::insertShow(const QDateTime & dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    DatabaseHandler::DatabaseRecord values;
    values.append(qMakePair(QString("DateTime"), dateTime));
    values.append(qMakePair(QString("Price"), price));
    values.append(qMakePair(QString("ThreeD"), threeD));
    values.append(qMakePair(QString("Subtitles"), subtitles));
    values.append(qMakePair(QString("Language"), language));
    values.append(qMakePair(QString("MovieID"), movieID));
    values.append(qMakePair(QString("HallID"), hallID));
    qDebug() << dh.insert("show", values);
    return true;
}
