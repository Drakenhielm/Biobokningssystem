#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpModels();
    setUpTables();


    //Your space



    /*movieModel->insertMovie("Insert 1", 1, 1, "Desc", "genre", 2014, "");
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

    */QList<QList<bool> > hallSeats;
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
    hallModel->insertHall("Hall 1", "3x5", "Dolby", hallSeats);
    int edit = hallModel->insertHall("Hall 2", "3x5", "Dolby", hallSeats);
    int remove = hallModel->insertHall("Hall 3", "3x5", "Dolby", hallSeats);

    hallSeats.removeLast();
    hallSeats.removeLast();
    hallModel->editHall(edit, "Hall Edit", "4x4", "Dolby Special Edition Deluxe Super Master Epica System", hallSeats);

    hallModel->refresh();
    qDebug() << remove;
    qDebug() << hallModel->getRowByPrimaryKeyValue(remove);
    hallModel->removeRow(hallModel->getRowByPrimaryKeyValue(remove));
    hallModel->refresh();
    /*
    QList<int> bookingSeats;
    bookingSeats.append(1);
    bookingModel->insertBookings(1, bookingSeats, "979");
    bookingModel->refresh();*/

    //End your space

    //ui->comboBox->setModel(showModel);
    //qDebug() << timer.elapsed();
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
    QElapsedTimer timer;
    timer.start();

    QList<QList<bool> > hallSeats;
    for(int i = 0; i < 10; i++)
    {
        hallSeats.append(QList<bool>());
        for(int j = 0; j < 10; j++)
        {
            if(j == 1)
                hallSeats[i].append(false);
            else
                hallSeats[i].append(true);
        }
    }

    DatabaseHandler dh;
    dh.transaction();
    int c = 0;
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(c);
    for(int i = 1; i <= c; i++)
    {
        if(i < c/10)
        {
            QString poster;
            if(i%2 == 0)
                poster = "C:/Users/Isac/Desktop/avatar.jpg";
            else
                poster = "C:/Users/Isac/Desktop/Bad_boys_two.jpg";

            movieModel->insertMovie("Title "+QString::number(i), 1, 1, "Desc", "genre", 2014, poster);
        }

        showModel->insertShow(QDateTime::currentDateTime(), 99.50, false, true, "English", i/10, i);

        hallModel->insertHall("Hall "+i, "2 x 3", "Dolby", hallSeats);

        QList<int> bookingSeats;
        bookingSeats.append((i+1)*10+0);
        bookingSeats.append((i+1)*10+1);
        bookingSeats.append((i+1)*10+2);
        bookingSeats.append((i+1)*10+3);

        bookingModel->insertBookings(i, bookingSeats, "070"+QString::number(i));

        ui->progressBar->setValue(i);
    }
    dh.endTransaction(true);

    qDebug() << timer.elapsed();
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
