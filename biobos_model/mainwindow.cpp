#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpTable();
    movieModel->insertMovie("Flygplan\"", 120, 11, "bla bla", "Familj", 2008, false);
    //movieModel->removeRow(0);
    movieModel->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTable()
{
    movieModel = new MovieModel();
    ui->tableView->setModel(movieModel);
    movieModel->select();
}

void MainWindow::insertValues(int nrOfRows)
{
    /*model->database().transaction();
    int rowCount = model->rowCount();
    qDebug() << rowCount;
    if(!model->insertRows(rowCount, nrOfRows)) {
        qDebug() << "insertRows" << model->lastError().text();
        return;
    }

    for(int i = 0; i < nrOfRows; i++)
    {
        model->setData(model->index(rowCount+i,0), rowCount+i);
        model->setData(model->index(rowCount+i,1), "Star Wars: Episode VII - The Force Awakens");
        model->setData(model->index(rowCount+i,2), 127);
        model->setData(model->index(rowCount+i,3), 11);
        model->setData(model->index(rowCount+i,4), "Bla bla");
        model->setData(model->index(rowCount+i,5), "Sci-Fi");
        model->setData(model->index(rowCount+i,6), 2015);
    }

    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        qDebug() << "Database Write Error" <<
            "The database reported an error: " <<
            model->lastError().text();
    }*/
}

void MainWindow::deleteValues(int startRow, int nrOfRows)
{
    /*model->database().transaction();
    if(!movieModel->removeRows(startRow, nrOfRows)) {
        qDebug() << "removeRows" << movieModel->lastError().text();
        return;
    }

    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        qDebug() << "Database Delete Error" <<
            "The database reported an error: " <<
            model->lastError().text();
    }*/
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    //model->setFilter("MovieID = 3");
}
