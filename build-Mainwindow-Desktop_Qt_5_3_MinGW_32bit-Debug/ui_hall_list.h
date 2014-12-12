/********************************************************************************
** Form generated from reading UI file 'hall_list.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALL_LIST_H
#define UI_HALL_LIST_H

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

class Ui_hall_list
{
public:
    QFrame *frame_rows_columns;
    QFrame *frame_hall;
    QLabel *label_number_of_seats;
    QTableView *tableView_hall_list;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *EditButton;
    QPushButton *DeleteButton;
    QPushButton *CloseButton;

    void setupUi(QWidget *hall_list)
    {
        if (hall_list->objectName().isEmpty())
            hall_list->setObjectName(QStringLiteral("hall_list"));
        hall_list->resize(858, 469);
        hall_list->setMinimumSize(QSize(858, 469));
        hall_list->setMaximumSize(QSize(858, 469));
        frame_rows_columns = new QFrame(hall_list);
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
        tableView_hall_list = new QTableView(hall_list);
        tableView_hall_list->setObjectName(QStringLiteral("tableView_hall_list"));
        tableView_hall_list->setGeometry(QRect(470, 10, 371, 371));
        tableView_hall_list->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_hall_list->verticalHeader()->setVisible(false);
        tableView_hall_list->verticalHeader()->setDefaultSectionSize(20);
        layoutWidget = new QWidget(hall_list);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(610, 430, 239, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        EditButton = new QPushButton(layoutWidget);
        EditButton->setObjectName(QStringLiteral("EditButton"));

        horizontalLayout->addWidget(EditButton);

        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);

        CloseButton = new QPushButton(layoutWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        horizontalLayout->addWidget(CloseButton);


        retranslateUi(hall_list);

        QMetaObject::connectSlotsByName(hall_list);
    } // setupUi

    void retranslateUi(QWidget *hall_list)
    {
        hall_list->setWindowTitle(QApplication::translate("hall_list", "Hall List", 0));
        label_number_of_seats->setText(QApplication::translate("hall_list", "Seats:", 0));
        EditButton->setText(QApplication::translate("hall_list", "Edit", 0));
        DeleteButton->setText(QApplication::translate("hall_list", "Delete", 0));
        CloseButton->setText(QApplication::translate("hall_list", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class hall_list: public Ui_hall_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALL_LIST_H
