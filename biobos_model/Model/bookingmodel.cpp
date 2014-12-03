#include "bookingmodel.h"

BookingModel::BookingModel(QObject *parent)
    : BaseModel("booking", "BookingID", parent)
{
    setQuery("SELECT b.BookingID, b.ShowID, s.MovieID, b.Phone, m.Title, s.DateTime, "
             "COUNT(b.BookingID) AS Tickets, GROUP_CONCAT(sb.SeatID) AS SeatIDs "
             "FROM booking AS b "
             "LEFT JOIN movie AS m ON m.MovieID = b.ShowID "
             "LEFT JOIN show AS s ON s.ShowID = b.ShowID "
             "LEFT JOIN seatbooking AS sb ON sb.BookingID = b.BookingID "
             "GROUP BY b.BookingID "
             "ORDER BY b.BookingID DESC");
}

QList<int> BookingModel::getSeatIDs(int row) const
{
    QList<int> list;
    QStringList strList = data(index(row, SeatIDs)).toString().split(',');
    for(int i = 0; i < strList.size(); i++)
    {
        list.append(strList.at(i).toInt());
    }
    return list;
}

int BookingModel::insertBookings(int showID, const QList<int> &seatIDs, const QString &phone)
{
    QList<QPair<QString, QVariant> > values;
    int id;
    bool ok;

    dh.transaction();
    //insert booking
    values.append(qMakePair(QString("ShowID"), showID));
    values.append(qMakePair(QString("Phone"), phone));
    id = dh.insert("booking", values);
    ok = (id != -1);
    values.clear();
    //insert seatbookings
    insertSeatBookings(id, seatIDs);
    dh.endTransaction(ok);

    return id; //BookingID
}

bool BookingModel::remove(const QVariant &pkValue)
{
    bool ok = true;
    dh.transaction();
    ok &= dh.remove(tableName, "BookingID", pkValue);
    ok &= dh.remove("seatbooking", "BookingID", pkValue);
    return ok && dh.endTransaction(ok);;
}

bool BookingModel::editBookings(int bookingID, int showID, const QList<int> &seatIDs, const QString &phone)
{
    QList<QPair<QString, QVariant> > values;
    bool ok = true;

    dh.transaction();
    //edit booking
    values.append(qMakePair(QString("ShowID"), showID));
    values.append(qMakePair(QString("Phone"), phone));
    ok &= dh.edit("booking", values, "BookingID", bookingID);
    values.clear();

    //remove old and insert new seatbookings
    dh.remove("seatbooking", "BookingID", bookingID);
    insertSeatBookings(bookingID, seatIDs);

    dh.endTransaction(ok);
    return ok;
}

bool BookingModel::insertSeatBookings(int bookingID, const QList<int> &seatIDs)
{
    QList<QPair<QString, QVariant> > values;
    bool ok = true;
    for(int i = 0; i < seatIDs.size(); i++)
    {
        values.append(qMakePair(QString("BookingID"), bookingID));
        values.append(qMakePair(QString("SeatID"), seatIDs.at(i)));
        ok &= dh.insert("seatbooking", values);
        values.clear();
    }
    return ok;
}
