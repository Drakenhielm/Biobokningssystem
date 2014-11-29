#include "seatmodel.h"

SeatModel::SeatModel(QObject *parent)
    : BaseModel("seat", "SeatID", parent)
{
    //default
    hallID = 0;
    showID = 0;
}

void SeatModel::refresh()
{
    fixQuery();
    BaseModel::refresh();
    while(canFetchMore())
    {
        fetchMore();
    }
}

void SeatModel::setHall(int id)
{
    hallID = id;
}

void SeatModel::setShow(int id)
{
    showID = id;
}

/*void SeatModel::setBooking(const QString &phone)
{
    bookingPhoneNr = phone;
}*/

void SeatModel::fixQuery()
{
    QString queryStr = QString("SELECT seat.*, b_all.BookingID AS Booked, b_current.BookingID AS CurrentBooking")
                       +" FROM seat"
                       +" LEFT JOIN booking as b_all ON b_all.SeatID = seat.SeatID AND b_all.ShowID = " +(showID+'0')
                       +" LEFT JOIN booking as b_current ON b_current.SeatID = seat.SeatID AND b_current.ShowID = " +(showID+'0')
                       +" WHERE HallID = "+(hallID+'0')
                       +" GROUP BY seat.SeatID";
    setQuery(queryStr);
}

