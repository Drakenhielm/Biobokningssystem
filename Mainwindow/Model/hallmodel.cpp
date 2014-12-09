#include "hallmodel.h"

HallModel::HallModel(QObject *parent)
    : BaseModel("hall", "HallID", parent)
{
    setQuery(QString("SELECT hall.*, COUNT(seat.SeatNr) AS Seats, "
                     "MAX(seat.Row) AS Rows, MAX(seat.Column) AS Columns "
                     "FROM hall "
                     "LEFT JOIN seat ON seat.HallID = hall.HallID "
                     "GROUP BY hall.HallID"));
}

int HallModel::insertHall(const QString &name, const QString &screenSize, const QString &soundSystem,
           const QList<QList<bool> > &seats)
{
    QMap<QString, QVariant> values;
    dh.transaction();
    values.insert(QString("Name"), name);
    values.insert(QString("ScreenSize"), screenSize);
    values.insert(QString("SoundSystem"), soundSystem);
    int id = dh.insert("hall", values);
    int lastSeatID = insertSeats(id, seats) > 0;
    bool ok = id > 0 && lastSeatID > 0;
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}

bool HallModel::editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem,
                          const QList<QList<bool> > &seats)
{
   bool ok = true;
   QMap<QString, QVariant> values;
   if(!seats.isEmpty())
       dh.transaction();

   values.insert(QString("Name"), name);
   values.insert(QString("ScreenSize"), screenSize);
   values.insert(QString("SoundSystem"), soundSystem);
   ok &= dh.edit("hall", values, "HallID", hallID);
   values.clear();

   if(seats.isEmpty())
       return ok;

   ok &= editSeats(hallID, seats);
   return ok && dh.endTransaction(ok);
}

int HallModel::insertSeats(int hallID, const QList<QList<bool> > &seats)
{
    QMap<QString, QVariant> values;
    int seatNr = 1;
    int lastID = -1;
    for(int r = 0; r < seats.size(); r++)
    {
        for(int c = 0; c < seats.at(r).size(); c++)
        {
            values.insert(QString("Row"), r+1);
            values.insert(QString("Column"), c+1);
            if(seats.at(r).at(c))
            {
                values.insert(QString("SeatNr"), seatNr++);
                values.insert(QString("SeatType"), 1);
            }
            else
            {
                values.insert(QString("SeatType"), 0);
            }
            values.insert(QString("HallID"), hallID);

            lastID = dh.insert("seat", values);
            values.clear();

            if(lastID == -1)
                return -1;
        }
    }
    return lastID;
}



bool HallModel::editSeats(int row, const QList<QList<bool> > &seats)
{
    bool ok = true;
    ok &= dh.remove("seat", "HallID", getHallID(row));
    int lastId = insertSeats(getHallID(row), seats);
    ok &= lastId != -1;
    /*QMap<QString, QVariant> values;
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
    }*/
    return ok;
}

/*int HallModel::insertSeat(int hallID, int r, int c, bool seatType, int seatNr)
{
    QMap<QString, QVariant> values;
    values.insert(QString("Row"), r);
    values.insert(QString("Column"), c);
    if(seatType)
    {
        values.insert(QString("SeatNr"), seatNr);
        values.insert(QString("SeatType"), 1);
    }
    else
    {
        values.insert(QString("SeatType"), 0);
    }
    values.insert(QString("HallID"), getHallID(row));

    lastID = dh.insert("seat", values);
    values.clear();

    if(lastID == -1)
        return -1;
}*/

bool HallModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok = ok && dh.remove("hall", "HallID = ?", pkValue);
    ok = ok && dh.remove("booking", "ShowID IN (SELECT ShowID FROM show WHERE HallID = ?)", pkValue);
    ok = ok && dh.remove("seatbooking", "SeatID IN (SELECT SeatID FROM seat WHERE HallID = ?)", pkValue);
    ok = ok && dh.remove("show", "HallID = ?", pkValue);
    ok = ok && dh.remove("seat", "HallID = ?", pkValue);
    return ok && dh.endTransaction(ok);
}
