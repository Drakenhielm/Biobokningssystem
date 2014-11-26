#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtSql>
#include <QElapsedTimer>

#include "Model/moviemodel.h"
#include "Model/showmodel.h"
#include "Model/hallmodel.h"
#include "Model/seatmodel.h"
#include "Model/bookingmodel.h"

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_pressed(const QModelIndex &index);

    void on_tableView_viewportEntered();

private:
    Ui::MainWindow *ui;
    MovieModel *movieModel;
    ShowModel *showModel;
    HallModel *hallModel;
    SeatModel *seatModel;
    BookingModel *bookingModel;

    QSqlRelationalTableModel *model;
    QSqlQueryModel *qModel;
    void setUpTable();
    void insertValues(int nrOfRows);
    void deleteValues(int startRow, int nrOfRows);
};

#endif // MAINWINDOW_H
