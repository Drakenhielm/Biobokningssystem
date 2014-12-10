#ifndef EDIT_HALL_H
#define EDIT_HALL_H

#include <QDialog>
#include "hallview.h"
#include "Model/hallmodel.h"
#include "Model/seatmodel.h"
#include <QItemSelection>



namespace Ui {
class edit_hall;
}

class edit_hall : public QDialog
{
    Q_OBJECT

public:
    explicit edit_hall(HallModel *hallModel, QWidget *parent = 0);
    ~edit_hall();


private slots:
    void setLabelNumberOfSeats();
    void hallSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void deleteHall();

    void on_CancelButton_clicked();

private:
    Ui::edit_hall *ui;
    HallView *hallView;
    HallModel *hallModel;
    SeatModel *seatModel;

    int getSelected(const QItemSelection &selection);
    int getSelected(QItemSelectionModel *selectionModel);


};




#endif // POPUP_H
