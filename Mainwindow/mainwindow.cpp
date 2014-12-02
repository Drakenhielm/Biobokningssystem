#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include "hallview.h"
#include "add_hall/hall.h"
#include "add_movie/popup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    movieModel = new MovieModel(this);
    ui->listView_movies->setModel(movieModel);
    ui->listView_movies->setModelColumn(MovieModel::Title);

    showModel = new ShowModel(this);
    showModel->setFilter("MovieID = -1");
    showModel->setHeaderData(ShowModel::ThreeD, Qt::Horizontal, "3D");
    showModel->setHeaderData(ShowModel::AvailableSeats, Qt::Horizontal, "Available seats");
    ui->tableView_show->setModel(showModel);
    ui->tableView_show->hideColumn(ShowModel::ShowID);
    ui->tableView_show->hideColumn(ShowModel::MovieID);
    ui->tableView_show->hideColumn(ShowModel::HallID);
    ui->tableView_show->horizontalHeader()->setStretchLastSection(true);

    ui->tableView_show->setColumnWidth(ShowModel::DateTime,100);
    ui->tableView_show->setColumnWidth(ShowModel::AvailableSeats, 100);

    bookingModel = new BookingModel(this);
    //bookingModel->setFilter("Phone = '070'");
    ui->tableView_search->setModel(bookingModel);
    ui->tableView_search->hideColumn(BookingModel::ShowID);
    ui->tableView_search->hideColumn(BookingModel::MovieID);
    ui->tableView_search->hideColumn(BookingModel::BookingID);
    ui->tableView_search->hideColumn(BookingModel::SeatIDs);
    ui->tableView_search->horizontalHeader()->setStretchLastSection(true);

    ui->pushButton_hallview_info_book->setEnabled(false);

    hallView = new HallView(this);
    hallView->setRows(10);
    hallView->setColumns(8);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(hallView);
    ui->frame_3->setLayout(lineLayout);
    ui->frame_3->setFrameStyle(1);
    ui->frame_3->setFrameShadow(QFrame::Plain);

    connect(ui->comboBox_numberOfSeats, SIGNAL(currentIndexChanged(int)), hallView, SLOT(setNumberOfSelected(int)));

    connect(ui->actionAdd_hall, SIGNAL(triggered()), this, SLOT(addHall()));

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(updateSelectedSeats(QList<int>)));

    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), hallView, SLOT(setSeperateSeats(bool)));
    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), this, SLOT(setComboBox(bool)));

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableBookButton()));

    //connect movie list from selectionChanged
    connect(ui->listView_movies->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(movieSelectionChanged(QItemSelection,QItemSelection)));

    //connect movie list from selectionChanged
    connect(ui->tableView_show->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(showSelectionChanged(QItemSelection,QItemSelection)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::enableBookButton()
{
    if(hallView->getSelectedSeats().size() > 0 && ui->lineEdit->text().size() > 0)
        ui->pushButton_hallview_info_book->setEnabled(true);
    else
        ui->pushButton_hallview_info_book->setEnabled(false);
}

void MainWindow::setComboBox(bool seperate)
{
    if(seperate)
        ui->comboBox_numberOfSeats->setCurrentIndex(0);
    ui->comboBox_numberOfSeats->setDisabled(seperate);
}

void MainWindow::updateSelectedSeats(QList<int> seats)
{
    enableBookButton();

    QString selectedSeats;
    if(seats.size() > 0)
        selectedSeats = QString::number(seats[0]);
    else
        selectedSeats = " ";
    for(int i = 1; i < seats.size(); ++i)
        selectedSeats = selectedSeats + ", " + QString::number(seats[i]);
    ui->label_hallinfo_selectedSeats_display->setText(selectedSeats);
}

void MainWindow::addHall()
{
    hall hallPopup;
    hallPopup.setModal(true);
    hallPopup.exec();
}

void MainWindow::on_pushButton_info_edit_clicked()
{

}

void MainWindow::on_pushButton_movies_add_clicked()
{
    movieModel->insertMovie("Avatar", 123, 11, "Handlar om blue figures.", "Adventure", 2009, "/images/avatar.jpg");
    movieModel->insertMovie("Bad Boys 2", 456, 11, "The boys are back in town. Watch out. tjalalalala mmmmm mm mm mmmmm mm mm mmmmm mm", "Drama", 2009, "/images/Bad_boys_two.jpg");
    movieModel->refresh();
    qDebug() << movieModel->record(0).value(MovieModel::AgeLimit).toInt();

    popup popuper;
    popuper.setModal(true);
    popuper.exec();

}

void MainWindow::on_pushButton_movies_delete_clicked()
{
    if(getSelected(ui->listView_movies->selectionModel())!=(-1))
    {
        movieModel->removeRow(getSelected(ui->listView_movies->selectionModel()));
        movieModel->refresh();
        setHTML();
    }
}


void MainWindow::on_listView_movies_clicked(const QModelIndex &index)
{

    //if(ui->comboBox_search->currentText("Selected show"))
        //bookingModel->setFilter("ShowID = ?", showModel);
}



void MainWindow::on_listView_movies_activated(const QModelIndex &index)
{
    qDebug() << "activated used";
    setHTML();
}

void MainWindow::setHTML()
{

    int selIndex = getSelected(ui->listView_movies->selectionModel());

    if(selIndex==(-1))
    {
        ui->textBrowser_info->setHtml("");
    }

    else
    {
    ui->textBrowser_info->setHtml
    (

        "<html><head><meta name='qrichtext' content='1' /><style type='text/css'>"
        "p, li { white-space: pre-wrap; }"
        "</style></head><body style=' font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;'>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'> <b><span style=' font-size:18pt; text-decoration: underline;'>"
        + movieModel->getTitle(selIndex) +
        "</span></b> </p>"
        "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
        + QString::number(movieModel->getPlayTime(selIndex)) +
        " min. "
        + movieModel->getGenre(selIndex) +
        "."
        "</p>"

                "<table width='100%' cellpadding='0' cellspacing='10' border='0'>"
                    "<tr>"
                        "<td width='50%' valign='top'>"
                            "<p style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
                            + movieModel->getDescription(selIndex) +
                            "</p>"
                        "</td>"
                        "<td width='50%' valign='top'>"
                            "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'><img src=':"
                             + movieModel->getMoviePoster(selIndex) +
                             "' height='180' /></p>"
                        "</td>"
                    "</tr>"
                "</table>"


      "</body></html>"
    );

    }

}


void MainWindow::on_pushButton_show_add_clicked()
{
    showModel->insertShow(QDateTime::currentDateTime(), 145, false, true, "English", 1, 1);
    showModel->refresh();
}

void MainWindow::on_pushButton_show_delete_clicked()
{
    int select = getSelected(ui->tableView_show->selectionModel());

    if(select!=(-1))
    {
    showModel->removeRow(select);
    showModel->refresh();
    }
}

void MainWindow::on_pushButton_search_clicked()
{
    filterBookings();
}

int MainWindow::getSelected(QItemSelectionModel *selectionModel)
{
    if(selectionModel->selectedIndexes().empty())
        return (-1);
    else
        return selectionModel->selectedIndexes().first().row();
}

void MainWindow::on_pushButton_hallview_info_book_clicked()
{
    QList<int> seatIDs = hallView->getSelectedSeats();
    bookingModel->insertBookings(1, seatIDs, "070654321");
    bookingModel->refresh();

    hallView->comfirmSelectedSeats();
}

//NEW FUNCTIONS BELOW
void MainWindow::filterBookings()
{
    QString showFilter;
    QString phone = ui->lineEdit_search->text();
    qDebug() << ui->comboBox_search->currentIndex();
    if(ui->comboBox_search->currentIndex() == 1) //within selected show
    {
        int row = getSelected(ui->tableView_show->selectionModel());
        showFilter = QString("ShowID = %1").arg(showModel->getShowID(row));
    }

    if(!showFilter.isEmpty() && !phone.isEmpty())
    {
        bookingModel->setFilter(showFilter+" AND Phone = ?", phone);
    }
    else if(!phone.isEmpty())
    {
        bookingModel->setFilter("Phone = ?", phone);
    }
    else if(!showFilter.isEmpty())
    {
        bookingModel->setFilter(showFilter);
    }
    else
    {
        bookingModel->clearFilter();
    }
}

void MainWindow::on_comboBox_search_currentIndexChanged(int index)
{
    filterBookings();
}

void MainWindow::movieSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    setHTML();

    if(selected.empty())
    {
        showModel->clearFilter();
    }
    else
    {
        int row = selected.first().indexes().first().row();
        showModel->setFilter("MovieID = ?", movieModel->getMovieID(row));
    }
}

void MainWindow::showSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    filterBookings();
}
