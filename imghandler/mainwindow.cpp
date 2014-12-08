#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel;
    ui->treeView->setModel(model);
    model->setRootPath("C:\\Users");
    qDebug() << ih.getFolderPath();
    qDebug() << model->rootPath();

    ui->label->setPixmap(pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //get the path to the file selected, tr("Image Files...") adds filters to file endings
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), ih.getFolderPath(), tr("Image Files (*.png *.jpg *.bmp)"));

     ui->lineEdit->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file = ui->lineEdit->text();
    ih.copyImage(file);
    qDebug() << pixmap.load("C:/Users/Isac/Documents/Qt_projects/build-imghandler-Desktop_Qt_5_3_MinGW_32bit-Debug/img/stol_w4.png");
    ui->label->setPixmap(pixmap);
}
