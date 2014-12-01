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

    int getMaxRow() const { return rowMax; }
    int getMaxColumn() const { return colMax; }

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
