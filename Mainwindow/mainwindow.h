#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "moviemodel.h"
#include "showmodel.h"
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

private:
    Ui::MainWindow *ui;
    MovieModel *movieModel;
    ShowModel *showModel;
    HallView *hallView;
};

#endif // MAINWINDOW_H
