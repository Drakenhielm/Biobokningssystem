#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/moviemodel.h"
#include "Model/showmodel.h"
#include "Model/hallmodel.h"
#include "Model/seatmodel.h"
#include "Model/bookingmodel.h"
#include <QItemSelection>
#include "hallview.h"
#include "add_hall/hall.h"
#include "add_movie/popup.h"
#include "add_show/addshowdialog.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //SelectionChanged slots for TableViews and ListViews
    void movieSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void showSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void bookingSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    //Add Movie
    void openAddMovieDialogue();
    void addMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);
    //Delete Movie
    void deleteMovie();
    //Edit Movie
    void openEditMovieDialogue();
    void editMovie(int movieID, QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);

    //Add Show
    void openAddShowDialog();
    void addShow(QDateTime dateTime, double price, QString lang, bool DDD, bool subs, int movieID, int hallID);
    //Delete Show
    void deleteShow();
    //Edit Show
    //void openEditShowDialogue();
    //void editShow();
    //Filter shows
    void on_comboBox_shows_currentIndexChanged(int index);

    //Add Booking
    void on_pushButton_hallview_info_book_clicked();

    //Delete Booking
    void deleteBooking();

    //Search Booking
    void on_pushButton_search_clicked();
    void on_comboBox_search_currentIndexChanged(int index);
    void highlightSearchBooking();

    //Add Hall
    void openAddHallDialogue();
    void addHall(QString name,QString soundSystem,QString screenSize,QList<QList<bool> > seats);
    void openEditHallDialogue();

    void updateSelectedSeats(QList<int> seats);

    void setComboBox(bool);

    void enableBookButton();

    void on_pushButton_hallview_info_clear_clicked();

    //Quit
    void on_actionQuit_triggered();

    void hideShow();

private:
    Ui::MainWindow *ui;
    HallView *hallView;

    MovieModel *movieModel;
    ShowModel *showModel;
    HallModel *hallModel;
    SeatModel *seatModel;
    BookingModel * bookingModel;

    void initConnections();
    void initModels();
    void initViews();

    void setHTML();

    void filterBookings();
    void filterShows(int selectedMovie, int showFilterIndex);

    int getSelected(const QItemSelection &selection);
    int getSelected(QItemSelectionModel *selectionModel);


};

#endif // MAINWINDOW_H
