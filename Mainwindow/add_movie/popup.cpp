#include "popup.h"
#include "ui_popup.h"
#include<QFileDialog>

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
    //adds a new genre to the movie
    if(ui->GenreCbb->currentText() != ""){
        QString tmp = ui->GenreCbb->currentText();
        ui->GenreCbb->removeItem(ui->GenreCbb->currentIndex());
        updateCurrentGenre(tmp);    //updates the current genre of the movie
    }
}

void popup::on_RemoveGenreButton_clicked()
{
    bool Drama = false, Action = false, Comedy = false, Thriller = false;

    //check for genres in the menu
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
    //add the missing ones
    if(!Drama)
        ui->GenreCbb->addItem("Drama");
    if(!Action)
        ui->GenreCbb->addItem("Action");
    if(!Comedy)
        ui->GenreCbb->addItem("Komedi");
    if(!Thriller)
        ui->GenreCbb->addItem("Thriller");

    //remove all text
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

//The function that generates the signal add_Movie.
void popup::on_AddButton_clicked()
{
    QString title, desc, genre, movieposter;
    int playtime, age, year;

    //save all values and send it away with the signal
    title = ui->TitleBox->text();
    desc = ui->DescritionEdit->toPlainText();
    playtime = ui->PlaytimeSpinBox->value();
    age = ui->AgeSpinBox->value();
    genre = ui->CurrGenreLabel->text();
    year = ui->YearSpinBox->value();
    movieposter = ui->PictureEdit->text();

    //emit the signal
    emit add_Movie(title, playtime, age, desc, genre, year, movieposter);

    close();
}

//open file explorer
void popup::on_ExploreButton_clicked()
{
   //get the path to the file selected, tr("Image Files...") adds filters to file endings
   QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/rasfa749", tr("Image Files (*.png *.jpg *.bmp)"));

    ui->PictureEdit->setText(fileName);
}

