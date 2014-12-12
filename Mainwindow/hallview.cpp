#include "hallview.h"

HallView::HallView(QWidget *parent)
    : QWidget(parent)
{
    //default values
    row_count = 0;
    column_count = 0;
    spacing = 3;
    leftOffset = 0;
    seatSelector = 1;
    editMode = false;
    seperateSeats = false;
    enabled = true;
    setMouseTracking(true); //Needed for mouseMoveEvent.
    loadDefaultSeatValues();
}

//public slots:
QList<int> HallView::getSelectedSeats()
{
    QList<int> selectedSeats;
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == Selected)
                selectedSeats.push_back(getSeatNr(row, column));
        }
    }
    return selectedSeats;
}

QList<QList<bool>> HallView::getSeats()
{
    QList<QList<bool>> hall;
    for (int row = 0; row < row_count; ++row) {
        QList<bool> seatsRow;
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == Available)
                seatsRow.push_back(true);
            else
                seatsRow.push_back(false);
        }
        hall.push_back(seatsRow);
    }
    return hall;
}

int HallView::getTotalNumberOfSeats()
{
    int numberOfSeats = 0;

    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first != NoSeat)
                numberOfSeats++;
         }
    }
    return numberOfSeats;
}

int HallView::getSeatNr(int rowIndex, int columnIndex)
{
    int seatNr = 1;
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(row == rowIndex && column == columnIndex)
                return seatNr;
            else if(seats[column][row].first != NoSeat)
                seatNr++;
        }
    }
    return -1;
}

void HallView::setRows(int rows)
{
    row_count = rows;
    update(); //Update graphics
}

void HallView::setColumns(int columns)
{
    column_count = columns;
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

void HallView::setSeperateSeats(bool seperate)
{
    seperateSeats = seperate;
    clearSelectedSeats();
}

void HallView::setHall(QVector<QVector<int>> hall, int rows, int columns)
{
    setRows(rows);
    setColumns(columns);

    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column)
            seats[column][row].first = hall.at(row).at(column);
    }
}

void HallView::setEnabled(bool enabled)
{
    this->enabled = enabled;
}

void HallView::comfirmSelectedSeats()
{
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == Selected)
                seats[column][row].first = Booked;
         }
    }
    update();
}

void HallView::clearSelectedSeats()
{
    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) {
            if(seats[column][row].first == Selected)
                seats[column][row].first = Available;
         }
    }
    update();
}

//protected:

void HallView::mousePressEvent(QMouseEvent *event)
{
    if(!enabled)
        return;

    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = (mouseY-topOffset)/(squareSize+spacing);
    int columnIndex = (mouseX-leftOffset)/(squareSize+spacing);

    if(HallSquare(mouseX, mouseY)){
        int columnDistance;
        if((columnIndex+(seatSelector-1))>(column_count-1))
            columnDistance = column_count-seatSelector;
        else
            columnDistance = columnIndex;

        int seatMode;
        if(editMode == true)
            seatMode = NoSeat;
        else
            seatMode = Selected;

        bool freeSeats = true;
        for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
            if(seats[i][rowIndex].first == Booked || (seats[i][rowIndex].first == NoSeat && !editMode))
                freeSeats = false;
        }

        if(freeSeats){
            if(!seperateSeats){
                for (int row = 0; row < row_count; ++row) {
                    for (int column = 0; column < column_count; ++column) {
                        if(seats[column][row].first == Selected)
                            seats[column][row].first = Available;
                     }
                }
            }

            for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
                if(seats[i][rowIndex].first == Available)
                    seats[i][rowIndex].first = seatMode;
                else
                    seats[i][rowIndex].first = Available;

                update(); //Update graphics
            }
        }
    }
}

void HallView::mouseMoveEvent(QMouseEvent *event)
{
    if(!enabled)
        return;

    //Remove highlight from seats
    for(auto& rows : seats){
        for(auto& seat : rows){
            seat.second = false;
        }
    }

    int mouseX = event->x();
    int mouseY = event->y();

    int rowIndex = (mouseY-topOffset)/(squareSize+spacing);
    int columnIndex = (mouseX-leftOffset)/(squareSize+spacing);

    if(HallSquare(mouseX, mouseY)){
        int seatNr = getSeatNr(rowIndex, columnIndex);
        QString toolTipText = "Row: " + QString::number(rowIndex+1) + " Column: " + QString::number(columnIndex+1) + " Seat: " + QString::number(seatNr);

        if(seats[columnIndex][rowIndex].first != NoSeat)
            QToolTip::showText(event->globalPos(), toolTipText);
        else
            QToolTip::hideText();

        int columnDistance;
        if((columnIndex+(seatSelector-1))>(column_count-1))
            columnDistance = column_count-seatSelector;
        else
            columnDistance = columnIndex;

        if(seats[columnIndex][rowIndex].first != NoSeat)
            for(int i = columnDistance; i < (columnDistance+seatSelector); ++i){
                seats[i][rowIndex].second = true;
            }

    }else{
        QToolTip::hideText();
    }
    update();
}

void HallView::leaveEvent(QEvent * event)
{
    if(!enabled)
        return;

    //Remove highlight from seats
    for(auto& rows : seats){
        for(auto& seat : rows){
            seat.second = false;
        }
    }
    update();
    QWidget::leaveEvent(event);
}

void HallView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::white)); //Background color

        //Get the size of the widget
        QRect widget = event->rect();
        int widgetHeight = widget.bottom();
        int widgetWidth = widget.right();

        //Add a topOffset so a screen will fit in the front of the hall
        topOffset = widgetHeight/10;

        //Calculate the needed size for the seats so that they use as much of the width and height as possible
        if(row_count > 0 && column_count > 0){
            if(widgetWidth/column_count > (widgetHeight-topOffset)/row_count){
                squareSize = ((widgetHeight-topOffset)-((row_count-1)*spacing))/row_count;
                //Add an offset to make the seats align in the center(x-led) of the widget
                leftOffset = (widgetWidth-((squareSize*column_count)+(spacing*(column_count-1))))/2;
            }else{
                squareSize = (widgetWidth-((column_count-1)*spacing))/column_count;
                leftOffset = (widgetWidth-((squareSize*column_count)+(spacing*(column_count-1))))/2;;
            }
        }
        //Paint all the seats
        for (int row = 0; row < row_count; ++row) {
            for (int column = 0; column < column_count; ++column) {
                if(seats[column][row].first == Available){
                    if(seats[column][row].second == false)
                        painter.setBrush(QBrush(QColor(150, 150, 255))); //Bluuuueeee
                    else
                        painter.setBrush(QBrush(QColor(100, 100, 200))); //Bluuuueeee
                }else if(seats[column][row].first == Selected){
                    if(seats[column][row].second == false)
                        painter.setBrush(QBrush(QColor(150, 255, 150))); //Greeeennnn
                    else
                        painter.setBrush(QBrush(QColor(100, 200, 100))); //Greeeennnn
                }else if(seats[column][row].first == Booked){
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

                //Do not paint a square if seat is a NoSeat and editMode is false
                if(seats[column][row].first != NoSeat || editMode != false)
                    painter.drawRect(column*(squareSize+spacing)+leftOffset, row*(squareSize+spacing)+topOffset, squareSize, squareSize);

                //Paint a cross if a selected seat is Booked or NoSeat
                if((seats[column][row].first == Booked && seats[column][row].second == true) || (seats[column][row].first == NoSeat && seats[column][row].second == true)){
                    painter.setBrush(QBrush(QColor(0, 0, 0))); //black
                    painter.drawLine(column*(squareSize+spacing)+leftOffset, row*(squareSize+spacing)+topOffset, column*(squareSize+spacing)+leftOffset+squareSize, row*(squareSize+spacing)+squareSize+topOffset);
                    painter.drawLine(column*(squareSize+spacing)+leftOffset, row*(squareSize+spacing)+squareSize+1+topOffset, column*(squareSize+spacing)+leftOffset+squareSize, row*(squareSize+spacing)+1+topOffset);
                }
            }
        }

    if(row_count > 0 && column_count > 0){
        //Paint a screen in the front of the hall
        painter.setBrush(QBrush(QColor(200, 200, 200)));
        int screenWidth = (widgetWidth/10)*6;
        int screenHeight = topOffset-topOffset/3;
        painter.drawRect((widgetWidth-screenWidth)/2, 0, screenWidth, screenHeight);
        painter.setBrush(QBrush(QColor(0, 0, 0))); //black
        painter.drawText ( widgetWidth/2-20, topOffset/2, "Screen");
    }else{
        painter.drawText ( widgetWidth/2-50, widgetHeight/2, "Nothing to display");
    }

    //Emit a signal that a change in the HallView has happened
    emit selectedSeatsChanged(getSelectedSeats());
}

bool HallView::HallSquare(int mouseX, int mouseY)
{
    int hallViewWidth = column_count*squareSize+spacing*(column_count-1);
    int hallViewHieght = row_count*squareSize+spacing*(column_count-1)+topOffset;

    return mouseX <= hallViewWidth+leftOffset && mouseX >= leftOffset && mouseY >= topOffset && mouseY <= hallViewHieght;
}

void HallView::loadDefaultSeatValues()
{
    for (int row = 0; row < 25; ++row) {
        for (int column = 0; column < 25; ++column) {
            seats[column][row].first = Available;
            seats[column][row].second = false;
        }
    }
}
