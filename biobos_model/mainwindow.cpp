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

    //for(int i = 0; i < 2000; i++)
        //movieModel->insertMovie("City of God", 127, 15, "Hmmm hm hm", "Drama", 2006);
    //movieModel->refresh();
    showModel->insertShow(QDateTime::currentDateTime(), 80, false, true, "Portuguese", 1, 8);
    showModel->refresh();
    //hallModel->insertHall("Rigoletto", "3x5", "Dolby", 10, 10);
    //hallModel->refresh();
    //seatModel->refresh();
    //bookingModel->insertBooking(1, 17, "070346757548");
    //bookingModel->refresh();*/

    qDebug() << timer.elapsed();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpTable()
{
    movieModel = new MovieModel(this);
    movieModel->refresh();
    ui->tableView->setModel(movieModel);
    movieModel->setFilter(QString("MovieID > '23'"));
    movieModel->refresh();

    showModel = new ShowModel(this);
    showModel->refresh();
    ui->tableView_4->setModel(showModel);

    hallModel = new HallModel(this);
    hallModel->refresh();
    //ui->tableView->setModel(hallModel);

    seatModel = new SeatModel(this);
    seatModel->setHall(8);
    seatModel->setShow(1);
    seatModel->refresh();
    ui->tableView_2->setModel(seatModel);

    bookingModel = new BookingModel(this);
    //bookingModel->refresh();
    ui->tableView_5->setModel(bookingModel);

    //model = new QSqlRelationalTableModel(this);
    /*QString queryStr = QString("SELECT seat.*, b_all.BookingID AS Booked, b_current.BookingID AS CurrentBooking")
                       +" from seat"
                       +" LEFT JOIN booking as b_all ON b_all.SeatID = seat.SeatID and b_all.ShowID = '1'"
                       +" LEFT JOIN booking as b_current ON b_current.SeatID = seat.SeatID and b_current.ShowID = '1'"
                       +" WHERE seat.HallID = '1'"
                       +" GROUP BY seat.SeatID ORDER BY seat.Row,seat.Column DESC";
    qDebug() << queryStr;
    model->QSqlQueryModel::setQuery(queryStr);*/
    /*model->setTable("seat");
    model->setFilter("SeatID > '10'");
    model->select();
    //ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(model);*/

    /*customModel = new CustomModel(this);
    customModel->setQuery("select * from movie");
    ui->tableView->setModel(customModel);*/
}

/*void MainWindow::insertValues(int nrOfRows)
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
}*/

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

void MainWindow::on_pushButton_clicked()
{
    movieModel->insertMovie("City of God", 127, 15, "Hmmm hm hm", "Drama", 2006);
    movieModel->refresh();
}
