#ifndef HALLMODEL_H
#define HALLMODEL_H

#include <basemodel.h>

class HallModel : public BaseModel
{
public:
    HallModel(QObject *parent = 0);

    int insertHall(const QString &name, const QString &screenSize, const QString &SoundSystem,
               int cols, int rows);
};

#endif // HALLMODEL_H
