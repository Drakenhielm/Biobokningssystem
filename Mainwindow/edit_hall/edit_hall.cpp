#include "edit_hall.h"
#include "ui_edit_hall.h"
#include "hallview.h"
#include <QVBoxLayout>
#include <QMessageBox>



edit_hall::edit_hall(SeatModel *seatModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_hall)
{
    ui->setupUi(this);

    this->seatModel = seatModel;

    hallView = new HallView(this);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    ui->frame_hall->setLayout(lineLayout);
    ui->frame_hall->layout()->addWidget(hallView);

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(setLabelNumberOfSeats()));

    //hallView->setMode(true);
    hallView->setEnabled(false);

    hallModel = new HallModel(this);
    ui->tableView_edit_hall->setModel(hallModel);
    ui->tableView_edit_hall->hideColumn(HallModel::HallID);
    ui->tableView_edit_hall->hideColumn(HallModel::Rows);
    ui->tableView_edit_hall->hideColumn(HallModel::Cols);

    ui->tableView_edit_hall->setColumnWidth(HallModel::Name, 120);
    ui->tableView_edit_hall->setColumnWidth(HallModel::ScreenSize, 140);
    ui->tableView_edit_hall->setColumnWidth(HallModel::SoundSystem, 70);
    ui->tableView_edit_hall->setColumnWidth(HallModel::Seats, 39);

    //hallSelectionChanged
    connect(ui->tableView_edit_hall->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(hallSelectionChanged(QItemSelection,QItemSelection)));

    //delete hall
    connect(ui->DeleteButton, SIGNAL(clicked()), this, SLOT(deleteHall()));


}

void edit_hall::hallSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    int selIndex = getSelected(selected);

    //set seatModel to selected show
    seatModel->setHall(hallModel->getHallID(selIndex));
    seatModel->refresh();
    qDebug() << seatModel->getSeatStateMatrix();
    hallView->setHall(seatModel->getSeatStateMatrix(), hallModel->getRows(selIndex), hallModel->getColumns(selIndex));

}

int edit_hall::getSelected(const QItemSelection &selection)
{
    if(selection.empty())
    {
        return (-1);
    }
    else if(selection.first().indexes().empty())
    {
        return (-1);
    }
    else
    {
        return selection.first().indexes().first().row();
    }
}


int edit_hall::getSelected(QItemSelectionModel *selectionModel)
{
    if(selectionModel->selectedIndexes().empty())
    {
        return (-1);
    }
    else
    {
        return selectionModel->selectedIndexes().first().row();
    }
}


edit_hall::~edit_hall()
{

    delete ui;
}

void edit_hall::setLabelNumberOfSeats()
{
    ui->label_number_of_seats->setText("Seats: " + QString::number(hallView->getTotalNumberOfSeats()));
}

void edit_hall::deleteHall()
{
    int select = getSelected(ui->tableView_edit_hall->selectionModel());

    if(select!=(-1))
    {
        QMessageBox msgBox(QMessageBox::Question,
                           "Delete Show",
                           "Are you sure?",
                           QMessageBox::Yes | QMessageBox::No
                           );
        if(msgBox.exec() == QMessageBox::Yes)
        {
            hallModel->removeRow(select);
            hallModel->refresh();
        }
    }
}
