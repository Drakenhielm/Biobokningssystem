#ifndef CONFIRMADDMOVIE_H
#define CONFIRMADDMOVIE_H

#include <QDialog>

namespace Ui {
class confirmAddMovie;
}

class confirmAddMovie : public QDialog
{
    Q_OBJECT

public:
    explicit confirmAddMovie(QWidget *parent = 0);
    ~confirmAddMovie();

private:
    Ui::confirmAddMovie *ui;
};

#endif // CONFIRMADDMOVIE_H
