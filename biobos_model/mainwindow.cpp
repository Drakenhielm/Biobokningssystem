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

    //for(int i = 0; i < 3000; i++)
        //movieModel->deleteWhere("MovieID", i);
        movieModel->insertMovie("Polis", 127, 15, "Hmmm hm hm", "Drama", 2006);
    movieModel->refresh();
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
    movieModel->refresh();
    ui->tableView->setModel(movieModel);
    movieModel->setFilter(QString("MovieID > 3"));
    //movieModel->refresh();
    //movieModel->setQuery(movieModel->query());
    //qDebug() << movieModel->query().executedQuery()
            //<< movieModel->lastError();
    /*movieModel->clearFilter();
    movieModel->setQuery(movieModel->query());
    qDebug() << movieModel->query().executedQuery()
             << movieModel->lastError();*/

    /*showModel = new ShowModel(this);
    showModel->refresh();
    ui->tableView_4->setModel(showModel);

    hallModel = new HallModel(this);
    hallModel->refresh();
    ui->tableView_3->setModel(hallModel);

    seatModel = new SeatModel(this);
    seatModel->setHall(8);
    seatModel->setShow(1);
    seatModel->refresh();
    ui->tableView_2->setModel(seatModel);

    bookingModel = new BookingModel(this);
    //bookingModel->refresh();
    ui->tableView_5->setModel(bookingModel);

    model = new QSqlRelationalTableModel();
    model->setTable("movie");
    //model->setFilter("MovieID = '' or 1=1 or 1='1'");
    model->select();
    //qDebug() << model->query().executedQuery();

    */qModel = new QSqlQueryModel(this);
    qModel->setQuery("select * from (select * from movie) where MovieID = 1");
    ui->tableView_2->setModel(qModel);
    /*QSqlQuery query;
    query.prepare("select * from movie where MovieID < :val and Title = :val2 and AgeLimit = :val or MovieID = :val");

    query.bindValue(":val", 15);
    query.bindValue(":val2", "City'");

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

void MainWindow::on_pushButton_2_clicked()
{
    QString filter = ui->lineEdit->text();
    model->setFilter("Title like '"+filter+"%'");
}
