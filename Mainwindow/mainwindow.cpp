#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include "hallview.h"
#include "add_hall/hall.h"
#include "add_movie/popup.h"
#include "add_show/addshowdialog.h"

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
    showModel->setHeaderData(ShowModel::Hall, Qt::Horizontal, "Hall");
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
    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(hallView);
    ui->frame_3->setLayout(lineLayout);
    ui->frame_3->setFrameStyle(1);
    ui->frame_3->setFrameShadow(QFrame::Plain);

    seatModel = new SeatModel(this);
    hallModel = new HallModel(this);

    initConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnections()
{
    //add movie
    connect(ui->pushButton_movies_add, SIGNAL(clicked()),
            this, SLOT(openAddMovieDialogue()));

    connect(ui->comboBox_numberOfSeats, SIGNAL(currentIndexChanged(int)), hallView, SLOT(setNumberOfSelected(int)));

    connect(ui->actionAdd_hall, SIGNAL(triggered()), this, SLOT(openAddHallDialogue()));

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(updateSelectedSeats(QList<int>)));

    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), hallView, SLOT(setSeperateSeats(bool)));
    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), this, SLOT(setComboBox(bool)));

    connect(ui->lineEdit_phone, SIGNAL(textChanged(QString)), this, SLOT(enableBookButton()));

    //connect movie list from selectionChanged
    connect(ui->listView_movies->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(movieSelectionChanged(QItemSelection,QItemSelection)));

    //connect show table from selectionChanged
    connect(ui->tableView_show->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(showSelectionChanged(QItemSelection,QItemSelection)));
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_H )
    {
        openAddHallDialogue();
    }
    else if( event->key() == Qt::Key_M )
    {
        openAddMovieDialogue();
    }
    else if(event->key() == Qt::Key_F)
    {
        ui->lineEdit_search->setFocus();
    }
}

void MainWindow::enableBookButton()
{
    bool isInt;
    ui->lineEdit_phone->text().toInt(&isInt);

    if(hallView->getSelectedSeats().size() > 0 && ui->lineEdit_phone->text().size() >= 5 && isInt == true)
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

void MainWindow::openAddHallDialogue()
{
    hall hallPopup;
    hallPopup.setModal(true);
    hallPopup.exec();
}

void MainWindow::on_pushButton_info_edit_clicked()
{

}

void MainWindow::openAddMovieDialogue()
{
    //declare the popup window
    popup popuper;

    //connect it with the add_Movie signal from the popup
    QObject::connect(&popuper, SIGNAL(add_Movie(QString, int, int, QString, QString, int, QString)),this, SLOT(addMovie(QString, int, int, QString, QString, int, QString)));

    //donno wat dis is
    popuper.setModal(true);

    //launch the popup
    popuper.exec();
}

void MainWindow::addMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter)
{
    movieModel->insertMovie(title, playtime, age, desc, genre, year, movieposter);
    movieModel->refresh();
}


void MainWindow::openEditMovieDialogue(const QModelIndex &index)
{

}

void MainWindow::editMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter)
{
    Q_UNUSED(title);
    Q_UNUSED(playtime);
    Q_UNUSED(age);
    Q_UNUSED(desc);
    Q_UNUSED(genre);
    Q_UNUSED(year);
    Q_UNUSED(movieposter);
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

void MainWindow::setHTML()
{
    int selIndex = getSelected(ui->listView_movies->selectionModel());

    if(selIndex==(-1))
    {
        ui->textBrowser_info->setHtml("");
    }

    else
    {
        QString img;
        if(!movieModel->getMoviePoster(selIndex).isEmpty()
                && ui->textBrowser_info->width() > 300)
        {
            img = "<img src='" + movieModel->getMoviePoster(selIndex) + "' width='150'/>";
        }

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
                            "<p align='center' style=' margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;'>"
                                +img+
                            "</p>"
                        "</td>"
                    "</tr>"
                "</table>"
            "</body></html>"
        );
    }
}


void MainWindow::on_pushButton_show_add_clicked()
{
    showModel->insertShow(QDateTime::currentDateTime(), 145, false, true, "English", 1, 2);
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
    {
        return (-1);
    }
    else
    {
        return selectionModel->selectedIndexes().first().row();
    }
}

int MainWindow::getSelected(const QItemSelection &selection)
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

void MainWindow::on_pushButton_hallview_info_book_clicked()
{
    QString phone = ui->lineEdit_phone->text();
    int showID = showModel->getShowID(getSelected(ui->tableView_show->selectionModel()));
    QList<int> seatIDs = hallView->getSelectedSeats();
    for(int i = 0; i < seatIDs.size(); i++)
    {
        seatIDs[i] = seatModel->getSeatID(seatIDs.at(i));
    }
    if(showID > 0 && !phone.isEmpty() && !seatIDs.isEmpty()) //check if valid booking
    {
        bookingModel->insertBookings(showID, seatIDs, phone);
        bookingModel->refresh();

        hallView->comfirmSelectedSeats();

        ui->lineEdit_phone->QLineEdit::clear();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Error: could not perform booking.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

//NEW FUNCTIONS BELOW
void MainWindow::filterBookings()
{
    QString showFilter;
    QString phone = ui->lineEdit_search->text();
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
    int selIndex = getSelected(selected);

    if(selIndex == -1)
    {
        showModel->clearFilter();
    }
    else
    {
        showModel->setFilter("MovieID = ?", movieModel->getMovieID(selIndex));
    }
    showSelectionChanged(QItemSelection(), QItemSelection());
}

void MainWindow::showSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    int selIndex = getSelected(selected);

    //update bookings table
    filterBookings();

    //set seatModel to selected show
    seatModel->setHall(showModel->getHallID(selIndex));
    seatModel->setShow(showModel->getShowID(selIndex));

    //set hall info labels
    if(selIndex == -1)
    {
        ui->label_hallinfo_title->setText("");
        ui->label_hallinfo->setText("");
    }
    else
    {
        ui->label_hallinfo_title->setText(showModel->getHall(selIndex));
        int hallIndex = hallModel->getRowByPrimaryKeyValue(showModel->getHallID(selIndex));
        int numOfSeats = hallModel->getSeats(hallIndex);
        QString soundSystem = hallModel->getSoundSystem(hallIndex);
        QString screenSize = hallModel->getScreenSize(hallIndex);
        ui->label_hallinfo->setText(
            QString::number(numOfSeats) + " seats"+", "
            +soundSystem+", "
            +screenSize+"m"
        );
    }
}

void MainWindow::on_pushButton_hallview_info_clear_clicked()
{
    hallView->clearSelectedSeats();
    ui->lineEdit_phone->QLineEdit::clear();
}
