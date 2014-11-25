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

    setMouseTracking(true); //Needed for mouseMoveEvent.
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

    int rowIndex = mouseY/(squareSize+spacing);
    int columnIndex = (mouseX-offset)/(squareSize+spacing);

    int hallViewWidth = column_count*squareSize+spacing*(column_count-1);
    int hallViewHieght = row_count*squareSize+spacing*(column_count-1);

    //qDebug() << "columnIndex: " << columnIndex << "  rowIndex: " << rowIndex << "   mouseX: " << mouseX << "   mouseY: " << mouseY << "  squareSize: " << squareSize << "  offset: " << offset << endl;
    if(mouseX <= hallViewWidth+offset && mouseX >= offset && mouseY <= hallViewHieght){
        if(seats[columnIndex][rowIndex].first == 0)
            seats[columnIndex][rowIndex].first = 1;
        else
            seats[columnIndex][rowIndex].first = 0;
    }
    update(); //Update graphics
}

void HallView::leaveEvent(QEvent * event)
{
    for(auto& rows : seats){
        for(auto& seat : rows){
            seat.second = false;
        }
    }
    update();
    QWidget::leaveEvent(event);
}

void HallView::mouseMoveEvent(QMouseEvent *event)
{
    for(auto& rows : seats){
        for(auto& seat : rows){
            seat.second = false;
        }
    }

    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = mouseY/(squareSize+spacing);
    int columnIndex = (mouseX-offset)/(squareSize+spacing);

    int hallViewWidth = column_count*squareSize+spacing*(column_count-1);
    int hallViewHieght = row_count*squareSize+spacing*(column_count-1);

    if(mouseX <= hallViewWidth+offset && mouseX >= offset && mouseY <= hallViewHieght){
        int seatNr = rowIndex*row_count+columnIndex+1;
        QString toolTipText = "Rad: " + QString::number(rowIndex+1) + " Kolumn: " + QString::number(columnIndex+1) + " Sittplats: " + QString::number(seatNr);
        QToolTip::showText(event->globalPos(), toolTipText);
        seats[columnIndex][rowIndex].second = true;
    }else{
        QToolTip::hideText();
    }
    update();
}

void HallView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::white)); //Background color

    QRect widget = event->rect();
    int widgetHeight = widget.bottom();
    int widgetWidth = widget.right();

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
            if(seats[column][row].first == 0){
                if(seats[column][row].second == false)
                    painter.setBrush(QBrush(QColor(150, 150, 255))); //Bluuuueeee
                else
                    painter.setBrush(QBrush(QColor(100, 100, 200))); //Bluuuueeee
            }else{
                if(seats[column][row].second == false)
                    painter.setBrush(QBrush(QColor(255, 150, 150))); //Reeeeddddd
                else
                    painter.setBrush(QBrush(QColor(200, 100, 100))); //Reeeeddddd
            }
            painter.drawRect(column*(squareSize+spacing)+offset, row*(squareSize+spacing), squareSize, squareSize);
        }
    }
}
