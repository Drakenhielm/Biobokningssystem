#include "hallmodel.h"

HallModel::HallModel(QObject *parent)
    : BaseModel("hall", "HallID", parent)
{
    setQuery(QString("SELECT hall.*, COUNT(SeatID) AS Seats "
                     "FROM hall "
                     "LEFT JOIN seat ON seat.HallID = hall.HallID "
                     "GROUP BY hall.HallID"));
}

int HallModel::insertHall(const QString &name, const QString &screenSize, const QString &soundSystem,
           QList<QList<bool> > seats)
{
    QList<QPair<QString, QVariant> > values;
    dh.transaction();
    values.append(qMakePair(QString("Name"), name));
    values.append(qMakePair(QString("ScreenSize"), screenSize));
    values.append(qMakePair(QString("SoundSystem"), soundSystem));
    int id = dh.insert("hall", values);
    bool ok = true;
    values.clear();
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
                ok = dh.insert("seat", values) != -1;
            values.clear();
        }
    }
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}

bool HallModel::editHall(const QString &name, const QString &screenSize, const QString &soundSystem,
           QList<QList<bool> > seats)
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
                //if(r > )
                ok = dh.insert("seat", values) != -1;
            values.clear();
        }
    }
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}

bool HallModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok &= dh.remove(tableName, primaryKey, pkValue);
    ok &= dh.remove("seat", primaryKey, pkValue);
    return ok && dh.endTransaction(ok);
}
