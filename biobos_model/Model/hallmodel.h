#ifndef HALLMODEL_H
#define HALLMODEL_H

#include "basemodel.h"

class HallModel : public BaseModel
{
public:
    HallModel(QObject *parent = 0);

    enum Column {
        HallID = 0,
        Name = 1,
        ScreenSize = 2,
        SoundSystem = 3,
        Seats = 4
    };

    int insertHall(const QString &name, const QString &screenSize, const QString &SoundSystem,
               int cols, int rows);

    virtual bool remove(const QVariant &pkValue);

    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }
    QString getName(int row) const { return data(index(row, Name)).toString(); }
    QString getScreenSize(int row) const { return data(index(row, ScreenSize)).toString(); }
    QString getSoundSystem(int row) const { return data(index(row, SoundSystem)).toString(); }
    int getSeats(int row) const { return data(index(row, Seats)).toInt(); }
};

#endif // HALLMODEL_H
