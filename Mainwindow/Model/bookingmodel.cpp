#include "bookingmodel.h"

BookingModel::BookingModel(QObject *parent)
    : BaseModel("booking", "BookingID", parent)
{
    setQuery("SELECT b.BookingID, b.ShowID, s.MovieID, b.Phone, m.Title AS Movie, s.DateTime AS Showtime, "
             "hall.Name AS Hall, GROUP_CONCAT(seat.SeatNr) AS Seats "
             "FROM booking AS b "
             "LEFT JOIN show AS s ON s.ShowID = b.ShowID "
             "LEFT JOIN movie AS m ON m.MovieID = s.MovieID "
             "LEFT JOIN seatbooking AS sb ON sb.BookingID = b.BookingID "
             "LEFT JOIN seat ON seat.SeatID = sb.SeatID "
             "LEFT JOIN hall ON hall.HallID = seat.HallID "
             "GROUP BY b.BookingID "
             "ORDER BY b.BookingID DESC");
}

QVariant BookingModel::data(const QModelIndex &item, int role) const
{
    QVariant value = BaseModel::data(item, role);
    if (value.isValid() && role == Qt::DisplayRole)
    {
        if(item.column() == DateTime)
        {
            return dateTimeString(value.toDateTime());
        }
    }
    return BaseModel::data(item, role);
}

QList<int> BookingModel::getSeats(int row) const
{
    QList<int> list;
    QStringList strList = data(index(row, Seats)).toString().split(',');
    for(int i = 0; i < strList.size(); i++)
    {
        list.append(strList.at(i).toInt());
    }
    return list;
}

int BookingModel::insertBookings(int showID, const QList<int> &seatIDs, const QString &phone)
{
    QMap<QString, QVariant> values;
    int id;
    bool ok;

    dh.transaction();

    //insert booking
    values.insert(QString("ShowID"), showID);
    values.insert(QString("Phone"), phone);
    id = dh.insert("booking", values);
    ok = (id != -1);
    values.clear();

    //insert seatbookings
    insertSeatBookings(id, seatIDs);

    dh.endTransaction(ok);

    return id; //BookingID
}

bool BookingModel::editBookings(int bookingID, int showID, const QList<int> &seatIDs, const QString &phone)
{
    QMap<QString, QVariant> values;
    bool ok = true;

    dh.transaction();

    //edit booking
    values.insert(QString("ShowID"), showID);
    values.insert(QString("Phone"), phone);
    ok &= dh.edit("booking", values, "BookingID", bookingID);
    values.clear();

    //remove old and insert new seatbookings
    dh.remove("seatbooking", "BookingID", bookingID);
    insertSeatBookings(bookingID, seatIDs);

    dh.endTransaction(ok);

    return ok;
}

bool BookingModel::insertSeatBookings(int bookingID, const QList<int> &seatIDs)
{
    QMap<QString, QVariant> values;
    bool ok = true;
    for(int i = 0; i < seatIDs.size(); i++)
    {
        values.insert(QString("BookingID"), bookingID);
        values.insert(QString("SeatID"), seatIDs.at(i));
        ok &= dh.insert("seatbooking", values);
        values.clear();
    }
    return ok;
}

bool BookingModel::remove(const QVariant &pkValue)
{
    bool ok = true;

    dh.transaction();

    ok = ok && dh.remove("booking", "BookingID = ?", pkValue);
    ok = ok && dh.remove("seatbooking", "BookingID = ?", pkValue);

    return ok && dh.endTransaction(ok);;
}
