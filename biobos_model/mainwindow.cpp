#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpTable();
    QElapsedTimer timer;
    timer.start();
    //QSqlDatabase::database().transaction();
    //QSqlQuery query;
    //insertValues(2000);
    //bool ok = true;
        //ok = query.prepare(QString("DELETE FROM %1 WHERE %2 = :val").arg("movie").arg("MovieID"));
        //query.bindValue(":val", 6);
        //qDebug() << query.exec();
        //qDebug() << movieModel->removeRows(257, 300);
        //qDebug() << movieModel->removeRows(0, 256);
    movieModel->sort(1, Qt::AscendingOrder);
    //for(int i = 0; i < 1; i++)
        movieModel->insertMovie("Flygplan\"", 120, 11, "bla bla", "Familj", 2008);
        movieModel->insertMovie("BCD", 120, 11, "bla bla", "Familj", 2008);
        movieModel->insertMovie("Abc", 120, 11, "bla bla", "Familj", 2008);
    movieModel->submitAll(true);
    model->insertRows(0, 3);
    /*if(movieModel->QSqlTableModel::submitAll())
    if(ok && query.exec())
    {
        QSqlDatabase::database().commit();
    }
    else
    {
        QSqlDatabase::database().rollback();
        qDebug() << "The database reported an error: "
                 << QSqlDatabase::database().lastError().text();
    }*/
    qDebug() << timer.elapsed();
    movieModel->select();
    ui->tableView->setModel(movieModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTable()
{
    model = new QSqlQueryModel();
    model->setQuery("select * from movie order by MovieID asc");
    ui->tableView_2->setModel(model);
    movieModel = new MovieModel();
    movieModel->select();
}

void MainWindow::insertValues(int nrOfRows)
{
    movieModel->database().transaction();
    int rowCount = movieModel->rowCount();
    if(!movieModel->QSqlTableModel::insertRows(rowCount, nrOfRows)) {
        qDebug() << "insertRows" << movieModel->lastError().text();
        return;
    }

    for(int i = 0; i < nrOfRows; i++)
    {
        movieModel->setData(movieModel->index(rowCount+i,1), "Star Wars: Episode VII - The Force Awakens");
        movieModel->setData(movieModel->index(rowCount+i,2), 127);
        movieModel->setData(movieModel->index(rowCount+i,3), 11);
        movieModel->setData(movieModel->index(rowCount+i,4), "Bla bla");
        movieModel->setData(movieModel->index(rowCount+i,5), "Sci-Fi");
        movieModel->setData(movieModel->index(rowCount+i,6), 2015);
    }

    if(movieModel->submitAll()) {
        movieModel->database().commit();
    } else {
        movieModel->database().rollback();
        qDebug() << "Database Write Error" <<
            "The database reported an error: " <<
            movieModel->lastError().text();
    }
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
