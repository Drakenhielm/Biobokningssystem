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

    /*for(int i = 0; i < 100; i++)
    {
        showModel->insertShow(QDateTime::currentDateTime().addDays(1), 99.5, false, true, "Swe", 10, 1);
        hallModel->insertHall("Rigoletto", "3x5", "Dolby", 10, 5);
    }
    bookingModel->insertBooking(1, 10, "07023456");
    bookingModel->insertBooking(1, 11, "07023456");
    bookingModel->insertBooking(1, 12, "07023456");
    bookingModel->insertBooking(1, 17, "07067044");
    bookingModel->insertBooking(1, 18, "07078979");
    showModel->refresh();
    bookingModel->refresh();
    hallModel->refresh();*/
    //showModel->insertShow(QDateTime::currentDateTime(), 80, false, true, "Portuguese", 1, 8);
    //showModel->refresh();
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
    //movieModel->refresh();
    ui->tableView->setModel(movieModel);
    QList<QVariant> list;
    list.append(20);
    movieModel->setFilter(QString("MovieID > ?"), list);
    //movieModel->refresh();
    //movieModel->setQuery(movieModel->query());
    //qDebug() << movieModel->query().executedQuery()
            //<< movieModel->lastError();
    /*movieModel->clearFilter();
    movieModel->setQuery(movieModel->query());
    qDebug() << movieModel->query().executedQuery()
             << movieModel->lastError();*/

    showModel = new ShowModel(this);
    //showModel->refresh();
    ui->tableView_4->setModel(showModel);

    hallModel = new HallModel(this);
    hallModel->refresh();
    ui->tableView_3->setModel(hallModel);

    seatModel = new SeatModel(this);
    seatModel->setHall(1);
    seatModel->setShow(1);
    seatModel->refresh();
    ui->tableView_2->setModel(seatModel);

    bookingModel = new BookingModel(this);
    bookingModel->refresh();
    ui->tableView_5->setModel(bookingModel);
    /*
    model = new QSqlRelationalTableModel();
    model->setTable("movie");
    //model->setFilter("MovieID = '' or 1=1 or 1='1'");
    model->select();
    //qDebug() << model->query().executedQuery();
    */
    qModel = new QSqlQueryModel(this);
    qModel->setQuery("select * from (select * from movie) where MovieID = 1");
    ui->tableView_2->setModel(qModel);
    QSqlQuery query;
    query.prepare("select * from movie where MovieID < :val and Title = :2val and AgeLimit = :val or MovieID = :val");

    query.bindValue(":val", 15);
    query.bindValue(":2val", "City'");

    query.exec();//"select * from movie where MovieID = ''\";delete from movie where MovieID = '1'");
    qModel->setQuery(query);
    qModel->query().exec();
    qDebug() << qModel->query().executedQuery();
    qDebug() << qModel->query().lastQuery();
    query.prepare(qModel->query().lastQuery());
    /*QMapIterator<QString, QVariant> i(qModel->query().boundValues());
    while(i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": "
                 << i.value().toString();
        query.bindValue(i.key(), i.value());
    }
    query.exec();
    qModel->setQuery(query);
    qModel->query().exec();*/
    /*QList<QVariant> list = qModel->query().boundValues().values();
    qDebug() << qModel->query().boundValues().size();
    int i = 0;
    while(qModel->query().boundValue(i).isValid())
    {
        qDebug() << i << ": "
                 << qModel->query().boundValue(i);
        i++;
    }
    for(int i = 0; i < list.size(); i++)
        //qDebug() << i << ": " << list.at(i).toString();
    qDebug() << 2 << ": " << qModel->query().boundValue(3);
    //ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(qModel);

    QString str = "abcdefgh";
    str.remove(1, -1);
    qDebug() << str;

    str = "abcdefgh";
    str.remove(1, 100);
    qDebug() << str;

    str = "abcdefgh";
    qDebug() << str.mid(1, 7);

    /*customModel = new CustomModel(this);
    customModel->setQuery("select * from movie");
    ui->tableView->setModel(customModel);*/
}

void MainWindow::on_pushButton_clicked()
{
    movieModel->insertMovie("City of God", 127, 15, "Hmmm hm hm", "Drama", 2006);
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
