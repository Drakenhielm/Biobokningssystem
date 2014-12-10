#include "edit_hall.h"
#include "ui_edit_hall.h"
#include "hallview.h"
#include <QVBoxLayout>
#include <QMessageBox>



edit_hall::edit_hall(HallModel *hallModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_hall)
{
    ui->setupUi(this);

    hallView = new HallView(this);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    ui->frame_hall->setLayout(lineLayout);
    ui->frame_hall->layout()->addWidget(hallView);

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(setLabelNumberOfSeats()));

    hallView->setEnabled(false);

    this->hallModel = hallModel;

    seatModel = new SeatModel(this);
    ui->tableView_edit_hall->setModel(hallModel);
    ui->tableView_edit_hall->hideColumn(HallModel::HallID);
    ui->tableView_edit_hall->hideColumn(HallModel::Rows);
    ui->tableView_edit_hall->hideColumn(HallModel::Cols);

    ui->tableView_edit_hall->setColumnWidth(HallModel::Name, 120);
    ui->tableView_edit_hall->setColumnWidth(HallModel::ScreenSize, 70);
    ui->tableView_edit_hall->setColumnWidth(HallModel::SoundSystem, 140);
    ui->tableView_edit_hall->setColumnWidth(HallModel::Seats, 39);

    //hallSelectionChanged
    connect(ui->tableView_edit_hall->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(hallSelectionChanged(QItemSelection,QItemSelection)));

    //delete hall
    connect(ui->DeleteButton, SIGNAL(clicked()), this, SLOT(deleteHall()));

    connect(ui->EditButton, SIGNAL(clicked()), this, SLOT(openEditHallDialogue()));


}

void edit_hall::hallSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    int selIndex = getSelected(selected);

    //set seatModel to selected show
    seatModel->setHall(hallModel->getHallID(selIndex));
    seatModel->refresh();
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
                           "Delete Hall",
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

void edit_hall::on_CloseButton_clicked()
{
    close();
}


void edit_hall::openEditHallDialogue()
{
    int selIndex = getSelected(ui->tableView_edit_hall->selectionModel());
    if(selIndex != -1)
    {
        QString scsi = hallModel->getScreenSize(selIndex);
        QString sosy = hallModel->getSoundSystem(selIndex);
        hall hallPopup(hallModel->getHallID(selIndex), hallModel->getName(selIndex), hallModel->getScreenSize(selIndex),
                       hallModel->getSoundSystem(selIndex), seatModel->getSeatStateMatrix());
        QObject::connect(&hallPopup, SIGNAL(editHall(int,QString,QString,QString,QList<QList<bool> >)),
                         this, SLOT(editHall(int,QString,QString,QString,QList<QList<bool> >)));

        hallPopup.setModal(true);
        hallPopup.setWindowTitle("Edit Hall");
        hallPopup.move(this->x()+50,this->y()+50);
        hallPopup.exec();
    }


}

void edit_hall::editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem, const QList<QList<bool> > &seats)
{
    int selIndex = getSelected(ui->tableView_edit_hall->selectionModel());
    hallModel->editHall(hallID, name, screenSize, soundSystem, seats);
    hallModel->refresh();
    if(selIndex != -1)
    {
        QModelIndex index = hallModel->index(selIndex, 0);
        ui->tableView_edit_hall->setCurrentIndex(index);
    }
}
