#ifndef BOOKINGMODEL_H
#define BOOKINGMODEL_H

#include "basemodel.h"

class BookingModel : public BaseModel
{
public:
    BookingModel(QObject *parent = 0);

    enum Column
    {
        BookingID = 0,
        ShowID = 1,
        MovieID = 2,
        Phone = 3,
        Title = 4,
        DateTime = 5,
        Seats = 6
    };

    int insertBookings(int ShowID, const QList<int> &seatIDs, const QString &phone);
    bool editBookings(int bookingID, int showID, const QList<int> &seatIDs, const QString &phone);

    int getShowID(int row) const { return data(index(row, ShowID)).toInt(); }
    int getMovieID(int row) const { return data(index(row, MovieID)).toInt(); }
    QString getPhone(int row) const { return data(index(row, Phone)).toString(); }
    QString getTitle(int row) const { return data(index(row, Title)).toString(); }
    QDateTime getDateTime(int row) const { return data(index(row, DateTime)).toDateTime(); }
    QList<int> getSeats(int row) const;

protected:
    virtual bool remove(const QVariant &pkValue);

private:
    bool insertSeatBookings(int bookingID, const QList<int> &seatIDs);

};

#endif // BOOKINGMODEL_H
