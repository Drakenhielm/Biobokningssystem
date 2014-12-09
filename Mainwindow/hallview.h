#ifndef HALLVIEW_H
#define HALLVIEW_H

#include <QSize>
#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
class QMouseEvent;
class QPaintEvent;
QT_END_NAMESPACE

class HallView : public QWidget
{
    Q_OBJECT

public:
    HallView(QWidget *parent = 0);

public slots:
    QList<int> getSelectedSeats();
    QList<QList<bool>> getSeats();
    //void setSelectedSeats(vector<int> seats);
    void setRows(int rows);
    void setColumns(int columns);
    //void toggleSeats();
    //void setModel(SeatModel, int hallID);
    void setNumberOfSelected(int);
    void setMode(bool);
    void comfirmSelectedSeats();
    void setSeperateSeats(bool seperate);
    int getTotalNumberOfSeats();
    void clearSelectedSeats();
    void setHall(QVector<QVector<int>>, int rows, int columns);
signals:
    void selectedSeatsChanged(QList<int>);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void reSizeSeats();
    bool HallSquare(int, int);
    void loadDefaultSeatValues();
    int getSeatNr(int rowIndex, int columnIndex);
private:
    int row_count;
    int column_count;
    int seatSelector;
    int squareSize;
    int spacing;
    int offset;
    bool editMode;
    bool seperateSeats;
    int NoSeat = 0;
    int Selected = 1;
    int Available = 2;
    int Booked = 4;
    QPair<int, bool> seats[25][25];
};

#endif
