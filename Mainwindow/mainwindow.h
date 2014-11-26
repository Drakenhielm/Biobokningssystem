#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/moviemodel.h"
#include "Model/showmodel.h"
#include "Model/hallmodel.h"
#include "Model/seatmodel.h"
#include "Model/bookingmodel.h"
#include <QItemSelection>
#include "hallview.h"

#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_pushButton_info_edit_clicked();

    void on_pushButton_movies_add_clicked();

    void on_pushButton_movies_delete_clicked();

    void on_listView_movies_clicked(const QModelIndex &index);

    void on_listView_movies_activated(const QModelIndex &index);

    void on_pushButton_show_add_clicked();

    void on_pushButton_show_delete_clicked();

    void on_pushButton_search_clicked();

    void setHTML();

private:
    Ui::MainWindow *ui;
    HallView *hallView;

    MovieModel *movieModel;
    ShowModel *showModel;
    HallModel *hallModel;
    SeatModel *seatModel;
    BookingModel * bookingModel;
};

#endif // MAINWINDOW_H
