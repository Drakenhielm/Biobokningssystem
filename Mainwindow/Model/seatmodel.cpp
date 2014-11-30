#include "seatmodel.h"

SeatModel::SeatModel(QObject *parent)
    : BaseModel("seat", "SeatID", parent)
{
    //default
    hallID = 0;
    showID = 0;
    rowMax = 0;
    colMax = 0;
}

void SeatModel::refresh()
{
    QPair<int, int> hallSize = getHallSize(hallID);
    if(hallSize.first == 0 || hallSize.second == 0)
    {
        //empty hall
        return;
    }
    rowMax = hallSize.first;
    colMax = hallSize.second;
    setQuery(sqlStatement(hallID, showID));
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

QString SeatModel::sqlStatement(int hallID, int showID)
{
    return QString("SELECT seat.*, b_all.BookingID AS Booked, b_current.BookingID AS CurrentBooking")
                       +" FROM seat"
                       +" LEFT JOIN booking as b_all ON b_all.SeatID = seat.SeatID AND "
                       + "b_all.ShowID = " + QString::number(showID)
                       +" LEFT JOIN booking as b_current ON b_current.SeatID = seat.SeatID AND "
                       + "b_current.ShowID = " + QString::number(showID)
                       + " WHERE HallID = "+ QString::number(hallID)
                       +" GROUP BY seat.SeatID";
}

QPair<int, int> SeatModel::getHallSize(int hallID)
{
    QString queryStr = QString("SELECT Max(Row), MAX(Column) FROM seat WHERE HallID = %1").arg(hallID);
    QSqlQuery query(queryStr);
    qDebug() << queryStr;
    if(query.next())
    {
        qDebug() << "getMatrixSize() rows, cols" << query.value(0).toInt() << query.value(1).toInt();
        return qMakePair(query.value(0).toInt(), query.value(1).toInt());
    }
    return qMakePair(0, 0);
}
