#ifndef HALLVIEW_H
#define HALLVIEW_H

#include <QSize>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QMouseEvent;
class QPaintEvent;
QT_END_NAMESPACE

class HallView : public QWidget
{
    Q_OBJECT

public:
    HallView(QWidget *parent = 0);
    //QSize sizeHint() const;

public slots:
    //vector<int>getSelectedSeats();
    //void setSelectedSeats(vector<int> seats);
    void setRows(int rows);
    void setColumns(int columns);
    //void toggleSeats();
    //void setModel();

signals:
    void characterSelected(const QString &character);

protected:
    //void mouseMoveEvent(QMouseEvent *event);
    //void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void reSizeSeats();
private:
    int row_count;
    int column_count;
    int squareSize;
};

#endif
