#include <QtWidgets>
#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    //default values
    row_count = 5;
    column_count = 5;
    spacing = 3;
    offset = 0;

    setMouseTracking(true);
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

void HallView::mousePressEvent(QMouseEvent *event)
{
    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = mouseY/(squareSize+spacing/2);
    int columnIndex = (mouseX-offset)/(squareSize+spacing/2);

    qDebug() << "columnIndex: " << columnIndex << "  rowIndex: " << rowIndex << "   mouseX: " << mouseX << "   mouseY: " << mouseY << "  squareSize: " << squareSize << "  offset: " << offset << endl;
    if(rowIndex <= 25 && columnIndex <= 25 && rowIndex >= 0 && columnIndex >= 0 ){
        if(seats[columnIndex][rowIndex] == 0)
            seats[columnIndex][rowIndex] = 1;
        else
            seats[columnIndex][rowIndex] = 0;
    }
    update(); //Update graphics
}

void HallView::mouseMoveEvent(QMouseEvent *event)
{
    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = mouseY/(squareSize+spacing/2);
    int columnIndex = (mouseX-offset)/(squareSize+spacing/2);

    if(rowIndex <= 25 && columnIndex <= 25 && rowIndex >= 0 && columnIndex >= 0 ){
        int seatNr = rowIndex*row_count+columnIndex+1;
        QString toolTipText = "Rad: " + QString::number(rowIndex+1) + " Kolumn: " + QString::number(columnIndex+1) + " Sittplats: " + QString::number(seatNr);
        QToolTip::showText(event->globalPos(), toolTipText);
    }else{
        QToolTip::hideText();
    }
}

void HallView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::white)); //Background color

    QRect redrawRect = event->rect();
    int widgetHeight = redrawRect.bottom();
    int widgetWidth = redrawRect.right();

    //Calculate the needed size for the seats so that they use as much of the width and height as possible
    if(widgetWidth/column_count > widgetHeight/row_count){
        squareSize = (widgetHeight-((row_count-1)*spacing))/row_count;
        //Add an offset to make the seats align in the center(x-led) of the widget
        offset = (widgetWidth-((squareSize*column_count)+(spacing*(column_count-1))))/2;
    }else{
        squareSize = (widgetWidth-((column_count-1)*spacing))/column_count;
        offset = 0;
    }

    //Paint all the seats
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row] == 0)
                painter.setBrush(QBrush(QColor(150, 150, 255))); //Bluuuueeee
            else
                painter.setBrush(QBrush(QColor(255, 150, 150))); //Reeeeddddd
            painter.drawRect(column*(squareSize+spacing)+offset, row*(squareSize+spacing), squareSize, squareSize);
        }
    }
}
