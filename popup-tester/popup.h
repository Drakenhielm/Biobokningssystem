#ifndef POPUP_H
#define POPUP_H

#include <QDialog>

namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = 0);
    ~popup();


private slots:
    void on_AddGenreButton_clicked();

    void updateCurrentGenre(QString);

    void on_CancelButton_clicked();

    void on_RemoveGenreButton_clicked();

private:
    Ui::popup *ui;
};

#endif // POPUP_H
