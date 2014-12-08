/********************************************************************************
** Form generated from reading UI file 'edit_hall.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_HALL_H
#define UI_EDIT_HALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_hall
{
public:
    QFrame *frame_rows_columns;
    QFrame *frame_hall;
    QSpinBox *spinBox_rows;
    QSpinBox *spinBox_columns;
    QLabel *label_rows;
    QLabel *label_columns;
    QLabel *label_number_of_seats;
    QPushButton *DeleteButton;
    QTableView *tableView_edit_hall;

    void setupUi(QWidget *edit_hall)
    {
        if (edit_hall->objectName().isEmpty())
            edit_hall->setObjectName(QStringLiteral("edit_hall"));
        edit_hall->resize(858, 469);
        frame_rows_columns = new QFrame(edit_hall);
        frame_rows_columns->setObjectName(QStringLiteral("frame_rows_columns"));
        frame_rows_columns->setGeometry(QRect(20, 10, 501, 431));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame_rows_columns->setPalette(palette);
        frame_rows_columns->setAutoFillBackground(true);
        frame_rows_columns->setFrameShape(QFrame::StyledPanel);
        frame_rows_columns->setFrameShadow(QFrame::Plain);
        frame_hall = new QFrame(frame_rows_columns);
        frame_hall->setObjectName(QStringLiteral("frame_hall"));
        frame_hall->setGeometry(QRect(0, 0, 501, 371));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame_hall->setPalette(palette1);
        frame_hall->setAutoFillBackground(true);
        frame_hall->setFrameShape(QFrame::StyledPanel);
        frame_hall->setFrameShadow(QFrame::Sunken);
        spinBox_rows = new QSpinBox(frame_rows_columns);
        spinBox_rows->setObjectName(QStringLiteral("spinBox_rows"));
        spinBox_rows->setGeometry(QRect(310, 390, 41, 21));
        QFont font;
        font.setPointSize(12);
        spinBox_rows->setFont(font);
        spinBox_rows->setMinimum(1);
        spinBox_rows->setMaximum(25);
        spinBox_rows->setValue(5);
        spinBox_columns = new QSpinBox(frame_rows_columns);
        spinBox_columns->setObjectName(QStringLiteral("spinBox_columns"));
        spinBox_columns->setGeometry(QRect(440, 390, 42, 22));
        spinBox_columns->setFont(font);
        spinBox_columns->setMinimum(1);
        spinBox_columns->setMaximum(25);
        spinBox_columns->setValue(5);
        label_rows = new QLabel(frame_rows_columns);
        label_rows->setObjectName(QStringLiteral("label_rows"));
        label_rows->setGeometry(QRect(260, 390, 51, 21));
        label_rows->setFont(font);
        label_columns = new QLabel(frame_rows_columns);
        label_columns->setObjectName(QStringLiteral("label_columns"));
        label_columns->setGeometry(QRect(370, 390, 71, 21));
        label_columns->setFont(font);
        label_number_of_seats = new QLabel(frame_rows_columns);
        label_number_of_seats->setObjectName(QStringLiteral("label_number_of_seats"));
        label_number_of_seats->setGeometry(QRect(10, 390, 91, 21));
        label_number_of_seats->setFont(font);
        DeleteButton = new QPushButton(edit_hall);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(730, 400, 81, 31));
        DeleteButton->setFont(font);
        tableView_edit_hall = new QTableView(edit_hall);
        tableView_edit_hall->setObjectName(QStringLiteral("tableView_edit_hall"));
        tableView_edit_hall->setGeometry(QRect(530, 10, 311, 371));

        retranslateUi(edit_hall);

        QMetaObject::connectSlotsByName(edit_hall);
    } // setupUi

    void retranslateUi(QWidget *edit_hall)
    {
        edit_hall->setWindowTitle(QApplication::translate("edit_hall", "Hall List", 0));
        label_rows->setText(QApplication::translate("edit_hall", "Rows:", 0));
        label_columns->setText(QApplication::translate("edit_hall", "Columns:", 0));
        label_number_of_seats->setText(QApplication::translate("edit_hall", "Seats:", 0));
        DeleteButton->setText(QApplication::translate("edit_hall", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_hall: public Ui_edit_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_HALL_H
