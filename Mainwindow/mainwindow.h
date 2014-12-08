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
    void addShow();
    //Delete Show
    void deleteShow();
    //Edit Show
    //void openEditShowDialogue();
    //void editShow();

    //Add Booking
    void on_pushButton_hallview_info_book_clicked();

    //Delete Booking
    void deleteBooking();

    //Search Booking
    void on_pushButton_search_clicked();
    void on_comboBox_search_currentIndexChanged(int index);

    //Add Hall
    void openAddHallDialogue();

    void openEditHallDialogue();

    void updateSelectedSeats(QList<int> seats);

    void setComboBox(bool);

    void enableBookButton();

    void on_pushButton_hallview_info_clear_clicked();

    void keyPressEvent( QKeyEvent * event );

    //Quit
    void on_actionQuit_triggered();

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

    void filterBookings();
    void setHTML();
    int getSelected(const QItemSelection &selection);
    int getSelected(QItemSelectionModel *selectionModel);

};

#endif // MAINWINDOW_H
