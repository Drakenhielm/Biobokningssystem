#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include "hallview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    movieModel = new MovieModel();
    movieModel->refresh();
    ui->listView_movies->setModel(movieModel);
    ui->listView_movies->setModelColumn(MovieModel::Title);

    showModel = new ShowModel();
    showModel->refresh();
    ui->tableView_show->setModel(showModel);
    ui->tableView_show->hideColumn(ShowModel::ShowID);
    ui->tableView_show->hideColumn(ShowModel::MovieID);
    ui->tableView_show->setSelectionBehavior(QAbstractItemView::SelectRows);

    bookingModel = new BookingModel();
    bookingModel->setFilter("Phone = '070'");
    bookingModel->refresh();
    ui->tableView_search->setModel(bookingModel);

    hallView = new HallView();
    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(hallView);
    ui->frame_3->setLayout(lineLayout);
    ui->frame_3->setFrameStyle(1);
    ui->frame_3->setFrameShadow(QFrame::Raised);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_pushButton_info_edit_clicked()
{
    ;
}

void MainWindow::on_pushButton_movies_add_clicked()
{
    movieModel->insertMovie("Avatar", 123, 11, "Handlar om blue figures.", "Adventure", 2009);
    movieModel->insertMovie("Bad Boys 2", 456, 11, "The boys are back in town. Watch out. tjalalalala mmmmm mm mm mmmmm mm mm mmmmm mm", "Drama", 2009);
    movieModel->refresh();
    qDebug() << movieModel->record(0).value(MovieModel::AgeLimit).toInt();
}

void MainWindow::on_pushButton_movies_delete_clicked()
{
    movieModel->removeRow(ui->listView_movies->selectionModel()->selectedIndexes().first().row());
    movieModel->refresh();
}


void MainWindow::on_listView_movies_clicked(const QModelIndex &index)
{

    int selIndex = ui->listView_movies->selectionModel()->selectedIndexes().first().row();

    ui->textBrowser_info->setHtml
    (

        "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
        "p, li { white-space: pre-wrap; }"
        "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'> <b>"
        + movieModel->record(selIndex).value(MovieModel::Title).toString() +
        "</b> </p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + movieModel->record(selIndex).value(MovieModel::PlayTime).toString() +
        " min. "
        + movieModel->record(selIndex).value(MovieModel::Genre).toString() +
        "."
        "</p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><img src=':/images/Bad_boys_two.jpg' height='100' /></p>"

        "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + movieModel->record(selIndex).value(MovieModel::Description).toString() +
        "</p></body></html>"
    );

    //showModel->setFilter("MovieID = '"+);
}



void MainWindow::on_listView_movies_activated(const QModelIndex &index)
{
    qDebug() << "activated used";

    int selIndex = ui->listView_movies->selectionModel()->selectedIndexes().first().row();

    ui->textBrowser_info->setHtml
    (

        "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
        "p, li { white-space: pre-wrap; }"
        "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'> <b>"
        + movieModel->record(selIndex).value(MovieModel::Title).toString() +
        "</b> </p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + movieModel->record(selIndex).value(MovieModel::PlayTime).toString() +
        " min. "
        + movieModel->record(selIndex).value(MovieModel::Genre).toString() +
        "."
        "</p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><img src=':/images/Bad_boys_two.jpg' height='100' /></p>"

        "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + movieModel->record(selIndex).value(MovieModel::Description).toString() +
        "</p></body></html>"
    );

}

void MainWindow::on_pushButton_show_add_clicked()
{
    showModel->insertShow(QDateTime::currentDateTime(), 145, false, true, "English", 1, 1);
    showModel->refresh();
}

void MainWindow::on_pushButton_show_delete_clicked()
{
    showModel->removeRow(ui->tableView_show->selectionModel()->selectedIndexes().first().row());
    showModel->refresh();
}
