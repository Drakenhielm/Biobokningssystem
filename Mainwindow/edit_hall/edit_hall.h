#ifndef EDIT_HALL_H
#define EDIT_HALL_H

#include <QDialog>
#include "hallview.h"
#include "Model/showmodel.h"



namespace Ui {
class edit_hall;
}

class edit_hall : public QDialog
{
    Q_OBJECT

public:
    explicit edit_hall(QWidget *parent = 0);
    ~edit_hall();


private slots:
    void setLabelNumberOfSeats();

private:
    Ui::edit_hall *ui;
    HallView *hallView;
    ShowModel *showModel;
};




#endif // POPUP_H
