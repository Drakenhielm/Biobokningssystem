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
    explicit hall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem,
                  const QVector<QVector<int> > &seats, QWidget *parent = 0);
    ~hall();

signals:
    void addHall(const QString &name, const QString &screenSize, const QString &soundSystem,
               const QList<QList<bool> > &seats);
    void editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem,
               const QList<QList<bool> > &seats);

private slots:
    void setLabelNumberOfSeats();

    void on_AddButton_clicked();

    void on_cancel_Button_clicked();

private:
    Ui::hall *ui;
    HallView *hallView;

    enum Role { Add, Edit } role;
    int hallID; //used in edit mode

    void initConnections();
    void initHallView();
    QPoint getScreenSizeFromString(const QString &str);
};

#endif // POPUP_H
