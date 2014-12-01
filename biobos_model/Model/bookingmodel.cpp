#include "bookingmodel.h"

BookingModel::BookingModel(QObject *parent)
    : BaseModel("booking", "BookingID", parent)
{
    setQuery("SELECT b.BookingID, b.ShowID, s.MovieID, b.Phone, m.Title, s.DateTime, "
             "COUNT(b.BookingID) AS Tickets, GROUP_CONCAT(sb.SeatID) AS SeatIDs "
             "FROM booking AS b "
             "LEFT JOIN movie AS m ON m.MovieID = b.ShowID "
             "LEFT JOIN show AS s ON s.ShowID = b.ShowID "
             "LEFT JOIN seatbooking AS sb ON sb.BookingID = b.BookingID "
             "GROUP BY b.BookingID "
             "ORDER BY b.BookingID DESC");
}

int BookingModel::insertBooking(int showID, int seatID, const QString &phone)
{
    QList<int> seatIDs;
    seatIDs.append(seatID);
    return insertBookings(showID, seatIDs, phone);
}

int BookingModel::insertBookings(int showID, const QList<int> &seatIDs, const QString &phone)
{
    QList<QPair<QString, QVariant> > values;
    int id;
    bool ok;

    dh.transaction();
    //insert booking
    values.append(qMakePair(QString("ShowID"), showID));
    values.append(qMakePair(QString("Phone"), phone));
    id = dh.insert("booking", values);
    ok = (id != -1);
    values.clear();

    //insert seatbookings
    for(int i = 0; i < seatIDs.size(); i++)
    {
        values.append(qMakePair(QString("BookingID"), id));
        values.append(qMakePair(QString("SeatID"), seatIDs.at(i)));
        if(ok)
            ok = (dh.insert("seatbooking", values) != -1);
        values.clear();
    }
    dh.endTransaction(ok);

    return id; //BookingID
}
