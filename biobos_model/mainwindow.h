#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtSql>
#include <QElapsedTimer>

#include <moviemodel.h>
#include <showmodel.h>

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
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    MovieModel *movieModel;
    ShowModel *showModel;
    QSqlQueryModel *model;
    void setUpTable();
    void insertValues(int nrOfRows);
    void deleteValues(int startRow, int nrOfRows);

};

#endif // MAINWINDOW_H
