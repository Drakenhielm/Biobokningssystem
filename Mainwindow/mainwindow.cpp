#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    movieModel = new MovieModel();
    movieModel->select();
    ui->listView_movies->setModel(movieModel);
    ui->listView_movies->setModelColumn(MovieModel::Title);

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
   QString movie("Bad boys 2");
    // movie is used to test textbrowser (HTML) module.



    ui->textBrowser_info->setHtml
    (

        "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
        "p, li { white-space: pre-wrap; }"
        "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
        "<p style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
     //   + movieModel->record(0).value(MovieModel::Title).toString() +
        "</p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
   //     "Playtime: " + movieModel->record(0).value(MovieModel::PlayTime).toString() +
        ". "
        "Action."
        "</p>"
        "<p align='center' style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
        "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Information about movie. aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa </p></body></html>"
    );



}

void MainWindow::on_pushButton_movies_add_clicked()
{
    movieModel->insertMovie("Avatar", 123, 11, "ebebwen", "Adventure", 2009);
    movieModel->insertMovie("Bad Boys 2", 456, 11, "ebebwen", "Adventure", 2009);
    movieModel->submitAll();
    qDebug() << movieModel->record(0).value(MovieModel::AgeLimit).toInt();
}

void MainWindow::on_pushButton_movies_delete_clicked()
{
    movieModel->removeRow(ui->listView_movies->selectionModel()->selectedIndexes().first().row());
    movieModel->submitAll();
}


void MainWindow::on_listView_movies_clicked(const QModelIndex &index)
{

    ui->textBrowser_info->setHtml
    (

        "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
        "p, li { white-space: pre-wrap; }"
        "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
        "<p style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + movieModel->record(ui->listView_movies->selectionModel()->selectedIndexes().first().row()).value(MovieModel::Title).toString() +
        "</p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        "Playtime: " + movieModel->record(ui->listView_movies->selectionModel()->selectedIndexes().first().row()).value(MovieModel::PlayTime).toString() +
        ". "
        "Action."
        "</p>"
        "<p align='center' style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
        "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Information about movie. aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa </p></body></html>"
    );

}


