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
    /*QSqlQuery query;
    //insertValues(2000);
    bool ok = true;
        ok = query.prepare("insert into movie(Title) values('Valkyra')");//query.prepare(QString("DELETE FROM %1 WHERE %2 = :val").arg("movie").arg("MovieID"));
        //query.bindValue(":val", 6);
        qDebug() << query.exec();
        //qDebug() << movieModel2->removeRows(257, 300);
        qDebug() << movieModel2->removeRows(0, 3);
    movieModel2->sort(1, Qt::AscendingOrder);
    movieModel2->setJoinMode(QSqlRelationalTableModel::LeftJoin);
    movieModel2->setRelation(3, QSqlRelation("show", "ShowID", "ThreeD"));
    //movieModel2->setFilter("Title='Abc'");
    for(int i = 0; i < 1000; i++){
        movieModel2->insertMovie("Grreeen", 120, 11, "bla bla", "Familj", 2008);
    }
    movieModel2->submitAll();
    qDebug() << movieModel2->data(movieModel2->index(0, 3));
    //model->insertRows(0, 3);
    /*if(movieModel2->QSqlTableModel::submitAll())
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
    movieModel2->deleteWhere("Genre", "Familj");
    MovieModel *movieModel = new MovieModel;
    movieModel->insertMovie("Saw", 120, 11, "bla bla", "Hej", 2008);
    movieModel->select();
    ui->tableView_2->setModel(movieModel);
    qDebug() << movieModel2->insertMovie("Saw", 120, 11, "bla bla", "Hej", 2008);
    //movieModel2->query().exec();
    qDebug() << timer.elapsed();
    //MovieModel2->query().exec();
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
    movieModel2 = new MovieModel2();
    movieModel2->query().exec();
    ui->tableView->setModel(movieModel2);
    ui->tableView_2->setModel(movieModel2);
    //qDebug() << movieModel2->rowCount();
}

void MainWindow::insertValues(int nrOfRows)
{
    /*movieModel2->database().transaction();
    int rowCount = movieModel2->rowCount();
    if(!movieModel2->QSqlTableModel::insertRows(rowCount, nrOfRows)) {
        qDebug() << "insertRows" << movieModel2->lastError().text();
        return;
    }

    for(int i = 0; i < nrOfRows; i++)
    {
        movieModel2->setData(movieModel2->index(rowCount+i,1), "Star Wars: Episode VII - The Force Awakens");
        movieModel2->setData(movieModel2->index(rowCount+i,2), 127);
        movieModel2->setData(movieModel2->index(rowCount+i,3), 11);
        movieModel2->setData(movieModel2->index(rowCount+i,4), "Bla bla");
        movieModel2->setData(movieModel2->index(rowCount+i,5), "Sci-Fi");
        movieModel2->setData(movieModel2->index(rowCount+i,6), 2015);
    }

    if(movieModel2->submitAll()) {
        movieModel2->database().commit();
    } else {
        movieModel2->database().rollback();
        qDebug() << "Database Write Error" <<
            "The database reported an error: " <<
            movieModel2->lastError().text();
    }*/
}

void MainWindow::deleteValues(int startRow, int nrOfRows)
{
    /*model->database().transaction();
    if(!movieModel2->removeRows(startRow, nrOfRows)) {
        qDebug() << "removeRows" << movieModel2->lastError().text();
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
    /*QSqlQuery query;
    query.exec("insert into movie(Title) values('Valkyra')");
    int rows = movieModel2->rowCount();
    qDebug() << rows;
    movieModel2->selectRow(rows);*/
    /*for(int i = 0; i < 1500; i++){
    movieModel2->insertMovie("Grreeen", 120, 11, "bla bla", "Familj", 2008);
    movieModel2->submitAll(true);
    QVariant id = movieModel2->query().lastInsertId();
    movieModel2->setData(movieModel2->index(0,0), id);
    qDebug() << movieModel2->query().exec();//selectRow(0);
    ui->tableView->selectRow(0);
    }*/
    //qDebug() << movieModel2->record(0).value(1);//movieModel2->match(movieModel2->index(0,0), Qt::DisplayRole, "377", -1, Qt::MatchExactly).first().row();
}
