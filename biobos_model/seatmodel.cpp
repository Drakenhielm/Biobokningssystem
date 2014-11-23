#include "seatmodel.h"

SeatModel::SeatModel(QObject *parent)
    : BaseModel("seat", parent)
{
    hallID = 0;
    showID = 0;
}

/*int SeatModel::rowCount(const QModelIndex & parent = QModelIndex()) const
{
    return BaseModel::data(BaseModel::index(BaseModel::rowCount(), 1)).toInt();
}

int SeatModel::columnCount(const QModelIndex & parent = QModelIndex()) const
{
    return BaseModel::data(BaseModel::index(BaseModel::rowCount(), 2)).toInt();
}

QVariant SeatModel::data(const QModelIndex & index, int role = Qt::DisplayRole)
{
    if(role == Qt::DisplayRole)
    {

    }
}*/

void SeatModel::refresh()
{
    fixQuery();
    BaseModel::refresh();
    while(canFetchMore())
        fetchMore();
}

void SeatModel::setHall(int id)
{
    hallID = id;
}

void SeatModel::setShow(int id)
{
    showID = id;
}

void SeatModel::setBooking(const QString &phone)
{
    bookingPhoneNr = phone;
}

void SeatModel::fixQuery()
{
    QString queryStr = QString("SELECT seat.*, b_all.BookingID AS Booked, b_current.BookingID AS CurrentBooking")
                       +" from seat"
                       +" LEFT JOIN booking as b_all ON b_all.SeatID = seat.SeatID and b_all.ShowID = " +(showID+'0')
                       +" LEFT JOIN booking as b_current ON b_current.SeatID = seat.SeatID and b_current.ShowID = " +(showID+'0')
                       //+" WHERE HallID = "+(hallID+'0')
                       +" GROUP BY seat.SeatID";
    //setFilter("HallID = '1'");
    //qDebug() << queryStr;
    setQuery(queryStr);
}

