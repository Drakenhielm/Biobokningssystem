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
    /*QList<QPair<QString, QVariant> > values;
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
    else*/
        return -1;
}

int HallModel::insertSeats(int hallID, const QList<QList<bool> > &seats, int firstSeatNr, QPoint offset)
{
    QList<QPair<QString, QVariant> > values;
    int seatNr = firstSeatNr;
    int lastID = -1;
    /*for(int r = 0; r < seats.size(); r++)
    {
        for(int c = 0; c < seats.at(r).size(); c++)
        {
            values.append(qMakePair(QString("Row"), r+offset.y()+1));
            values.append(qMakePair(QString("Column"), c+offset.x()+1));
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
    }*/
    return lastID;
}

bool HallModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok &= dh.remove(tableName, primaryKey, pkValue);
    ok &= dh.remove("seat", primaryKey, pkValue);
    return ok && dh.endTransaction(ok);
}

/*bool HallModel::editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem,
           const QList<QList<bool> > &seats)
{
    bool ok = true;
    QList<QPair<QString, QVariant> > values;
    if(!seats.isEmpty())
        dh.transaction();

    values.append(qMakePair(QString("Name"), name));
    values.append(qMakePair(QString("ScreenSize"), screenSize));
    values.append(qMakePair(QString("SoundSystem"), soundSystem));
    ok &= dh.edit("hall", values, "HallID", hallID);
    values.clear();

    if(seats.isEmpty())
        return ok;

    ok &= editSeats(hallID, seats);
    return ok && dh.endTransaction(ok);
}



bool HallModel::editSeats(int row, const QList<QList<bool> > &seats)
{
    QList<QPair<QString, QVariant> > values;
    if(seats.size() < getRows(row))
        dh.remove("seatbooking", "HallID = ? AND Row > ?", seats.size());

    int seatNr = 1;
    int lastId;
    bool ok = true;
    for(int r = 0; r < seats.size(); r++)
    {
        for(int c = 0; c < seats.at(r).size(); c++)
        {
            if(r > getRows(row) || c > getColumns(row))
            {
                lastId = insertSeat(getHallID(row), r+1, c+1, seats.at(r).at(c) ? seatNr++ : -1);
            }
            else
            {
                lastId = editSeat(getHallID(row), r+1, c+1, seats.at(r).at(c) ? seatNr++ : -1);
            }

            if(lastId == -1)
                ok = false;
        }
    }
    return ok;
}

int HallModel::insertSeat(int hallID, int r, int c, bool seatType, int seatNr)
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
    values.append(qMakePair(QString("HallID"), getHallID(row)));

    lastID = dh.insert("seat", values);
    values.clear();

    if(lastID == -1)
        return -1;
}*/

bool editSeats(int row, const QList<QList<bool> > &seats,
              int startSeatNr = 1, QPoint offset = QPoint());
bool editSeat(int row, int r, int c, int seatNr);
