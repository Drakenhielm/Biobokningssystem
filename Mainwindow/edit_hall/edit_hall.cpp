#include "edit_hall.h"
#include "ui_edit_hall.h"
#include "hallview.h"
#include <QVBoxLayout>



edit_hall::edit_hall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_hall)
{
    ui->setupUi(this);

    hallView = new HallView(this);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    ui->frame_hall->setLayout(lineLayout);
    ui->frame_hall->layout()->addWidget(hallView);

    connect(ui->spinBox_rows, SIGNAL(valueChanged(int)), hallView, SLOT(setRows(int)));
    connect(ui->spinBox_columns, SIGNAL(valueChanged(int)), hallView, SLOT(setColumns(int)));

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(setLabelNumberOfSeats()));

    hallView->setMode(true);


    showModel = new ShowModel(this);
    ui->tableView_edit_hall->setModel(showModel);

}

edit_hall::~edit_hall()
{

    delete ui;
}

void edit_hall::setLabelNumberOfSeats()
{
    ui->label_number_of_seats->setText("Seats: " + QString::number(hallView->getTotalNumberOfSeats()));
}


