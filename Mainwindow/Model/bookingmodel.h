#ifndef BOOKINGMODEL_H
#define BOOKINGMODEL_H

#include "basemodel.h"

class BookingModel : public BaseModel
{
public:
    BookingModel(QObject *parent = 0);

    //enum Column {SID = 0, Name = 1, ScreenSize = 2, SoundSystem = 3, Seats = 4};

    int insertBooking(int ShowID, int seatID, const QString &phone);
    int insertBookings(int ShowID, const QList<int> &seatIDs, const QString &phone);
};

#endif // BOOKINGMODEL_H
