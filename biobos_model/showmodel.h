#ifndef SHOWMODEL_H
#define SHOWMODEL_H

#include <basemodel.h>

#include <QDebug>
#include <QSqlError>
#include <QPair>

class ShowModel : public BaseModel
{
public:
    enum Column {ShowID = 0, DateTime = 1, Price = 2, ThreeD = 3, Subtitles = 4, Language = 5, MovieID = 6, HallID = 7};

    ShowModel(QObject *parent = 0);

    int insertShow(const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                    int movieID, int hallID);
};

#endif // SHOWMODEL_H
