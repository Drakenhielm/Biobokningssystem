#ifndef HALL_LIST_H
#define HALL_LIST_H

#include <QDialog>
#include "hallview.h"
#include "Model/hallmodel.h"
#include "Model/seatmodel.h"
#include "Model/showmodel.h"
#include <QItemSelection>
#include <add_hall/hall.h>



namespace Ui {
class hall_list;
}

class hall_list : public QDialog
{
    Q_OBJECT

public:
    explicit hall_list(HallModel *hallModel, QWidget *parent = 0);
    ~hall_list();


private slots:
    void setLabelNumberOfSeats();
    void hallSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void deleteHall();
    void openEditHallDialogue();
    void editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem, const QList<QList<bool> > &seats);

    void on_CloseButton_clicked();

private:
    Ui::hall_list *ui;
    HallView *hallView;
    HallModel *hallModel;
    SeatModel *seatModel;

    int getSelected(const QItemSelection &selection);
    int getSelected(QItemSelectionModel *selectionModel);


};




#endif // HALL_LIST_H
