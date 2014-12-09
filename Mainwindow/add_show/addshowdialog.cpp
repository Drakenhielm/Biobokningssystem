#include "addshowdialog.h"
#include "ui_addshowdialog.h"
#include <QDateTime>

addShowDialog::addShowDialog(MovieModel *movieModel, HallModel *hallModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addShowDialog)
{
    ui->setupUi(this);
    /*
     * Get the movies/halls and insert them into the movieCBB and hallCBB here
     */
    ui->movieCBB->setModel(movieModel);
    ui->movieCBB->setModelColumn(1);
    ui->hallCBB->setModel(hallModel);
    ui->hallCBB->setModelColumn(1);

    this->movieModel = movieModel;
    this->hallModel = hallModel;

    //init radiobuttons (DDD = 3D...)
    ui->DDDNoRB->setChecked(true);
    ui->subNoRB->setChecked(true);

}

addShowDialog::~addShowDialog()
{
    delete ui;
}
/*
 *
 * Fucked up with the name of the buttons, should be fixed but saving this for now, just in case...
void addShowDialog::on_addHallButton_clicked()
{
    QDate date;
    QTime time;
    date = ui->calendarWidget->selectedDate();
    time = ui->timeEdit->time();

    QDateTime dateTime(date, time);

    emit add_Show(dateTime);

    close();

}

void addShowDialog::on_cancelHallButton_clicked()
{
    close();
}
*/
void addShowDialog::on_addShowButton_clicked()
{
    //Get the date and time
    QDate date;
    QTime time;
    date = ui->calendarWidget->selectedDate();
    time = ui->timeEdit->time();

    //Merge them into a QDateTime
    QDateTime dateTime(date, time);

    //Get movie
    int movieID = movieModel->getMovieID(ui->movieCBB->currentIndex());

    //Get hall
    int hallID = hallModel->getHallID(ui->hallCBB->currentIndex());

    //Get 3D
    bool DDD = ui->DDDYesRB->isChecked();

    //Get subs
    bool subs = ui->subYesRB->isChecked();

    //Get language
    QString lang = ui->languageCBB->currentText();

    //Get price
    double price = ui->priceSpinBox->value();

    //set sail! wohoo
    emit add_Show(dateTime, price, lang, DDD, subs, movieID, hallID);

    close();
}

void addShowDialog::on_cancelShowButton_clicked()
{
    close();
}
