#ifndef SEATMODEL_H
#define SEATMODEL_H

#include <QDebug>
#include "basemodel.h"

class SeatModel : public BaseModel
{
public:
    SeatModel(QObject *parent = 0);

    enum Column
    {
        SeatID = 0,
        Row = 1,
        Column = 2,
        SeatNr = 3,
        SeatTypeIndex = 4,
        HallID = 5,
        BookingID = 6
    };

    enum SeatType
    {
        NoSeat = 0,
        Seat = 1,
        Available = 2,
        Booked = 4
    };

    virtual void refresh();

    int getSeatID(int row) const { return data(index(row, SeatID)).toInt(); }
    int getRow(int row) const { return data(index(row, Row)).toInt(); }
    int getColumn(int row) const { return data(index(row, Column)).toInt(); }
    int getSeatNr(int row) const { return data(index(row, SeatNr)).toInt(); }
    int getSeatType(int row) const { return data(index(row, SeatTypeIndex)).toInt(); }
    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }
    int getBookingID(int row) const { return data(index(row, BookingID)).toInt(); }

    int getMaxRow() const { return rowMax; }
    int getMaxColumn() const { return colMax; }

    QVector<QVector<int> > getSeatStateMatrix() const;

    void setHall(int id);
    void setShow(int id);

private:
    int hallID;
    int showID;
    int rowMax;
    int colMax;

    QString sqlStatement(int hallID, int showID);
    QPair<int, int> getHallSize(int hallID);

};

#endif // SEATMODEL_H
