#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);

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
    pixmap = ih.getPixmap(ih.lastInsertedFileName());
    ui->label->setPixmap(pixmap);
    qDebug() << ih.lastInsertedFileName();

}
