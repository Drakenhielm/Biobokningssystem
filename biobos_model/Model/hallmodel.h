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
    /*bool editHall(int row, const QString &name, const QString &screenSize, const QString &SoundSystem,
                    const QList<QList<bool> > &seats = QList<QList<bool> >());*/

    virtual bool remove(const QVariant &pkValue);

    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }
    QString getName(int row) const { return data(index(row, Name)).toString(); }
    QString getScreenSize(int row) const { return data(index(row, ScreenSize)).toString(); }
    QString getSoundSystem(int row) const { return data(index(row, SoundSystem)).toString(); }
    int getSeats(int row) const { return data(index(row, Seats)).toInt(); }
    int getRows(int row) const { return data(index(row, Rows)).toInt(); }
    int getColumns(int row) const { return data(index(row, Cols)).toInt(); }

private:
    int insertSeats(int row, const QList<QList<bool> > &seats, int startSeatNr = 1);
    /*int editSeats(int row, const QList<QList<bool> > &seats,
                  int startSeatNr = 1, QPoint offset = QPoint());*/
};

#endif // HALLMODEL_H