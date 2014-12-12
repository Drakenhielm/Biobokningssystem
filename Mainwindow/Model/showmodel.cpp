#include "showmodel.h"

ShowModel::ShowModel(QObject *parent)
    : BaseModel("show", "ShowID", parent)
{
    setQuery("SELECT show.*, hall.Name, "
             "COUNT(seat.SeatNr) - COUNT(b.SeatBookingID) AS AvailableSeats "
             "FROM show "
             "LEFT JOIN hall ON hall.HallID = show.HallID "
             "LEFT JOIN seat ON seat.HallID = show.HallID "
             "LEFT JOIN ( "
                "SELECT seatbooking.SeatBookingID, booking.ShowID, seatbooking.SeatID "
                "FROM booking "
                "LEFT JOIN seatbooking ON seatbooking.BookingID = booking.BookingID "
             ") b ON b.ShowID = show.ShowID AND b.SeatID = seat.SeatID "
             "GROUP BY show.ShowID ORDER BY DateTime");
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
        if(item.column() == DateTime)
        {
            return dateTimeString(value.toDateTime());
        }
    }
    return BaseModel::data(item, role);
}

int ShowModel::insertShow(const QDateTime & dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    //database values
    QMap<QString, QVariant> values;
    values.insert(QString("DateTime"), dateTime);
    values.insert(QString("Price"), price);
    values.insert(QString("ThreeD"), threeD);
    values.insert(QString("Subtitles"), subtitles);
    values.insert(QString("Language"), language);
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("HallID"), hallID);

    //insert show
    return dh.insert("show", values);
}

bool ShowModel::editShow(int showID, const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                int movieID, int hallID)
{
    dh.transaction();

    bool ok = true;

    //remove bookings
    ok = ok && dh.remove("booking", "ShowID = ?", showID);
    ok = ok && dh.remove("seatbooking",
                         "BookingID IN (SELECT BookingID FROM booking WHERE ShowID = ?)",
                         showID);

    //database values
    QMap<QString, QVariant> values;
    values.insert(QString("ShowID"), showID);
    values.insert(QString("DateTime"), dateTime);
    values.insert(QString("Price"), price);
    values.insert(QString("ThreeD"), threeD);
    values.insert(QString("Subtitles"), subtitles);
    values.insert(QString("Language"), language);
    values.insert(QString("MovieID"), movieID);
    values.insert(QString("HallID"), hallID);

    //edit show
    ok = ok && dh.edit("show", values, "ShowID = ?", showID);

    return ok && dh.endTransaction(ok);
}

bool ShowModel::remove(const QVariant &pkValue)
{
    bool ok = true;

    dh.transaction();

    //remove from show
    ok = ok && dh.remove("show", "ShowID = ?", pkValue);

    //remove from booking
    ok = ok && dh.remove("booking", "ShowID = ?", pkValue);

    //remove from seatbooking
    ok = ok && dh.remove("seatbooking",
                         "BookingID IN (SELECT BookingID FROM booking WHERE ShowID = ?)",
                         pkValue);

    return ok && dh.endTransaction(ok);
}
