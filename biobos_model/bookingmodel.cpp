#include "bookingmodel.h"

BookingModel::BookingModel(QObject *parent)
    : BaseModel("booking",
                QString("select booking.ShowID, show.MovieID, booking.Phone, movie.Title, show.DateTime, "
                        "count(booking.BookingID) as Tickets "
                        "from booking "
                        "left join movie on movie.MovieID = booking.ShowID "
                        "left join show on show.ShowID = booking.ShowID "
                        "group by booking.ShowID, booking.Phone"),
                        parent)
{
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
    int lastID;
    for(int i = 0; i < seatIDs.size(); i++)
    {
        values.append(qMakePair(QString("ShowID"), showID));
        values.append(qMakePair(QString("SeatID"), seatIDs.at(i)));
        values.append(qMakePair(QString("Phone"), phone));
        lastID = dh.insert("booking", values);
        values.clear();
    }
    return lastID;
}
