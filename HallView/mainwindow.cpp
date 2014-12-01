#include <QtWidgets>

#include "HallView.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *centralWidget = new QWidget;

    hallview = new HallView;

    QLabel *rowsLabel = new QLabel(tr("Rows"));
    QSpinBox *rowSpinBox = new QSpinBox;
        rowSpinBox->setRange(1, 25);
        rowSpinBox->setSingleStep(1);
        rowSpinBox->setValue(5);
    QLabel *columnsLabel = new QLabel(tr("Columns"));
    QSpinBox *columnSpinBox = new QSpinBox;
        columnSpinBox->setRange(1, 25);
        columnSpinBox->setSingleStep(1);
        columnSpinBox->setValue(5);
    QLabel *seatsLabel = new QLabel(tr("Seats"));
    QSpinBox *seatsSpinBox = new QSpinBox;
        seatsSpinBox->setRange(1, 8);
        seatsSpinBox->setSingleStep(1);
        seatsSpinBox->setValue(1);

    connect(rowSpinBox, SIGNAL(valueChanged(int)),
            hallview, SLOT(setRows(int)));
    connect(columnSpinBox, SIGNAL(valueChanged(int)),
            hallview, SLOT(setColumns(int)));
    connect(seatsSpinBox, SIGNAL(valueChanged(int)),
            hallview, SLOT(setMultiplySelectes(int)));

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(hallview);
    centralLayout->addWidget(rowsLabel);
    centralLayout->addWidget(rowSpinBox);
    centralLayout->addWidget(columnsLabel);
    centralLayout->addWidget(columnSpinBox);
    centralLayout->addWidget(seatsLabel);
    centralLayout->addWidget(seatsSpinBox);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("HallView prototyp"));
}
