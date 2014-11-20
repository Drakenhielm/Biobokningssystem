#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QComboBox *cbb = new QComboBox();
    cbb->addItem("Drama");
    cbb->addItem("Action");
    cbb->addItem("Komedi");
    cbb->addItem("Thriller");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    popup popuper;
    popuper.setModal(true);
    popuper.exec();
}
