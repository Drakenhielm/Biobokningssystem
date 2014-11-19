#include <QtWidgets>
#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    //default values
    row_count = 5;
    column_count = 5;
    //setMouseTracking(true);
}

void HallView::setColumns(int columns)
{
    column_count = columns;
    update(); //Update graphics
}

void HallView::setRows(int rows)
{
    row_count = rows;
    update(); //Update graphics
}

void HallView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::white));

    QRect redrawRect = event->rect();
    int widgetHeight = redrawRect.bottom();
    int widgetWidth = redrawRect.right();

    int squareSize;
    int spacing = 3;
    int offset = 0;
    //Calculate the needed size for the seats so that they use as much of the width and height as possible
    if(widgetWidth/column_count > widgetHeight/row_count){
        squareSize = (widgetHeight-((row_count-1)*spacing))/row_count;
        //Add an offset to make the seats align in the center of the widget
        offset = (widgetWidth-((squareSize*column_count)+(spacing*(column_count-1))))/2;
    }else{
        squareSize = (widgetWidth-((column_count-1)*spacing))/column_count;
    }

    //Paint all the seats
    painter.setBrush(QBrush(QColor(150, 150, 255)));
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            painter.drawRect(column*(squareSize+spacing)+offset, row*(squareSize+spacing), squareSize, squareSize);
        }
    }
}
