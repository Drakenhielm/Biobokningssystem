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
    QMap<QString, QVariant> values;
    values.insert(QString("DateTime"), dateTime);
    values.insert(QString("Price"), price);
    values.insert(QString("ThreeD"), threeD);
    values.insert(QString("Subtitles"), subtitles);
    values.insert(QString("Language"), language);
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("HallID"), hallID);
    dh.insert("show", values);
    return true;
}

bool ShowModel::editShow(int showID, const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    QMap<QString, QVariant> values;
    values.insert(QString("ShowID"), showID);
    values.insert(QString("DateTime"), dateTime);
    values.insert(QString("Price"), price);
    values.insert(QString("ThreeD"), threeD);
    values.insert(QString("Subtitles"), subtitles);
    values.insert(QString("Language"), language);
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("HallID"), hallID);
    dh.edit("show", values, "ShowID = ?", showID);
    return true;
}

bool ShowModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok = ok && dh.remove("show", "ShowID = ?", pkValue);
    ok = ok && dh.remove("booking", "ShowID IN (SELECT ShowID FROM show WHERE MovieID = ?)", pkValue);
    ok = ok && dh.remove("seatbooking",
                         "BookingID IN (SELECT BookingID FROM booking JOIN show ON booking.ShowID = show.ShowID WHERE MovieID = ?)",
                         pkValue);
    return ok && dh.endTransaction(ok);
}
