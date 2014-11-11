#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpTable();
    //deleteValues(10);
    //insertValues(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTable()
{
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("movie");
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
        model->setData(model->index(rowCount+i,0), rowCount+i);

    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        qDebug() << "Database Write Error" <<
            "The database reported an error: " <<
            model->lastError().text();
    }
}

void MainWindow::deleteValues(int nrOfRows)
{

}
