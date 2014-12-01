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
           int cols, int rows)
{
    QList<QPair<QString, QVariant> > values;
    dh.transaction();
    values.append(qMakePair(QString("Name"), name));
    values.append(qMakePair(QString("ScreenSize"), screenSize));
    values.append(qMakePair(QString("SoundSystem"), soundSystem));
    int id = dh.insert("hall", values);
    bool ok = true;
    values.clear();
    for(int r = 1; r <= rows; r++)
    {
        for(int c = 1; c <= cols; c++)
        {
            values.append(qMakePair(QString("Row"), r));
            values.append(qMakePair(QString("Column"), c));
            values.append(qMakePair(QString("SeatNr"), c+(r-1)*cols));
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
