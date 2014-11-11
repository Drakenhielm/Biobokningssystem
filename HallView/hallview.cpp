#include <QtWidgets>
#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize( 400, 400 );
    setMaximumSize( 400, 400 );

    row_count = 5;
    column_count = 5;
    squareLenght = 20;
    squareHeight = 16;
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
    update();
}

void HallView::setRows(int rows)
{
    row_count = rows;
    update();
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
    painter.setPen(QPen(Qt::black));
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {

            painter.drawRect(column*squareLenght + column*column_spacing + (maximumSize().width()/2-((squareLenght+column_spacing)*column_count)/2), row*squareHeight + row*row_spacing, squareLenght, squareHeight);
            //painter.drawRect(column*squareSize, row*squareSize, squareSize, squareSize);
        }
    }
}
