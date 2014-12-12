#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>
#include "hallview.h"
#include "add_hall/hall.h"
#include "add_movie/add_Movie.h"
#include "add_show/addshowdialog.h"
#include "hall_list/hall_list.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initModels();
    initViews();
    initConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initModels()
{
    //MovieModel
    movieModel = new MovieModel(this);

    //ShowModel
    showModel = new ShowModel(this);
    showModel->setFilter("MovieID = -1");
    showModel->setHeaderData(ShowModel::ThreeD, Qt::Horizontal, "3D");
    showModel->setHeaderData(ShowModel::Hall, Qt::Horizontal, "Hall");
    showModel->setHeaderData(ShowModel::AvailableSeats, Qt::Horizontal, "Available seats");

    //BookingModel
    bookingModel = new BookingModel(this);

    //HallModel
    hallModel = new HallModel(this);

    //SeatModel
    seatModel = new SeatModel(this);
}

void MainWindow::initViews()
{
    //Movies
    ui->listView_movies->setModel(movieModel);
    ui->listView_movies->setModelColumn(MovieModel::Title);

    //Shows
    ui->tableView_show->setModel(showModel);
    ui->tableView_show->hideColumn(ShowModel::ShowID);
    ui->tableView_show->hideColumn(ShowModel::MovieID);
    ui->tableView_show->hideColumn(ShowModel::HallID);
    ui->tableView_show->horizontalHeader()->setStretchLastSection(true);
   // ui->tableView_show->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_show->setColumnWidth(ShowModel::DateTime,120);
    ui->tableView_show->setColumnWidth(ShowModel::Price,40);
    ui->tableView_show->setColumnWidth(ShowModel::AvailableSeats, 100);

    //Bookings
    ui->tableView_search->setModel(bookingModel);
    ui->tableView_search->hideColumn(BookingModel::ShowID);
    ui->tableView_search->hideColumn(BookingModel::MovieID);
    ui->tableView_search->hideColumn(BookingModel::BookingID);
    ui->tableView_search->horizontalHeader()->setStretchLastSection(true);

    ui->tableView_search->setColumnWidth(BookingModel::DateTime,120);

    //New Booking
    ui->pushButton_hallview_info_book->setEnabled(false);

    //HallView
    hallView = new HallView(this);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(hallView);
    ui->frame_3->setLayout(lineLayout);
    ui->frame_3->setFrameStyle(1);
    ui->frame_3->setFrameShadow(QFrame::Plain);

    //left tableViews
    ui->tableView_show->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_search->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


}

void MainWindow::initConnections()
{
    //Add Movie
    connect(ui->pushButton_movies_add, SIGNAL(clicked()), this, SLOT(openAddMovieDialogue()));
    connect(ui->actionAdd_movie, SIGNAL(triggered()), this, SLOT(openAddMovieDialogue()));

    //Delete Movie
    connect(ui->pushButton_movies_delete, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    connect(ui->actionDelete_movie, SIGNAL(triggered()), this, SLOT(deleteMovie()));

    //Edit Movie
    connect(ui->pushButton_info_edit, SIGNAL(clicked()), this, SLOT(openEditMovieDialogue()));
    connect(ui->actionEdit_Movie, SIGNAL(triggered()), this, SLOT(openEditMovieDialogue()));

    //Add Show
    connect(ui->pushButton_show_add, SIGNAL(clicked()), this, SLOT(openAddShowDialog()));
    connect(ui->actionAdd_show, SIGNAL(triggered()), this, SLOT(openAddShowDialog()));

    //Delete Show
    connect(ui->pushButton_show_delete, SIGNAL(clicked()), this, SLOT(deleteShow()));
    connect(ui->actionDelete_show, SIGNAL(triggered()), this, SLOT(deleteShow()));

    //Edit Show
    connect(ui->pushButton_show_edit, SIGNAL(clicked()), this, SLOT(openEditShowDialogue()));
    connect(ui->actionEdit_Show, SIGNAL(triggered()), this, SLOT(openEditShowDialogue()));

    //Add Booking
    connect(ui->pushButton_hallview_info_book, SIGNAL(clicked()), this, SLOT(addBooking()));
    connect(ui->actionBook, SIGNAL(triggered()), this, SLOT(addBooking()));

    //Delete Booking
    connect(ui->pushButton_bookings_delete, SIGNAL(clicked()), this, SLOT(deleteBooking()));
    connect(ui->actionDelete_booking, SIGNAL(triggered()), this, SLOT(deleteBooking()));

    //Search Booking
    connect(ui->actionSearch_Booking, SIGNAL(triggered()), this, SLOT(highlightSearchBooking()));

    //Edit Booking

    //Add Hall
    connect(ui->actionAdd_hall, SIGNAL(triggered()), this, SLOT(openAddHallDialogue()));

    //Hall List
     connect(ui->actionHall_List, SIGNAL(triggered()), this, SLOT(openHallListDialogue()));

    //Booking Form
    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), hallView, SLOT(setSeperateSeats(bool)));
    connect(ui->checkBox_separateSeats, SIGNAL(clicked(bool)), this, SLOT(setComboBox(bool)));
    connect(ui->comboBox_numberOfSeats, SIGNAL(currentIndexChanged(int)), hallView, SLOT(setNumberOfSelected(int)));
    connect(ui->lineEdit_phone, SIGNAL(textChanged(QString)), this, SLOT(enableBookButton()));
    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(updateSelectedSeats(QList<int>)));

    //movieSelectionChanged
    connect(ui->listView_movies->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(movieSelectionChanged(QItemSelection,QItemSelection)));

    //showSelectionChanged
    connect(ui->tableView_show->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(showSelectionChanged(QItemSelection,QItemSelection)));

    //bookingSelectionChanged
    connect(ui->tableView_search->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(bookingSelectionChanged(QItemSelection,QItemSelection)));

    //press enter for search instead of search-button
    connect(ui->lineEdit_search, SIGNAL(returnPressed()),ui->pushButton_search,SIGNAL(clicked()));

    //press enter for book instead of book-button
    connect(ui->lineEdit_phone, SIGNAL(returnPressed()),ui->pushButton_hallview_info_book,SIGNAL(clicked()));

    //toggle movie information
    ui->widget_info->addAction(ui->actionInformation);
    connect(ui->actionInformation, SIGNAL(triggered(bool)), this, SLOT(setWidgetsVisible(bool)));

    //toggle bookings table
    ui->widget_bookings->addAction(ui->actionBookings);
    connect(ui->actionBookings, SIGNAL(triggered(bool)), this, SLOT(setWidgetsVisible(bool)));


}

void MainWindow::setWidgetsVisible(bool visible)
{
    QAction *action = dynamic_cast<QAction*>(this->sender());
    QList<QWidget *> widgetList = action->associatedWidgets();

    if(widgetList.isEmpty() == false)
    {
        for(int i = 0; i < widgetList.size(); i++)
        {
            widgetList.at(i)->setVisible(visible);
        }
    }
}


void MainWindow::on_actionQuit_triggered()
{
    //Exit program
    close();
}


void MainWindow::highlightSearchBooking()
{
    ui->lineEdit_search->setFocus();
}

void MainWindow::enableBookButton()
{
    bool isInt;
    ui->lineEdit_phone->text().toInt(&isInt);

    if(hallView->getSelectedSeats().size() > 0 && ui->lineEdit_phone->text().size() >= 5 && isInt == true)
    {
        ui->pushButton_hallview_info_book->setEnabled(true);
        ui->actionBook->setEnabled(true);
    }
    else
    {
        ui->pushButton_hallview_info_book->setEnabled(false);
        ui->actionBook->setEnabled(false);
    }
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
    hallPopup.setWindowTitle("Add Hall");
    QObject::connect(&hallPopup, SIGNAL(addHall(QString,QString,QString,QList<QList<bool> >)),this, SLOT(addHall(QString,QString,QString,QList<QList<bool> >)));

    hallPopup.setModal(true);
    hallPopup.exec();
}

void MainWindow::openHallListDialogue()
{
    hall_list hallPopup(hallModel);
    hallPopup.setModal(true);
    hallPopup.exec();
    seatModel->refresh();
    showModel->refresh();
    bookingModel->refresh();
    hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());
}

void MainWindow::openAddMovieDialogue()
{
    //declare the popup window
    add_Movie am;

    //connect it with the add_Movie signal from the popup
    QObject::connect(&am, SIGNAL(addMovie(QString, int, int, QString, QString, int, QString)),this, SLOT(addMovie(QString, int, int, QString, QString, int, QString)));

    am.setWindowTitle("Add Movie");
    am.setModal(true);

    //launch the add_Movie
    am.exec();
}

void MainWindow::addMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter)
{
    movieModel->insertMovie(title, playtime, age, desc, genre, year, movieposter);
    movieModel->refresh();
}

void MainWindow::addHall(QString name,QString soundSystem,QString screenSize,QList<QList<bool> > seats)
{
    hallModel->insertHall(name,soundSystem,screenSize,seats);
    hallModel->refresh();
}


void MainWindow::openEditMovieDialogue()
{
    int selIndex = getSelected(ui->listView_movies->selectionModel());
    if(selIndex != -1)
    {
        //declare the add_Movie window
        add_Movie am(movieModel->getMovieID(selIndex), movieModel->getTitle(selIndex),
                      movieModel->getPlayTime(selIndex), movieModel->getAgeLimit(selIndex),
                      movieModel->getDescription(selIndex), movieModel->getGenre(selIndex),
                      movieModel->getYear(selIndex), movieModel->getMoviePoster(selIndex));

        //connect it with the add_Movie signal from the add_Movie
        QObject::connect(&am, SIGNAL(editMovie(int, QString, int, int, QString, QString, int, QString)),
                         this, SLOT(editMovie(int, QString, int, int, QString, QString, int, QString)));

        am.setModal(true);
        am.setWindowTitle("Edit Movie");

        //launch the add_Movie
        am.exec();
    }
}

void MainWindow::editMovie(int movieID, QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter)
{
    int selMovieIndex = getSelected(ui->listView_movies->selectionModel());
    int selShowIndex = getSelected(ui->tableView_show->selectionModel());

    //edit movie
    movieModel->editMovie(movieID, title, playtime, age, desc, genre, year, movieposter);

    //refresh views
    movieModel->refresh();
    bookingModel->refresh();

    //select the items
    QModelIndex index = movieModel->index(selMovieIndex, MovieModel::Title);
    if(index.isValid())
    {
        ui->listView_movies->selectionModel()->select(index, QItemSelectionModel::Select);
    }

    index = showModel->index(selShowIndex, ShowModel::DateTime);
    if(index.isValid())
    {
        ui->tableView_show->selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

void MainWindow::deleteMovie()
{
    if(getSelected(ui->listView_movies->selectionModel())!=(-1))
    {
        QMessageBox msgBox(QMessageBox::Question,
                           "Delete Movie",
                           "Are you sure you want to delete this movie?"
                           "\n\nWarning: All shows and bookings connected to this movie will also be deleted.",
                           QMessageBox::Yes | QMessageBox::No
                           );
        if(msgBox.exec() == QMessageBox::Yes)
        {
            movieModel->removeRow(getSelected(ui->listView_movies->selectionModel()));
            movieModel->refresh();
            showModel->refresh();
            bookingModel->refresh();
            seatModel->refresh();
            hallModel->refresh();
            hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());
            setHTML();
        }
    }
}

void MainWindow::setHTML()
{
    int selIndex = getSelected(ui->listView_movies->selectionModel());

    if(selIndex==(-1))
    {
        ui->movie_info->setHtml("");
    }

    else
    {
        QString img;
        if(!movieModel->getMoviePoster(selIndex).isEmpty()
                && ui->movie_info->width() > 280)
        {
            img = "<img src='" + movieModel->getMoviePoster(selIndex) + "' width='150'/>";
        }

        ui->movie_info->setHtml
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

void MainWindow::openAddShowDialog()
{

    if(movieModel->rowCount() < 1 || hallModel->rowCount() < 1)
    {
        QMessageBox msgBox(QMessageBox::Information,
                           "Wrong",
                           "You need to add movies and halls before adding a show.",
                           QMessageBox::Ok
                           );
        msgBox.exec();
    }
    else
    {
        int selMovieIndex = ui->listView_movies->currentIndex().row();
        addShowDialog showDialog(movieModel, hallModel, selMovieIndex);
        connect(&showDialog, SIGNAL(add_Show(QDateTime,double,QString,bool,bool,int,int)), this, SLOT(addShow(QDateTime,double,QString,bool,bool,int,int)));
        showDialog.setWindowTitle("Add Show");
        showDialog.exec();
    }
}


void MainWindow::addShow(QDateTime dateTime, double price, QString lang, bool DDD, bool subs, int movieID, int hallID)
{
    showModel->insertShow(dateTime, price, DDD, subs, lang, movieID, hallID);
    showModel->refresh();
}

void MainWindow::deleteShow()
{
    int select = getSelected(ui->tableView_show->selectionModel());

    if(select!=(-1))
    {
        QMessageBox msgBox(QMessageBox::Question,
                           "Delete Show",
                           "Are you sure you want to delete this show?"
                           "\n\nWarning: All bookings connected to this show will also be deleted.",
                           QMessageBox::Yes | QMessageBox::No
                           );
        if(msgBox.exec() == QMessageBox::Yes)
        {
            showModel->removeRow(select);
            showModel->refresh();
            bookingModel->refresh();
            seatModel->refresh();
            hallModel->refresh();
            hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());
        }
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

void MainWindow::addBooking()
{
    QString phone = ui->lineEdit_phone->text();
    int selShowIndex = getSelected(ui->tableView_show->selectionModel());
    int showID = showModel->getShowID(selShowIndex);
    QList<int> seatIDs = hallView->getSelectedSeats();
    for(int i = 0; i < seatIDs.size(); i++)
    {
        seatIDs[i] = seatModel->getSeatID(seatIDs.at(i)-1);
    }
    if(!phone.isEmpty() && showID > 0 && !seatIDs.isEmpty()) //check if valid booking
    {
        bookingModel->insertBookings(showID, seatIDs, phone);
        bookingModel->refresh();
        showModel->refresh();
        ui->tableView_show->setCurrentIndex(showModel->index(selShowIndex, 0));

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
    bookingSelectionChanged(QItemSelection(),QItemSelection());
}

void MainWindow::on_comboBox_search_currentIndexChanged(int index)
{
    Q_UNUSED(index);

    filterBookings();
}

void MainWindow::movieSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected)

    int selIndex = getSelected(selected);

    if(selIndex == -1)
    {
        //disable delete and edit buttons
        ui->pushButton_movies_delete->setDisabled(true);
        ui->pushButton_info_edit->setDisabled(true);
        ui->actionDelete_movie->setDisabled(true);
    }
    else
    {
        //enable delete and edit buttons
        ui->pushButton_movies_delete->setEnabled(true);
        ui->pushButton_info_edit->setEnabled(true);
        ui->actionDelete_movie->setEnabled(true);
    }

    setHTML();

    filterShows(selIndex, ui->comboBox_shows->currentIndex());

    showSelectionChanged(QItemSelection(), QItemSelection());
}

void MainWindow::showSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected)

    //get selected show
    int selIndex = getSelected(selected);

    //update bookings table
    filterBookings();

    //set seatModel to selected show
    seatModel->setHall(showModel->getHallID(selIndex));
    seatModel->setShow(showModel->getShowID(selIndex));
    seatModel->refresh();

    //display seats in hallView
    hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());

    //set hall info labels
    if(selIndex == -1)
    {
        //Hide hall info labels
        ui->label_hallinfo_title->setText("");
        ui->label_hallinfo->setText("");

        //Disable edit
        ui->pushButton_show_edit->setDisabled(true);
        ui->actionEdit_Show->setDisabled(true);

        //Disable delete
        ui->pushButton_show_delete->setDisabled(true);
        ui->actionDelete_show->setDisabled(true);
    }
    else
    {
        //Set hall info labels
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

        //Enable edit
        ui->pushButton_show_edit->setEnabled(true);
        ui->actionEdit_Show->setEnabled(true);

        //Enable delete
        ui->pushButton_show_delete->setEnabled(true);
        ui->actionDelete_show->setEnabled(true);
    }
}

void MainWindow::on_pushButton_hallview_info_clear_clicked()
{
    hallView->clearSelectedSeats();
    ui->lineEdit_phone->QLineEdit::clear();
}

void MainWindow::deleteBooking()
{
    int selIndex = getSelected(ui->tableView_search->selectionModel());

    if(selIndex != -1)
    {
        QMessageBox msgBox(QMessageBox::Question,
                           "Delete Booking",
                           "Are you sure you want to delete this booking?",
                           QMessageBox::Yes | QMessageBox::No
                           );
        if(msgBox.exec() == QMessageBox::Yes)
        {
            bookingModel->removeRow(selIndex);
            bookingModel->refresh();
            seatModel->refresh();
            hallModel->refresh();
            hallView->setHall(seatModel->getSeatStateMatrix(), seatModel->getMaxRow(), seatModel->getMaxColumn());
        }
    }
}

void MainWindow::bookingSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected)
    int selIndex = getSelected(selected);

    if(selIndex == -1)
    {
        ui->pushButton_bookings_delete->setDisabled(true);
    }
    else
    {
        ui->pushButton_bookings_delete->setEnabled(true);
    }
}

void MainWindow::on_comboBox_shows_currentIndexChanged(int index)
{
    filterShows(getSelected(ui->listView_movies->selectionModel()), index);
}

void MainWindow::filterShows(int selectedMovie, int showFilterIndex)
{
    QString filter;
    QList<QVariant> placeholders;

    if(selectedMovie != -1)
    {
        filter = "MovieID = ?";

        if(showFilterIndex <3)
            filter.append(" AND ");

        placeholders.append(movieModel->getMovieID(selectedMovie));
    }

    switch(showFilterIndex)
    {
    case 0: filter += "DateTime > ?"; //Comming
        placeholders.append(QDateTime::currentDateTime());
        break;
    case 1: filter += "DateTime BETWEEN ? AND ?"; //Today
        placeholders.append(QDateTime(QDate::currentDate()));
        placeholders.append(QDateTime(QDate::currentDate().addDays(1)));
        break;
    case 2: filter += "DateTime BETWEEN ? AND ?"; //This Week
        placeholders.append(QDateTime(QDate::currentDate()));
        placeholders.append(QDateTime(QDate::currentDate().addDays(7)));
        break;
    case 3: //All Time
    default:
        break;
    }

    if(filter.isEmpty())
    {
        showModel->clearFilter();
    }
    else
    {
        showModel->setFilter(filter, placeholders);
    }
}

void MainWindow::openEditShowDialogue()
{
    int selIndex = getSelected(ui->tableView_show->selectionModel());
    if(selIndex != -1)
    {
        //declare the popup window
        addShowDialog showPopup(movieModel, hallModel,
                                showModel->getShowID(selIndex), showModel->getDateTime(selIndex),
                                showModel->getPrice(selIndex), showModel->getLanguage(selIndex),
                                showModel->get3D(selIndex), showModel->getSubtitles(selIndex),
                                showModel->getMovieID(selIndex), showModel->getHallID(selIndex));

        showPopup.setWindowTitle("Edit Show");

        QObject::connect(&showPopup, SIGNAL(edit_show(int,QDateTime,double,QString,bool,bool,int,int)),
                         this, SLOT(editShow(int,QDateTime,double,QString,bool,bool,int,int)));

        showPopup.setModal(true);

        showPopup.exec();
    }
}

void MainWindow::editShow(int showID, QDateTime dateTime, double price, QString lang, bool DDD, bool subs, int movieID, int hallID)
{
    int selIndex = getSelected(ui->tableView_show->selectionModel());
    showModel->editShow(showID, dateTime, price, DDD, subs, lang, movieID, hallID);
    showModel->refresh();
    if(selIndex != -1)
    {
        QModelIndex index = showModel->index(selIndex, 0);
        ui->tableView_show->setCurrentIndex(index);
    }
}
