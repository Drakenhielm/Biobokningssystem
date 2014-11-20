#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);

}

popup::~popup()
{

    delete ui;
}

void popup::on_CancelButton_clicked()
{
    close();
}

void popup::on_AddGenreButton_clicked()
{
    QString tmp = ui->GenreCbb->currentText();
    ui->GenreCbb->removeItem(ui->GenreCbb->currentIndex());
    updateCurrentGenre(tmp);
}

void popup::on_RemoveGenreButton_clicked()
{
    bool Drama = false, Action = false, Comedy = false, Thriller = false;

    for(int i = 0; i<=3; ++i){
        if(ui->GenreCbb->itemText(i) == "Drama")
            Drama = true;
        if(ui->GenreCbb->itemText(i) == "Action")
            Action = true;
        if(ui->GenreCbb->itemText(i) == "Komedi")
            Comedy = true;
        if(ui->GenreCbb->itemText(i) == "Thriller")
            Thriller = true;
    }
    if(!Drama)
        ui->GenreCbb->addItem("Drama");
    if(!Action)
        ui->GenreCbb->addItem("Action");
    if(!Comedy)
        ui->GenreCbb->addItem("Komedi");
    if(!Thriller)
        ui->GenreCbb->addItem("Thriller");


    ui->CurrGenreLabel->setText("");
}

void popup::updateCurrentGenre(QString s)
{
    QString tmp = ui->CurrGenreLabel->text();
    if(ui->CurrGenreLabel->text() == ""){
        ui->CurrGenreLabel->setText(s);
    }else{
        ui->CurrGenreLabel->setText(tmp+"/"+s);
    }
}


