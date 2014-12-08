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
signals:
    void selectedSeatsChanged(QList<int>);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void reSizeSeats();
    bool HallSquare(int, int);
private:
    int row_count;
    int column_count;
    int seatSelector;
    int squareSize;
    int spacing;
    int offset;
    bool editMode;
    bool seperateSeats;
    QPair<int, bool> seats[25][25];
};

#endif