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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_hall
{
public:
    QFrame *frame_rows_columns;
    QFrame *frame_hall;
    QLabel *label_number_of_seats;
    QTableView *tableView_edit_hall;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *CloseButton;
    QPushButton *EditButton;
    QPushButton *DeleteButton;

    void setupUi(QWidget *edit_hall)
    {
        if (edit_hall->objectName().isEmpty())
            edit_hall->setObjectName(QStringLiteral("edit_hall"));
        edit_hall->resize(858, 469);
        edit_hall->setMinimumSize(QSize(858, 469));
        edit_hall->setMaximumSize(QSize(858, 469));
        frame_rows_columns = new QFrame(edit_hall);
        frame_rows_columns->setObjectName(QStringLiteral("frame_rows_columns"));
        frame_rows_columns->setGeometry(QRect(20, 10, 441, 431));
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
        frame_hall->setGeometry(QRect(0, 0, 441, 371));
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
        label_number_of_seats = new QLabel(frame_rows_columns);
        label_number_of_seats->setObjectName(QStringLiteral("label_number_of_seats"));
        label_number_of_seats->setGeometry(QRect(10, 390, 91, 21));
        QFont font;
        font.setPointSize(12);
        label_number_of_seats->setFont(font);
        tableView_edit_hall = new QTableView(edit_hall);
        tableView_edit_hall->setObjectName(QStringLiteral("tableView_edit_hall"));
        tableView_edit_hall->setGeometry(QRect(470, 10, 371, 371));
        tableView_edit_hall->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_edit_hall->verticalHeader()->setVisible(false);
        tableView_edit_hall->verticalHeader()->setDefaultSectionSize(20);
        widget = new QWidget(edit_hall);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(620, 430, 231, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CloseButton = new QPushButton(widget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        horizontalLayout->addWidget(CloseButton);

        EditButton = new QPushButton(widget);
        EditButton->setObjectName(QStringLiteral("EditButton"));

        horizontalLayout->addWidget(EditButton);

        DeleteButton = new QPushButton(widget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);


        retranslateUi(edit_hall);

        QMetaObject::connectSlotsByName(edit_hall);
    } // setupUi

    void retranslateUi(QWidget *edit_hall)
    {
        edit_hall->setWindowTitle(QApplication::translate("edit_hall", "Hall List", 0));
        label_number_of_seats->setText(QApplication::translate("edit_hall", "Seats:", 0));
        CloseButton->setText(QApplication::translate("edit_hall", "Close", 0));
        EditButton->setText(QApplication::translate("edit_hall", "Edit", 0));
        DeleteButton->setText(QApplication::translate("edit_hall", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_hall: public Ui_edit_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_HALL_H
