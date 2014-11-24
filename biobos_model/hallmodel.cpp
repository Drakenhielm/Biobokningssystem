#include "hallmodel.h"

HallModel::HallModel(QObject *parent)
    : BaseModel("hall", parent)
{
    setQuery(QString("SELECT *, COUNT(SeatID) FROM hall "
                     "LEFT JOIN seat ON seat.HallID = hall.HallID "
                     "GROUP BY HallID"));
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
    bool ok;
    values.clear();
    for(int r = 1; r <= rows; r++)
    {
        for(int c = 1; c <= cols; c++)
        {
            values.append(qMakePair(QString("Row"), r));
            values.append(qMakePair(QString("Column"), c));
            values.append(qMakePair(QString("SeatNr"), c+(r-1)*cols));
            values.append(qMakePair(QString("HallID"), id));
            ok = dh.insert("seat", values) > 0;
            values.clear();
        }
    }
    dh.endTransaction(ok);
    if(ok)
        return id;
    else
        return -1;
}