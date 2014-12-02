/********************************************************************************
** Form generated from reading UI file 'hall.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALL_H
#define UI_HALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_hall
{
public:
    QPushButton *AddButton;
    QFrame *frame_rows_columns;
    QFrame *frame_hall;
    QSpinBox *spinBox_rows;
    QSpinBox *spinBox_columns;
    QLabel *label_rows;
    QLabel *label_columns;
    QLabel *label_hall_name;
    QLabel *label_sound_system;
    QLabel *label_screen_size;
    QLineEdit *hall_name;
    QComboBox *comboBox_sound;
    QSpinBox *spinBox_screen_width;
    QSpinBox *spinBox_screen_height;
    QLabel *label_6;

    void setupUi(QDialog *hall)
    {
        if (hall->objectName().isEmpty())
            hall->setObjectName(QStringLiteral("hall"));
        hall->resize(858, 469);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hall->sizePolicy().hasHeightForWidth());
        hall->setSizePolicy(sizePolicy);
        AddButton = new QPushButton(hall);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(749, 420, 81, 31));
        QFont font;
        font.setPointSize(12);
        AddButton->setFont(font);
        frame_rows_columns = new QFrame(hall);
        frame_rows_columns->setObjectName(QStringLiteral("frame_rows_columns"));
        frame_rows_columns->setGeometry(QRect(20, 20, 501, 431));
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
        label_hall_name = new QLabel(hall);
        label_hall_name->setObjectName(QStringLiteral("label_hall_name"));
        label_hall_name->setGeometry(QRect(550, 80, 46, 13));
        label_hall_name->setFont(font);
        label_sound_system = new QLabel(hall);
        label_sound_system->setObjectName(QStringLiteral("label_sound_system"));
        label_sound_system->setGeometry(QRect(550, 120, 111, 16));
        label_sound_system->setFont(font);
        label_screen_size = new QLabel(hall);
        label_screen_size->setObjectName(QStringLiteral("label_screen_size"));
        label_screen_size->setGeometry(QRect(550, 160, 91, 21));
        label_screen_size->setFont(font);
        hall_name = new QLineEdit(hall);
        hall_name->setObjectName(QStringLiteral("hall_name"));
        hall_name->setGeometry(QRect(680, 70, 141, 31));
        hall_name->setFont(font);
        comboBox_sound = new QComboBox(hall);
        comboBox_sound->setObjectName(QStringLiteral("comboBox_sound"));
        comboBox_sound->setGeometry(QRect(680, 110, 141, 31));
        spinBox_screen_width = new QSpinBox(hall);
        spinBox_screen_width->setObjectName(QStringLiteral("spinBox_screen_width"));
        spinBox_screen_width->setGeometry(QRect(710, 160, 42, 22));
        spinBox_screen_width->setFont(font);
        spinBox_screen_height = new QSpinBox(hall);
        spinBox_screen_height->setObjectName(QStringLiteral("spinBox_screen_height"));
        spinBox_screen_height->setGeometry(QRect(780, 160, 42, 22));
        spinBox_screen_height->setFont(font);
        label_6 = new QLabel(hall);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(760, 160, 16, 21));
        label_6->setFont(font);

        retranslateUi(hall);

        QMetaObject::connectSlotsByName(hall);
    } // setupUi

    void retranslateUi(QDialog *hall)
    {
        hall->setWindowTitle(QApplication::translate("hall", "Add hall", 0));
        AddButton->setText(QApplication::translate("hall", "Add", 0));
        label_rows->setText(QApplication::translate("hall", "Rows:", 0));
        label_columns->setText(QApplication::translate("hall", "Columns:", 0));
        label_hall_name->setText(QApplication::translate("hall", "Name:", 0));
        label_sound_system->setText(QApplication::translate("hall", "Sound system:", 0));
        label_screen_size->setText(QApplication::translate("hall", "Screen size:", 0));
        comboBox_sound->clear();
        comboBox_sound->insertItems(0, QStringList()
         << QApplication::translate("hall", "Dolby", 0)
         << QApplication::translate("hall", "Dolby Atmos", 0)
         << QApplication::translate("hall", "Dolby Digital", 0)
         << QApplication::translate("hall", "Dolby Digital EX", 0)
         << QApplication::translate("hall", "Dolby SR", 0)
         << QApplication::translate("hall", "Dolby Surround 7.1", 0)
         << QApplication::translate("hall", "DTS", 0)
         << QApplication::translate("hall", "New Item", 0)
        );
        label_6->setText(QApplication::translate("hall", "X", 0));
    } // retranslateUi

};

namespace Ui {
    class hall: public Ui_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALL_H
