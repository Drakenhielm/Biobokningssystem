#ifndef SHOWMODEL_H
#define SHOWMODEL_H

#include "basemodel.h"

#include <QDebug>
#include <QSqlError>
#include <QPair>

class ShowModel : public BaseModel
{
public:
    enum Column
    {
        ShowID = 0,
        DateTime = 1,
        Price = 2,
        ThreeD = 3,
        Subtitles = 4,
        Language = 5,
        MovieID = 6,
        HallID = 7,
        Hall = 8,
        AvailableSeats = 9
    };

    ShowModel(QObject *parent = 0);

    //reimplemented functions
    virtual QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const;

    int insertShow(const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                    int movieID, int hallID);
    bool editShow(int showID, const QDateTime &dateTime, float price, bool threeD, bool subtitles, const QString &language,
                    int movieID, int hallID);

    int getShowID(int row) const { return data(index(row, ShowID)).toInt(); }
    QDateTime getDateTime(int row) const { return data(index(row, DateTime)).toDateTime(); }
    float getPrice(int row) const { return data(index(row, Price)).toFloat(); }
    bool get3D(int row) const { return data(index(row, ThreeD)).toBool(); }
    bool getSubtitles(int row) const { return data(index(row, Subtitles)).toBool(); }
    QString getLanguage(int row) const { return data(index(row, Language)).toString(); }
    int getMovieID(int row) const { return data(index(row, MovieID)).toInt(); }
    int getHallID(int row) const { return data(index(row, HallID)).toInt(); }
    QString getHall(int row) const { return data(index(row, Hall)).toString(); }
    int getAvailableSeats(int row) const { return data(index(row, AvailableSeats)).toInt(); }

};

#endif // SHOWMODEL_H
