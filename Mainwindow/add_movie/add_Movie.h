#ifndef ADD_MOVIE_H
#define ADD_MOVIE_H

#include <QDialog>
#include <QDir>
#include <QDebug>

namespace Ui {
class add_Movie;
}

class add_Movie : public QDialog
{
    Q_OBJECT

public:
    explicit add_Movie(QWidget *parent = 0);
    explicit add_Movie(int movieID, QString title, int playtime, int age, QString desc, QString genre,
                   int year, QString movieposter, QWidget *parent = 0);
    ~add_Movie();


private slots:
    void on_AddGenreButton_clicked();

    void updateCurrentGenre(QString);

    void on_CancelButton_clicked();

    void on_RemoveGenreButton_clicked();

    void on_AddButton_clicked();

    void on_ExploreButton_clicked();

signals:
    void addMovie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);
    void editMovie(int movieID, QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);

private:
    Ui::add_Movie *ui;
    QDir directory;
    enum Role { Add, Edit } role;
    int movieID; //used in edit mode
    QVector<QString> genres;
    void removeGenresFromCbb(const QString &genreStr);
};

#endif // ADD_MOVIE_H
