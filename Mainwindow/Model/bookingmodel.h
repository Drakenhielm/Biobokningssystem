#ifndef BOOKINGMODEL_H
#define BOOKINGMODEL_H

#include "basemodel.h"

class BookingModel : public BaseModel
{
public:
    BookingModel(QObject *parent = 0);

    enum Column
    {
        ShowID = 0,
        MovieID = 1,
        Phone = 2,
        Title = 3,
        DateTime = 4,
        Tickets = 5
    };

    int insertBooking(int ShowID, int seatID, const QString &phone);
    int insertBookings(int ShowID, const QList<int> &seatIDs, const QString &phone);

    int getShowID(int row) const { return data(index(row, ShowID)).toInt(); }
    int getMovieID(int row) const { return data(index(row, MovieID)).toInt(); }
    QString getPhone(int row) const { return data(index(row, Phone)).toString(); }
    QString getTitle(int row) const { return data(index(row, Title)).toString(); }
    QDateTime getDateTime(int row) const { return data(index(row, DateTime)).toDateTime(); }
    int getTickets(int row) const { return data(index(row, Tickets)).toInt(); }

};

#endif // BOOKINGMODEL_H
