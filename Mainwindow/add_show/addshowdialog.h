#ifndef ADDSHOWDIALOG_H
#define ADDSHOWDIALOG_H

#include <QDialog>

namespace Ui {
class addShowDialog;
}

class addShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addShowDialog(QWidget *parent = 0);
    ~addShowDialog();

private slots:
    void on_addHallButton_clicked();

    void on_cancelHallButton_clicked();

signals:
    void add_Show();

private:
    Ui::addShowDialog *ui;
};

#endif // ADDSHOWDIALOG_H
