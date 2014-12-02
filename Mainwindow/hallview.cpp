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
    seatSelector = 1;
    editMode = false;
    seperateSeats = false;
    setMouseTracking(true); //Needed for mouseMoveEvent.
}

QList<int> HallView::getSelectedSeats()
{
    QList<int> selectedSeats;
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == 1)
                selectedSeats.push_back(row*row_count+column+1);
        }
    }
    return selectedSeats;
}

void HallView::setSeperateSeats(bool seperate)
{
    seperateSeats = seperate;
}

void HallView::comfirmSelectedSeats()
{
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == 1)
                seats[column][row].first = 2;
         }
    }
    update();
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

void HallView::setNumberOfSelected(int numberOfSeats)
{
    if(numberOfSeats+1 > column_count)
        seatSelector = column_count;
    else
        seatSelector = numberOfSeats+1;
}

void HallView::setMode(bool mode)
{
    editMode = mode;
}

void HallView::mousePressEvent(QMouseEvent *event)
{
    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = mouseY/(squareSize+spacing);
    int columnIndex = (mouseX-offset)/(squareSize+spacing);

    if(HallSquare(mouseX, mouseY)){
        int columnDistance;
        if((columnIndex+(seatSelector-1))>(column_count-1))
            columnDistance = column_count-seatSelector;
        else
            columnDistance = columnIndex;

        int seatMode;
        if(editMode == true)
            seatMode = 3;
        else
            seatMode = 1;

        bool freeSeats = true;
        for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
            if(seats[i][rowIndex].first == 2)
                freeSeats = false;
        }

        if(freeSeats){
            if(!seperateSeats){
                for (int row = 0; row < row_count; ++row) {
                    for (int column = 0; column < column_count; ++column) {
                        if(seats[column][row].first == 1)
                            seats[column][row].first = 0;
                     }
                }
            }

            for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
                if(seats[i][rowIndex].first == 0)
                    seats[i][rowIndex].first = seatMode;
                else
                    seats[i][rowIndex].first = 0;

                emit selectedSeatsChanged(getSelectedSeats());
                update(); //Update graphics
            }
        }
    }
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

    if(HallSquare(mouseX, mouseY)){
        int seatNr = rowIndex*row_count+columnIndex+1;
        QString toolTipText = "Row: " + QString::number(rowIndex+1) + " Column: " + QString::number(columnIndex+1) + " SeatNr: " + QString::number(seatNr);
        QToolTip::showText(event->globalPos(), toolTipText);

        int columnDistance;
        if((columnIndex+(seatSelector-1))>(column_count-1))
            columnDistance = column_count-seatSelector;
        else
            columnDistance = columnIndex;

        for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
            seats[i][rowIndex].second = true;
        }
    }else{
        QToolTip::hideText();
    }
    update();
}

bool HallView::HallSquare(int mouseX, int mouseY)
{
    int hallViewWidth = column_count*squareSize+spacing*(column_count-1);
    int hallViewHieght = row_count*squareSize+spacing*(column_count-1);

    return mouseX <= hallViewWidth+offset && mouseX >= offset && mouseY <= hallViewHieght;
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
            }else if(seats[column][row].first == 1){
                if(seats[column][row].second == false)
                    painter.setBrush(QBrush(QColor(150, 255, 150))); //Greeeennnn
                else
                    painter.setBrush(QBrush(QColor(100, 200, 100))); //Greeeennnn
            }else if(seats[column][row].first == 2){
                if(seats[column][row].second == false)
                    painter.setBrush(QBrush(QColor(255, 150, 150))); //Reeeeddddd
                else
                    painter.setBrush(QBrush(QColor(200, 100, 100))); //Reeeeddddd
            }else{
                if(seats[column][row].second == false)
                    painter.setBrush(QBrush(QColor(255, 255, 255))); //White
                else
                    painter.setBrush(QBrush(QColor(200, 200, 200))); //White
            }

            if(seats[column][row].first != 3 || editMode != false){
                painter.drawRect(column*(squareSize+spacing)+offset, row*(squareSize+spacing), squareSize, squareSize);
                if(seats[column][row].first == 2 && seats[column][row].second == true){
                    painter.setBrush(QBrush(QColor(0, 0, 0))); //black
                    painter.drawLine(column*(squareSize+spacing)+offset, row*(squareSize+spacing), column*(squareSize+spacing)+offset+squareSize, row*(squareSize+spacing)+squareSize);
                    painter.drawLine(column*(squareSize+spacing)+offset, row*(squareSize+spacing)+squareSize, column*(squareSize+spacing)+offset+squareSize, row*(squareSize+spacing));
                }
            }
        }
    }
}
