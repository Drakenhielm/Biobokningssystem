#ifndef BOOKINGMODEL_H
#define BOOKINGMODEL_H

#include <basemodel.h>
#include <databasehandler.h>

class BookingModel : public BaseModel
{
public:
    BookingModel(QObject *parent = 0);

    int insertBooking(int ShowID, int seatID, const QString &phone);
    int insertBookings(int ShowID, const QList<int> &seatIDs, const QString &phone);
};

#endif // BOOKINGMODEL_H
