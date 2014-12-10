#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QDir>
#include <QDebug>

namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = 0);
    explicit popup(int movieID, QString title, int playtime, int age, QString desc, QString genre,
                   int year, QString movieposter, QWidget *parent = 0);
    ~popup();


private slots:
    void on_AddGenreButton_clicked();

    void updateCurrentGenre(QString);

    void on_CancelButton_clicked();

    void on_RemoveGenreButton_clicked();

    void on_AddButton_clicked();

    void on_ExploreButton_clicked();

signals:
    void add_Movie(QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);
    void edit_Movie(int movieID, QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter);

    //QString title, int playtime, int age, QString desc, QString genre, int year, QString movieposter

private:
    Ui::popup *ui;
    QDir directory;
    enum Role { Add, Edit } role;
    int movieID; //used in edit mode

    void removeGenresFromCbb(const QString &genreStr);
};

#endif // POPUP_H
