#ifndef ADDSHOWDIALOG_H
#define ADDSHOWDIALOG_H

#include <QDialog>
#include "../Model/moviemodel.h"
#include "../Model/hallmodel.h"

namespace Ui {
class addShowDialog;
}

class addShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addShowDialog(MovieModel *movieModel, HallModel *hallModel, QWidget *parent = 0);
    ~addShowDialog();

private slots:
    void on_addHallButton_clicked();

    void on_cancelHallButton_clicked();

signals:
    void add_Show();

private:
    Ui::addShowDialog *ui;
    MovieModel *movieModel;
    HallModel *hallModel;
};

#endif // ADDSHOWDIALOG_H
