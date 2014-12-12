#include "hall_list.h"
#include "ui_hall_list.h"
#include "hallview.h"
#include <QVBoxLayout>
#include <QMessageBox>

hall_list::hall_list(HallModel *hallModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hall_list)
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
    ui->tableView_hall_list->setModel(hallModel);
    ui->tableView_hall_list->hideColumn(HallModel::HallID);
    ui->tableView_hall_list->hideColumn(HallModel::Rows);
    ui->tableView_hall_list->hideColumn(HallModel::Cols);

    ui->tableView_hall_list->setColumnWidth(HallModel::Name, 120);
    ui->tableView_hall_list->setColumnWidth(HallModel::ScreenSize, 70);
    ui->tableView_hall_list->setColumnWidth(HallModel::SoundSystem, 140);
    ui->tableView_hall_list->setColumnWidth(HallModel::Seats, 39);

    //hallSelectionChanged
    connect(ui->tableView_hall_list->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(hallSelectionChanged(QItemSelection,QItemSelection)));

    //delete hall
    connect(ui->DeleteButton, SIGNAL(clicked()), this, SLOT(deleteHall()));

    connect(ui->EditButton, SIGNAL(clicked()), this, SLOT(openEditHallDialogue()));

    //left tableview
    ui->tableView_hall_list->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

}

void hall_list::hallSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    int selIndex = getSelected(selected);

    //set seatModel to selected show
    seatModel->setHall(hallModel->getHallID(selIndex));
    seatModel->refresh();
    hallView->setHall(seatModel->getSeatStateMatrix(), hallModel->getRows(selIndex), hallModel->getColumns(selIndex));

}

int hall_list::getSelected(const QItemSelection &selection)
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


int hall_list::getSelected(QItemSelectionModel *selectionModel)
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


hall_list::~hall_list()
{

    delete ui;
}

void hall_list::setLabelNumberOfSeats()
{
    ui->label_number_of_seats->setText("Seats: " + QString::number(hallView->getTotalNumberOfSeats()));
}

void hall_list::deleteHall()
{
    int select = getSelected(ui->tableView_hall_list->selectionModel());

    if(select!=(-1))
    {
        QMessageBox msgBox(QMessageBox::Question,
                           "Delete Hall",
                           "Are you sure you want to delete this hall?"
                           "\n\nWarning: All connected shows and bookings to this hall will also be deleted.",
                           QMessageBox::Yes | QMessageBox::No
                           );
        if(msgBox.exec() == QMessageBox::Yes)
        {
            hallModel->removeRow(select);
            hallModel->refresh();
            seatModel->refresh();
            hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());
        }
    }
}

void hall_list::on_CloseButton_clicked()
{
    close();
}


void hall_list::openEditHallDialogue()
{
    int selIndex = getSelected(ui->tableView_hall_list->selectionModel());
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

void hall_list::editHall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem, const QList<QList<bool> > &seats)
{
    int selIndex = getSelected(ui->tableView_hall_list->selectionModel());
    hallModel->editHall(hallID, name, screenSize, soundSystem, seats);
    hallModel->refresh();
    seatModel->refresh();
    hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());

    QModelIndex index = hallModel->index(selIndex, HallModel::Name);
    if(index.isValid())
    {
        ui->tableView_hall_list->setCurrentIndex(index);
    }
}
