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
    void movieSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void showSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    //add movie
    void openAddMovieDialogue();
    void addMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);

    //delete movie
    void on_pushButton_movies_delete_clicked();

    //edit movie
    void openEditMovieDialogue(const QModelIndex &index);
    void editMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);

    void on_actionQuit_triggered();

    void on_pushButton_info_edit_clicked();

    void on_pushButton_show_add_clicked();

    void on_pushButton_show_delete_clicked();

    void on_pushButton_search_clicked();

    void setHTML();

    void on_pushButton_hallview_info_book_clicked();

    void on_comboBox_search_currentIndexChanged(int index);

    void openAddHallDialogue();

    void updateSelectedSeats(QList<int> seats);

    void setComboBox(bool);

    void enableBookButton();

    void on_pushButton_hallview_info_clear_clicked();

    void keyPressEvent( QKeyEvent * event );

private:
    Ui::MainWindow *ui;
    HallView *hallView;

    MovieModel *movieModel;
    ShowModel *showModel;
    HallModel *hallModel;
    SeatModel *seatModel;
    BookingModel * bookingModel;

    void initConnections();
    void filterBookings();
    int getSelected(const QItemSelection &selection);
    int getSelected(QItemSelectionModel *selectionModel);

};

#endif // MAINWINDOW_H
