#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE
class HallView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:

private:
    HallView *hallview;
};

#endif

