#ifndef HALL_H
#define HALL_H

#include <QDialog>
#include "hallview.h"

namespace Ui {
class hall;
}

class hall : public QDialog
{
    Q_OBJECT

public:
    explicit hall(QWidget *parent = 0);
    ~hall();


private slots:
    void setLabelNumberOfSeats();

private:
    Ui::hall *ui;
    HallView *hallView;
};

#endif // POPUP_H
