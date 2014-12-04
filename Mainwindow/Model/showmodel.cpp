#include "showmodel.h"

ShowModel::ShowModel(QObject *parent)
    : BaseModel("show", "ShowID", parent)
{
    setQuery("SELECT show.*, hall.Name, "
             "COUNT(seat.SeatID) - COUNT(b.SeatBookingID) AS AvailableSeats "
             "FROM show "
             "LEFT JOIN hall ON hall.HallID = show.HallID "
             "LEFT JOIN seat ON seat.HallID = show.HallID "
             "LEFT JOIN ( "
                "SELECT seatbooking.SeatBookingID, booking.ShowID, seatbooking.SeatID "
                "FROM booking "
                "LEFT JOIN seatbooking ON seatbooking.BookingID = booking.BookingID "
             ") b ON b.ShowID = show.ShowID AND b.SeatID = seat.SeatID "
             "GROUP BY show.ShowID");
}

QVariant ShowModel::data(const QModelIndex &item, int role) const
{
    QVariant value = BaseModel::data(item, role);
    if (value.isValid() && role == Qt::DisplayRole)
    {
        if(item.column() == ThreeD || item.column() == Subtitles)
        {
            if(value.toBool())
                return QString("Yes");
            else
                return QString("No");
        }
    }
    return BaseModel::data(item, role);
}

int ShowModel::insertShow(const QDateTime & dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    QList<QPair<QString, QVariant> > values;
    values.append(qMakePair(QString("DateTime"), dateTime));
    values.append(qMakePair(QString("Price"), price));
    values.append(qMakePair(QString("ThreeD"), threeD));
    values.append(qMakePair(QString("Subtitles"), subtitles));
    values.append(qMakePair(QString("Language"), language));
    values.append(qMakePair(QString("MovieID"), movieID));
    values.append(qMakePair(QString("HallID"), hallID));
    dh.insert("show", values);
    return true;
}

bool ShowModel::editShow(int showID, const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    QList<QPair<QString, QVariant> > values;
    values.append(qMakePair(QString("ShowID"), showID));
    values.append(qMakePair(QString("DateTime"), dateTime));
    values.append(qMakePair(QString("Price"), price));
    values.append(qMakePair(QString("ThreeD"), threeD));
    values.append(qMakePair(QString("Subtitles"), subtitles));
    values.append(qMakePair(QString("Language"), language));
    values.append(qMakePair(QString("MovieID"), movieID));
    values.append(qMakePair(QString("HallID"), hallID));
    dh.edit("show", values, "ShowID", showID);
    return true;
}
