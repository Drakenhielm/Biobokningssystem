#ifndef SEATMODEL_H
#define SEATMODEL_H

#include <QDebug>
#include "basemodel.h"

class SeatModel : public BaseModel
{
public:
    SeatModel(QObject *parent = 0);

    //virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    //virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
    //virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole);
    virtual void refresh();

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
