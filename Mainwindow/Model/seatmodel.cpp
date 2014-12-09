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

QString SeatModel::sqlStatement(int hallID, int showID)
{
    return QString("SELECT seat.*, b.BookingID FROM seat "
                   "LEFT JOIN ( "
                        "SELECT * FROM booking "
                        "LEFT JOIN seatbooking ON seatbooking.BookingID = booking.BookingID "
                   ") b ON b.SeatID = seat.SeatID AND b.ShowID = "+QString::number(showID)+
                   " WHERE seat.HallID = "+QString::number(hallID)+
                   " GROUP BY seat.SeatID"
                   " ORDER BY seat.Row, seat.Column");
}

QPair<int, int> SeatModel::getHallSize(int hallID)
{
    QString queryStr = QString("SELECT Max(Row), MAX(Column) FROM seat WHERE HallID = %1").arg(hallID);
    QSqlQuery query(queryStr);
    if(query.next())
    {
        //qDebug() << "getMatrixSize() rows, cols" << query.value(0).toInt() << query.value(1).toInt();
        return qMakePair(query.value(0).toInt(), query.value(1).toInt());
    }
    return qMakePair(0, 0);
}

QList<QList<int> > SeatModel::getSeatStateList() const
{
    QList<QList<int> > list;
    for(int r = 0; r < rowMax; r++)
    {
        list.append(QList<int>());
        for(int c = 0; c < colMax; c++)
        {
            int row = r*colMax+c;
            if(getSeatType(row) == NoSeat)
                list[r].append(NoSeat);
            else if(getSeatType(row) == Seat)
            {
                if(getBookingID(row) > 0)
                    list[r].append(Booked);
                else
                    list[r].append(Available);
            }

        }
    }
    return list;
}
