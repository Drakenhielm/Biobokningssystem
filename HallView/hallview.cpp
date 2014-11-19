#include <QtWidgets>
#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    row_count = 5;
    column_count = 5;
    //setMouseTracking(true);
}

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

     QRect redrawRect = event->rect();
    int widgetHeight = redrawRect.bottom();
    int widgetWidth = redrawRect.right();
    int squareSize;
    int spacing = 3;
    if(widgetWidth/column_count > widgetHeight/row_count){
        squareSize = (widgetHeight-((row_count-1)*spacing))/row_count;
    }else{
        squareSize = (widgetWidth-((column_count-1)*spacing))/column_count;
    }

    painter.setBrush(QBrush(QColor(150, 150, 255)));
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            painter.drawRect(column*(squareSize+spacing), row*(squareSize+spacing), squareSize, squareSize);
        }
    }
}
