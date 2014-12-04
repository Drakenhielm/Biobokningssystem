#include "confirmaddmovie.h"
#include "ui_confirmaddmovie.h"

confirmAddMovie::confirmAddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmAddMovie)
{
    ui->setupUi(this);
}

confirmAddMovie::~confirmAddMovie()
{
    delete ui;
}
