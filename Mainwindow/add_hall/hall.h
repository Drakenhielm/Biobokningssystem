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

signals:
    void addHall(const QString &name, const QString &screenSize, const QString &soundSystem,
               const QList<QList<bool> > &seats);

private slots:
    void setLabelNumberOfSeats();

    void on_AddButton_clicked();

private:
    Ui::hall *ui;
    HallView *hallView;
};

#endif // POPUP_H
