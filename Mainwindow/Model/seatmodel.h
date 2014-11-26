#ifndef SEATMODEL_H
#define SEATMODEL_H

#include <QDebug>
#include "basemodel.h"

class SeatModel : public BaseModel
{
public:
    SeatModel(QObject *parent = 0);

    enum Column
    {
        ShowID = 0,
        MovieID = 1,
        Phone = 2,
        Title = 3,
        Tickets = 4
    };

    //virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    //virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    //virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole);
    virtual void refresh();

    int getShowID(int row) const { return data(index(row, ShowID)).toInt(); }
    int getMovieID(int row) const { return data(index(row, MovieID)).toInt(); }
    QString getPhone(int row) const { return data(index(row, Phone)).toString(); }
    QString getTitle(int row) const { return data(index(row, Title)).toString(); }
    int getTickets(int row) const { return data(index(row, Tickets)).toInt(); }

    void setHall(int id);
    void setShow(int id);
    void setBooking(const QString &phone);

private:
    int hallID;
    int showID;
    QString bookingPhoneNr;

    void fixQuery();

};

#endif // SEATMODEL_H
