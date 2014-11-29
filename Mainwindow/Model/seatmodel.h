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
        SeatID,
        Row,
        Column,
        SeatNr,
        HallID
    };

    virtual void refresh();

    int getSeatID(int row) const { return data(index(row, SeatID)).toInt(); }
    int getRow(int row) const { return data(index(row, Row)).toInt(); }
    int getColumn(int row) const { return data(index(row, Column)).toInt(); }
    int getSeatNr(int row) const { return data(index(row, SeatNr)).toInt(); }
    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }

    void setHall(int id);
    void setShow(int id);
    //void setBooking(const QString &phone);

private:
    int hallID;
    int showID;
    //QString bookingPhoneNr;

    void fixQuery();

};

#endif // SEATMODEL_H
