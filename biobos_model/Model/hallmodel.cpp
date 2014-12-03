#include "hallmodel.h"

HallModel::HallModel(QObject *parent)
    : BaseModel("hall", "HallID", parent)
{
    setQuery(QString("SELECT hall.*, COUNT(seat.SeatID) AS Seats, "
                     "MAX(seat.Row) AS Rows, MAX(seat.Column) AS Columns "
                     "FROM hall "
                     "LEFT JOIN seat ON seat.HallID = hall.HallID "
                     "GROUP BY hall.HallID"));
}

int HallModel::insertHall(const QString &name, const QString &screenSize, const QString &soundSystem,
           const QList<QList<bool> > &seats)
{
    QList<QPair<QString, QVariant> > values;
    dh.transaction();
    values.append(qMakePair(QString("Name"), name));
    values.append(qMakePair(QString("ScreenSize"), screenSize));
    values.append(qMakePair(QString("SoundSystem"), soundSystem));
    int id = dh.insert("hall", values);
    int lastSeatID = insertSeats(id, seats) > 0;
    bool ok = id > 0 && lastSeatID > 0;
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}

int HallModel::insertSeats(int row, const QList<QList<bool> > &seats, int startSeatNr)
{
    QList<QPair<QString, QVariant> > values;
    int seatNr = startSeatNr;
    int lastID = -1;
    for(int r = 0; r < seats.size(); r++)
    {
        for(int c = 0; c < seats.at(r).size(); c++)
        {
            values.append(qMakePair(QString("Row"), r+1));
            values.append(qMakePair(QString("Column"), c+1));
            if(seats.at(r).at(c))
            {
                values.append(qMakePair(QString("SeatNr"), seatNr++));
                values.append(qMakePair(QString("SeatType"), 1));
            }
            else
            {
                values.append(qMakePair(QString("SeatType"), 0));
            }
            values.append(qMakePair(QString("HallID"), getHallID(row)));

            lastID = dh.insert("seat", values);
            values.clear();

            if(lastID == -1)
                return -1;
        }
    }
    return lastID;
}

/*bool HallModel::editHall(int row, const QString &name, const QString &screenSize, const QString &soundSystem,
           const QList<QList<bool> > &seats)
{
    bool ok = true;
    QList<QPair<QString, QVariant> > values;
    if(!seats.isEmpty())
        dh.transaction();

    values.append(qMakePair(QString("Name"), name));
    values.append(qMakePair(QString("ScreenSize"), screenSize));
    values.append(qMakePair(QString("SoundSystem"), soundSystem));
    int id = dh.insert("hall", values);
    ok = id > 0;
    values.clear();

    if(seats.isEmpty())
        return ok;

    int seatNr = 1;
    for(int r = 1; r <= seats.size(); r++)
    {
        for(int c = 1; c <= seats.at(r).size(); c++)
        {
            values.append(qMakePair(QString("Row"), r));
            values.append(qMakePair(QString("Column"), c));
            if(seats.at(r).at(c))
            {
                values.append(qMakePair(QString("SeatNr"), seatNr++));
                values.append(qMakePair(QString("SeatType"), 1));
            }
            else
            {
                values.append(qMakePair(QString("SeatType"), 0));
            }
            values.append(qMakePair(QString("HallID"), id));
            if(ok)
            {
                if(r > getRows(row))
                    ok &= dh.insert("seat", values) != -1;
            }
            values.clear();
        }
    }
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}*/



/*bool HallModel::editSeats(int row, const QList<QList<bool> > &seats,
              int startSeatNr = 1, QPoint offset = QPoint())
{
    int seatNr = startSeatNr;
    bool ok = true;
    for(int r = startPoint.y(); r < seats.size(); r++)
    {
        if(offset.y()+seats.size() > getRows(row)
                || offset.x()+seats.at(r).size() > getColumns(row))
        {
            insertSeats(row, list, startSeatNr, )
        }
        for(int c = startPoint.x(); c < seats.at(r).size(); c++)
        {
            values.append(qMakePair(QString("Row"), r));
            values.append(qMakePair(QString("Column"), c));
            if(seats.at(r).at(c))
            {
                values.append(qMakePair(QString("SeatNr"), seatNr++));
                values.append(qMakePair(QString("SeatType"), 1));
            }
            else
            {
                values.append(qMakePair(QString("SeatType"), 0));
            }
            values.append(qMakePair(QString("HallID"), hallID));
            lastID = dh.insert("seat", values);
            values.clear();
            if(lastID == -1)
                return -1;
        }
    }
}*/

bool HallModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok &= dh.remove(tableName, primaryKey, pkValue);
    ok &= dh.remove("seat", primaryKey, pkValue);
    return ok && dh.endTransaction(ok);
}
