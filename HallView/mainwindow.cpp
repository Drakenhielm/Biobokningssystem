#include <QtWidgets>

#include "HallView.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *centralWidget = new QWidget;

    hallview = new HallView;

    QLabel *rowsLabel = new QLabel(tr("Rader"));
    QSpinBox *rowSpinBox = new QSpinBox;
        rowSpinBox->setRange(1, 25);
        rowSpinBox->setSingleStep(1);
        rowSpinBox->setValue(5);
    QLabel *columnsnLabel = new QLabel(tr("Kolumner"));
    QSpinBox *columnSpinBox = new QSpinBox;
        columnSpinBox->setRange(1, 25);
        columnSpinBox->setSingleStep(1);
        columnSpinBox->setValue(5);

    connect(rowSpinBox, SIGNAL(valueChanged(int)),
            hallview, SLOT(setRows(int)));
    connect(columnSpinBox, SIGNAL(valueChanged(int)),
            hallview, SLOT(setColumns(int)));

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(hallview);
    centralLayout->addWidget(rowsLabel);
    centralLayout->addWidget(rowSpinBox);
    centralLayout->addWidget(columnsnLabel);
    centralLayout->addWidget(columnSpinBox);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("HallView prototyp"));
}
