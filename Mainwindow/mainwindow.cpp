#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

   QString html(
               "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
               "p, li { white-space: pre-wrap; }"
               "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
               "<p style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
               "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Movie</p>"
               "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>1h 45min. Action.</p>"
               "<p align='center' style='-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><br /></p>"
               "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>Information about movie. aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa  aaaa aaa aaaa aaa aaaa </p></body></html>"

               );

    ui->textBrowser_info->setHtml(html);
}
