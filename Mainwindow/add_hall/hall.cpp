#include "hall.h"
#include "ui_hall.h"
#include "hallview.h"
#include <QVBoxLayout>

hall::hall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hall)
{
    ui->setupUi(this);
    role = Add;

    initHallView();
    initConnections();
}

hall::hall(int hallID, const QString &name, const QString &screenSize, const QString &soundSystem,
           const QVector<QVector<int> > &seats, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hall)
{
    ui->setupUi(this);
    role = Edit;
    this->hallID = hallID;

    initHallView();
    initConnections();

    ui->hall_name->setText(name);
    QPoint point =  getScreenSizeFromString(screenSize);
    ui->spinBox_screen_width->setValue(point.x());
    ui->spinBox_screen_width->setValue(point.y());
    ui->comboBox_sound->setCurrentText(soundSystem);
    hallView->setHall(seats,seats.size(),seats.at(0).size());
    ui->spinBox_columns->setValue(seats.at(0).size());
    ui->spinBox_rows->setValue(seats.size());

    this->move(165,165);

}

void hall::initConnections()
{
    connect(ui->spinBox_rows, SIGNAL(valueChanged(int)), hallView, SLOT(setRows(int)));
    connect(ui->spinBox_columns, SIGNAL(valueChanged(int)), hallView, SLOT(setColumns(int)));

    connect(hallView, SIGNAL(selectedSeatsChanged(QList<int>)), this, SLOT(setLabelNumberOfSeats()));
}

void hall::initHallView()
{
    hallView = new HallView(this);
    QHBoxLayout *lineLayout = new QHBoxLayout;
    ui->frame_hall->setLayout(lineLayout);
    ui->frame_hall->layout()->addWidget(hallView);
    hallView->setMode(true);

}

hall::~hall()
{

    delete ui;
}

void hall::setLabelNumberOfSeats()
{
    ui->label_number_of_seats->setText("Seats: " + QString::number(hallView->getTotalNumberOfSeats()));
}

void hall::on_AddButton_clicked()
{
    QString hallName = ui->hall_name->text();
    QString screenSize = QString::number(ui->spinBox_screen_width->value()) + " X " + QString::number(ui->spinBox_screen_height->value());
    QString soundSystem = ui->comboBox_sound->currentText();
    QList<QList<bool>> seats = hallView->getSeats();
    if(role == Add)
        emit addHall(hallName, screenSize, soundSystem, seats);
    if(role == Edit)
        emit editHall(hallID, hallName, screenSize, soundSystem, seats);
    close();
}

void hall::on_cancel_Button_clicked()
{
    close();
}

QPoint hall::getScreenSizeFromString(const QString &str)
{
    QPoint point;
    QStringList strList = str.split('x', QString::SkipEmptyParts, Qt::CaseInsensitive);
    if(strList.size() == 2)
    {
        point.setX(strList.at(0).toInt());
        point.setY(strList.at(1).toInt());
    }
    return point;
}
