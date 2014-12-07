#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpModels();
    setUpTables();
    QElapsedTimer timer;
    timer.start();

    //Your space

    movieModel->insertMovie("Insert 1", 1, 1, "Desc", "genre", 2014, "");
    movieModel->insertMovie("Insert 2", 1, 1, "Desc", "genre", 2014, "");
    movieModel->insertMovie("Should be Deleted", 1, 1, "Desc", "genre", 2014, "");
    movieModel->editMovie(movieModel->getMovieID(1), "Edit 2", 1, 1, "Edit", "genre", 2014, "");
    movieModel->refresh();
    movieModel->removeRow(2);
    movieModel->refresh();

    showModel->insertShow(QDateTime::currentDateTime(), 9.99, false, true, "Eng", 1, 1);
    showModel->insertShow(QDateTime::currentDateTime(), 9.99, false, true, "Eng", 1, 1);
    showModel->insertShow(QDateTime::currentDateTime(), 9.99, false, true, "Should Be deleted", 1, 1);
    showModel->editShow(showModel->getShowID(1), QDateTime::currentDateTime(), 0, false, true, "Swe", 2, 2);
    showModel->refresh();
    showModel->removeRow(2);
    showModel->refresh();

    QList<QList<bool> > hallSeats;
    for(int i = 0; i < 5; i++)
    {
        hallSeats.append(QList<bool>());
        for(int j = 0; j < 3; j++)
        {
            if(j == 1)
                hallSeats[i].append(false);
            else
                hallSeats[i].append(true);
        }
    }

    hallModel->insertHall("Rigoletto", "3x5", "Dolby", hallSeats);
    hallModel->refresh();

    QList<int> bookingSeats;
    bookingSeats.append(1);
    bookingModel->insertBookings(1, bookingSeats, "979");
    bookingModel->refresh();

    //End your space

    ui->comboBox->setModel(showModel);
    qDebug() << timer.elapsed();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpModels()
{
    movieModel = new MovieModel(this);
    showModel = new ShowModel(this);
    bookingModel = new BookingModel(this);
    hallModel = new HallModel(this);
    seatModel = new SeatModel(this);
    seatModel->setHall(1);
    seatModel->setShow(1);
    seatModel->refresh();
}

void MainWindow::setUpTables()
{
    ui->tableView->setModel(movieModel);
    ui->tableView_2->setModel(seatModel);
    ui->tableView_3->setModel(hallModel);
    ui->tableView_4->setModel(showModel);
    ui->tableView_5->setModel(bookingModel);
}

void MainWindow::on_pushButton_clicked()
{
    movieModel->editMovie(1, "ööölll", 127, 15, "Hmmm hm hm", "Drama", 2006, "");
    movieModel->clearFilter();
    movieModel->refresh();
    qDebug() << movieModel->query().executedQuery();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filter = ui->lineEdit->text();
    movieModel->setFilter("Title LIKE ? || '%'", filter);
    qDebug() << movieModel->query().lastError();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    /*ui->textBrowser->document()->setDefaultStyleSheet(
                "#poster{ max-width: 50px; }"
    );
    ui->textBrowser->setHtml(
        "<!DOCTYPE html>"
        "<html lang='en'>"
            "<head>"
            "<meta charset='UTF-8'>"
            "<link href = 'style.css' rel = 'stylesheet'>"
            "</head>"
            "<body>"
                "<img src=':img/avatar.png' >"
                "<div style='width: 100; height: 20; background-color: #000000;' ></div>"
            "</body>"
        "</html>"
    );*/
    /*ui->webView->setHtml(
        "<!DOCTYPE html>"
        "<html lang='en'>"
            "<head>"
            "<link href = 'style.css' rel = 'stylesheet'>"
            "</head>"
            "<body>"
                "<img src=':img/avatar.png' >"
                "<div style='width: 100; height: 20; background-color: #000000;' ></div>"
            "</body>"
        "</html>"
    );*/
}
