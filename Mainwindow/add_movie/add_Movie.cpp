#include "add_Movie.h"
#include "ui_add_Movie.h"
#include<QFileDialog>

add_Movie::add_Movie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_Movie)
{
    ui->setupUi(this);
    role = Add;
}

add_Movie::add_Movie(int movieID, QString title, int playtime, int age, QString desc, QString genre,
                   int year, QString movieposter, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_Movie)
{
    ui->setupUi(this);
    role = Edit;

    removeGenresFromCbb(genre);

    this->movieID = movieID;
    ui->TitleBox->setText(title);
    ui->PlaytimeSpinBox->setValue(playtime);
    ui->AgeSpinBox->setValue(age);
    ui->DescritionEdit->setText(desc);
    ui->CurrGenreLabel->setText(genre);
    ui->YearSpinBox->setValue(year);
    ui->PictureEdit->setText(movieposter);
}

add_Movie::~add_Movie()
{
    delete ui;
}

void add_Movie::on_CancelButton_clicked()
{
    close();
}

void add_Movie::on_AddGenreButton_clicked()
{
    //adds a new genre to the movie
    if(ui->GenreCbb->currentText() != "" && genres.size() < 3){
        QString tmp = ui->GenreCbb->currentText();
        genres.push_back(tmp);
        ui->GenreCbb->removeItem(ui->GenreCbb->currentIndex());
        updateCurrentGenre(tmp);    //updates the current genre of the movie
    }
}

void add_Movie::on_RemoveGenreButton_clicked()
{
    //Re-add genres to combobox
    for(int i = 0; i<genres.size(); ++i){
      ui->GenreCbb->addItem(genres[i]);
    }

    genres.clear();
    //Alphabetical order
    ui->GenreCbb->model()->sort(0);

    //remove all text
    ui->CurrGenreLabel->setText("");
}

void add_Movie::updateCurrentGenre(QString s)
{
    QString tmp = ui->CurrGenreLabel->text();
    if(ui->CurrGenreLabel->text() == ""){
        ui->CurrGenreLabel->setText(s);
    }else{
        ui->CurrGenreLabel->setText(tmp+"/"+s);
    }
}

//The function that generates the signal add_Movie.
void add_Movie::on_AddButton_clicked()
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

    //emit the signal depending on the role
    if(role == Add)
        emit addMovie(title, playtime, age, desc, genre, year, movieposter);
    if(role == Edit)
        emit editMovie(movieID, title, playtime, age, desc, genre, year, movieposter);

    close();
}

//open file explorer
void add_Movie::on_ExploreButton_clicked()
{
   //get the path to the file selected, tr("Image Files...") adds filters to file endings
   QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

   if(fileName != "") //if not cancel button
   {
        ui->PictureEdit->setText(fileName);
   }
}

//Remove genres from genre combobox (used in the constructor for edit mode)
void add_Movie::removeGenresFromCbb(const QString &genreStr)
{
    //get all genres from genreStr in a QStringList
    QStringList strList = genreStr.split('/', QString::SkipEmptyParts);

    //iterat through the list
    for(int i = 0; i < strList.size(); i++)
    {
        //find the index of the genre in the cbb
        int cbbIndex = ui->GenreCbb->findText(strList.at(i));

        if(cbbIndex != -1)
        {
            ui->GenreCbb->removeItem(cbbIndex); //remove item
        }
    }
}
