#include <QtWidgets>
#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize( 400, 400 );
    setMaximumSize( 400, 400 );

    row_count = 5;
    column_count = 5;
    squareSize = 20;
    //setMouseTracking(true);
}

/*
QSize HallView::sizeHint() const
{
    return QSize(column_count*squareSize +1, (60/column_count)*squareSize);
}
*/

void HallView::setColumns(int columns)
{
    column_count = columns;
    reSizeSeats();
    update();
}

void HallView::setRows(int rows)
{
    row_count = rows;
    reSizeSeats();
    update();
}

void HallView::reSizeSeats()
{
    if(row_count >= 16 || column_count >= 16)
    {
        if(row_count > column_count)
            squareSize = 20 - (row_count - 15);
        else
            squareSize = 20 - (column_count - 15);
    }else
    {
        squareSize = 20;
    }
}

void HallView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.fillRect(event->rect(), QBrush(Qt::white));

    /*
    QRect redrawRect = event->rect();
    int beginRow = redrawRect.top()/squareSize;S
    int endRow = redrawRect.bottom()/squareSize;
    int beginColumn = redrawRect.left()/squareSize;
    int endColumn = redrawRect.right()/squareSize;
    */
    int row_spacing = 5;
    int column_spacing = 5;
    painter.setBrush(QBrush(QColor(150, 150, 255)));
    //painter.setPen(QPen(Qt::red));
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {

            painter.drawRect(column*squareSize + column*column_spacing + (maximumSize().width()/2-((squareSize+column_spacing)*column_count)/2), row*squareSize + row*row_spacing, squareSize, squareSize);
            //painter.drawRect(column*squareSize, row*squareSize, squareSize, squareSize);
        }
    }
}
