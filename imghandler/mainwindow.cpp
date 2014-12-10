#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setPixmap(pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_open_dialog_clicked()
{
    //get the path to the file selected, tr("Image Files...") adds filters to file endings
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Image"), ih.getFolderPath(), tr("Image Files (*.png *.jpg *.bmp)"));

     ui->lineEdit->setText(fileName);
}

void MainWindow::on_pushButton_copy_clicked()
{
    QString file = ui->lineEdit->text();
    ih.copyImage(file);
    pixmap = ih.getPixmap(ih.lastInsertedFileName());
    ui->label->setPixmap(pixmap);

    ui->lineEdit_2->setText(ih.lastInsertedFileName());

    ui->textEdit->setText(QString("Copy:\n")+
                          "From path: "+file+"\n"
                          "New name: "+ih.lastInsertedFileName()+"\n\n");
}

void MainWindow::on_pushButton_remove_clicked()
{
    QString file = ui->lineEdit_2->text();
    bool remove = ih.removeImage(file);
    bool exists = ih.fileNameExists(file);

    if(remove && !exists)
    {
        ui->lineEdit_2->setText("");
        pixmap.fill();
        ui->label->setPixmap(pixmap);
    }

    ui->textEdit->setText(QString("Remove:\n")+
                          "File: "+file+"\n"
                          "Removed: "+QString::number(remove)+"\n"
                          "Still exists: "+QString::number(exists)+"\n\n");
}

void MainWindow::on_pushButton_replace_clicked()
{
    QString newFile = ui->lineEdit->text();
    QString oldFile = ui->lineEdit_2->text();

    bool replace = ih.replaceImage(oldFile, newFile);

    pixmap = ih.getPixmap(ih.lastInsertedFileName());
    ui->label->setPixmap(pixmap);

    ui->textEdit->setText(QString("Replace:\n")+
                          "Old file: "+oldFile+"\n"
                          "New file: "+newFile+"\n"
                          "Replaced: "+QString::number(replace)+"\n");
}
