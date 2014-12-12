#ifndef HALLVIEW_H
#define HALLVIEW_H

#include <QSize>
#include <QWidget>
#include <vector>
#include <QtWidgets>

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
    int getTotalNumberOfSeats();
    int getSeatNr(int rowIndex, int columnIndex);
    void setRows(int rows);
    void setColumns(int columns);
    void setNumberOfSelected(int);
    void setMode(bool); //Set to true if in editmode
    void setSeperateSeats(bool seperate);
    void setHall(QVector<QVector<int>>, int rows, int columns);
    void setEnabled(bool enabled);
    void comfirmSelectedSeats();
    void clearSelectedSeats();
signals:
    void selectedSeatsChanged(QList<int>);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
    bool HallSquare(int, int);
    void loadDefaultSeatValues();
private:
    bool enabled;
    int row_count;
    int column_count;
    int seatSelector;
    int squareSize;
    int spacing;
    int leftOffset;
    int topOffset;
    bool editMode;
    bool seperateSeats;
    int NoSeat = 0;
    int Selected = 1;
    int Available = 2;
    int Booked = 4;
    QPair<int, bool> seats[25][25];
};

#endif
