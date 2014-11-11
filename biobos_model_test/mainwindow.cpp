#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpTable();
    insertValues(5);
    //deleteValues(0, 2);
    ui->tableView->hideColumn(0);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::setUpTable()
{
    model = new QSqlRelationalTableModel;
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("movie");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::insertValues(int nrOfRows)
{
    model->database().transaction();
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
    }
}

void MainWindow::deleteValues(int startRow, int nrOfRows)
{
    model->database().transaction();
    if(!model->removeRows(startRow, nrOfRows)) {
        qDebug() << "removeRows" << model->lastError().text();
        return;
    }

    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        qDebug() << "Database Delete Error" <<
            "The database reported an error: " <<
            model->lastError().text();
    }
}
