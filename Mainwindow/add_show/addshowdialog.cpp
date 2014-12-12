#include "addshowdialog.h"
#include "ui_addshowdialog.h"
#include <QDateTime>

//Add show constructor
addShowDialog::addShowDialog(MovieModel *movieModel, HallModel *hallModel, int selMovieIndex, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addShowDialog)
{
    ui->setupUi(this);

    role = Add;

    this->movieModel = movieModel;
    this->hallModel = hallModel;

    initComboBoxes(selMovieIndex, 0);

    //init radiobuttons (DDD = 3D...)
    ui->DDDNoRB->setChecked(true);
    ui->subNoRB->setChecked(true);
}

//Edit role constructor
addShowDialog::addShowDialog(MovieModel *movieModel, HallModel *hallModel, int showID, QDateTime dateTime, double price,
                           QString lang, bool DDD, bool subs, int movieID, int hallID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addShowDialog)
{
    ui->setupUi(this);

    role = Edit;

    this->showID = showID;

    this->movieModel = movieModel;
    this->hallModel = hallModel;

    //set combo boxes
    initComboBoxes(movieModel->getRowByPrimaryKeyValue(movieID), hallModel->getRowByPrimaryKeyValue(hallID));

    //Date
    ui->calendarWidget->setSelectedDate(dateTime.date());

    //Time
    ui->timeEdit->setTime(dateTime.time());

    //3D
    if(DDD)
        ui->DDDYesRB->setChecked(true);
    else
        ui->DDDNoRB->setChecked(true);

    //Subs
    if(subs)
        ui->subYesRB->setChecked(true);
    else
        ui->subNoRB->setChecked(true);

    //Language
    ui->languageCBB->setCurrentText(lang);

    //Price
    ui->priceSpinBox->setValue(price);

}

void addShowDialog::initComboBoxes(int movieIndex, int hallIndex)
{
    //init combo boxes
    ui->movieCBB->setModel(movieModel);
    ui->movieCBB->setCurrentIndex(movieIndex);
    ui->movieCBB->setModelColumn(1);
    ui->hallCBB->setModel(hallModel);
    ui->hallCBB->setModelColumn(1);
    ui->hallCBB->setCurrentIndex(hallIndex);
}

addShowDialog::~addShowDialog()
{
    delete ui;
}

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
    if(role == Add)
        emit add_Show(dateTime, price, lang, DDD, subs, movieID, hallID);
    if(role == Edit)
        emit edit_show(showID, dateTime, price, lang, DDD, subs, movieID, hallID);

    close();
}

void addShowDialog::on_cancelShowButton_clicked()
{
    close();
}
