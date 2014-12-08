#ifndef HALLMODEL_H
#define HALLMODEL_H

#include "basemodel.h"
#include <QPoint>

class HallModel : public BaseModel
{
public:
    HallModel(QObject *parent = 0);

    enum Column {
        HallID = 0,
        Name = 1,
        ScreenSize = 2,
        SoundSystem = 3,
        Seats = 4,
        Rows = 5,
        Cols = 6
    };

    int insertHall(const QString &name, const QString &screenSize, const QString &SoundSystem,
               const QList<QList<bool> > &seats);
    bool editHall(int row, const QString &name, const QString &screenSize, const QString &SoundSystem,
                    const QList<QList<bool> > &seats = QList<QList<bool> >());

    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }
    QString getName(int row) const { return data(index(row, Name)).toString(); }
    QString getScreenSize(int row) const { return data(index(row, ScreenSize)).toString(); }
    QString getSoundSystem(int row) const { return data(index(row, SoundSystem)).toString(); }
    int getSeats(int row) const { return data(index(row, Seats)).toInt(); }
    int getRows(int row) const { return data(index(row, Rows)).toInt(); }
    int getColumns(int row) const { return data(index(row, Cols)).toInt(); }

protected:
    virtual bool remove(const QVariant &pkValue);

private:
    int insertSeats(int hallID, const QList<QList<bool> > &seats);
    //int insertSeat(int hallID, int row, int col, bool seatType, int seatNr);
    bool editSeats(int row, const QList<QList<bool> > &seats);
    //bool editSeat(int row, int r, int c, int seatNr);
};

#endif // HALLMODEL_H
