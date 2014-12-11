#ifndef ADDSHOWDIALOG_H
#define ADDSHOWDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "../Model/moviemodel.h"
#include "../Model/hallmodel.h"

namespace Ui {
class addShowDialog;
}

class addShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addShowDialog(MovieModel *movieModel, HallModel *hallModel, int selMovieIndex = 0, QWidget *parent = 0);
    explicit addShowDialog(MovieModel *movieModel, HallModel *hallModel, int showID, QDateTime dateTime, double price,
                           QString lang, bool DDD, bool subs, int movieID, int hallID, QWidget *parent = 0);
    ~addShowDialog();

private slots:
    void on_addShowButton_clicked();

    void on_cancelShowButton_clicked();

signals:
    void add_Show(QDateTime datetime, double price, QString lang, bool DDD, bool subs, int movieID, int hallID);

    void edit_show(int showID, QDateTime dateTime, double price, QString lang, bool DDD, bool subs, int movieID, int hallID);

private:
    Ui::addShowDialog *ui;
    MovieModel *movieModel;
    HallModel *hallModel;

    enum Role { Add, Edit } role;
    int showID; //used in edit mode

    void initViews(int movieIndex, int hallIndex);
    void initComboBoxes(int movieIndex = 0, int hallIndex = 0);
};

#endif // ADDSHOWDIALOG_H
