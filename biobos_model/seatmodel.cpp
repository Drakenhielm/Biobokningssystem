#include "seatmodel.h"

SeatModel::SeatModel(QObject *parent)
    : BaseModel("seat", "null", parent)
{
    hallID = 0;
    showID = 0;
}

//virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
//virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
//virtual QVariant QAbstractItemModel::data(const QModelIndex & index, int role = Qt::DisplayRole);

void SeatModel::refresh()
{
    fixQuery();
    return BaseModel::refresh();
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
                       +" WHERE HallID = "+(hallID+'0')
                       +" GROUP BY seat.SeatID";
    //setFilter("HallID = '1'");
    qDebug() << queryStr;
    QSqlQuery query(queryStr);
    setQuery(query);
}

