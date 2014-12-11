/********************************************************************************
** Form generated from reading UI file 'addshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSHOWDIALOG_H
#define UI_ADDSHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addShowDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addShowButton;
    QPushButton *cancelShowButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *movieLabel;
    QComboBox *movieCBB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *hallLabel;
    QComboBox *hallCBB;
    QVBoxLayout *verticalLayout;
    QLabel *dateLabel;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *timeLabel;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *DDDLabel;
    QRadioButton *DDDYesRB;
    QRadioButton *DDDNoRB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *subLabel;
    QRadioButton *subYesRB;
    QRadioButton *subNoRB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *languageLabel;
    QComboBox *languageCBB;
    QHBoxLayout *horizontalLayout_8;
    QLabel *priceLabel;
    QSpinBox *priceSpinBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *addShowDialog)
    {
        if (addShowDialog->objectName().isEmpty())
            addShowDialog->setObjectName(QStringLiteral("addShowDialog"));
        addShowDialog->resize(431, 623);
        addShowDialog->setMinimumSize(QSize(431, 623));
        addShowDialog->setMaximumSize(QSize(431, 623));
        layoutWidget = new QWidget(addShowDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 550, 169, 32));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        addShowButton = new QPushButton(layoutWidget);
        addShowButton->setObjectName(QStringLiteral("addShowButton"));

        horizontalLayout_7->addWidget(addShowButton);

        cancelShowButton = new QPushButton(layoutWidget);
        cancelShowButton->setObjectName(QStringLiteral("cancelShowButton"));

        horizontalLayout_7->addWidget(cancelShowButton);

        widget = new QWidget(addShowDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 21, 351, 511));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        movieLabel = new QLabel(widget);
        movieLabel->setObjectName(QStringLiteral("movieLabel"));

        horizontalLayout->addWidget(movieLabel);

        movieCBB = new QComboBox(widget);
        movieCBB->setObjectName(QStringLiteral("movieCBB"));

        horizontalLayout->addWidget(movieCBB);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        hallLabel = new QLabel(widget);
        hallLabel->setObjectName(QStringLiteral("hallLabel"));

        horizontalLayout_2->addWidget(hallLabel);

        hallCBB = new QComboBox(widget);
        hallCBB->setObjectName(QStringLiteral("hallCBB"));

        horizontalLayout_2->addWidget(hallCBB);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dateLabel = new QLabel(widget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        verticalLayout->addWidget(dateLabel);

        calendarWidget = new QCalendarWidget(widget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        horizontalLayout_6->addWidget(timeLabel);

        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_6->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DDDLabel = new QLabel(widget);
        DDDLabel->setObjectName(QStringLiteral("DDDLabel"));

        horizontalLayout_3->addWidget(DDDLabel);

        DDDYesRB = new QRadioButton(widget);
        buttonGroup = new QButtonGroup(addShowDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(DDDYesRB);
        DDDYesRB->setObjectName(QStringLiteral("DDDYesRB"));

        horizontalLayout_3->addWidget(DDDYesRB);

        DDDNoRB = new QRadioButton(widget);
        buttonGroup->addButton(DDDNoRB);
        DDDNoRB->setObjectName(QStringLiteral("DDDNoRB"));

        horizontalLayout_3->addWidget(DDDNoRB);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        subLabel = new QLabel(widget);
        subLabel->setObjectName(QStringLiteral("subLabel"));

        horizontalLayout_4->addWidget(subLabel);

        subYesRB = new QRadioButton(widget);
        buttonGroup_2 = new QButtonGroup(addShowDialog);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(subYesRB);
        subYesRB->setObjectName(QStringLiteral("subYesRB"));

        horizontalLayout_4->addWidget(subYesRB);

        subNoRB = new QRadioButton(widget);
        buttonGroup_2->addButton(subNoRB);
        subNoRB->setObjectName(QStringLiteral("subNoRB"));

        horizontalLayout_4->addWidget(subNoRB);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        languageLabel = new QLabel(widget);
        languageLabel->setObjectName(QStringLiteral("languageLabel"));

        horizontalLayout_5->addWidget(languageLabel);

        languageCBB = new QComboBox(widget);
        languageCBB->setObjectName(QStringLiteral("languageCBB"));

        horizontalLayout_5->addWidget(languageCBB);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        priceLabel = new QLabel(widget);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));

        horizontalLayout_8->addWidget(priceLabel);

        priceSpinBox = new QSpinBox(widget);
        priceSpinBox->setObjectName(QStringLiteral("priceSpinBox"));
        priceSpinBox->setMaximum(999);

        horizontalLayout_8->addWidget(priceSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(addShowDialog);

        QMetaObject::connectSlotsByName(addShowDialog);
    } // setupUi

    void retranslateUi(QDialog *addShowDialog)
    {
        addShowDialog->setWindowTitle(QApplication::translate("addShowDialog", "Dialog", 0));
        addShowButton->setText(QApplication::translate("addShowDialog", "Submit", 0));
        cancelShowButton->setText(QApplication::translate("addShowDialog", "Cancel", 0));
        movieLabel->setText(QApplication::translate("addShowDialog", "Movie", 0));
        hallLabel->setText(QApplication::translate("addShowDialog", "Hall", 0));
        dateLabel->setText(QApplication::translate("addShowDialog", "Date", 0));
        timeLabel->setText(QApplication::translate("addShowDialog", "Time", 0));
        DDDLabel->setText(QApplication::translate("addShowDialog", "3D", 0));
        DDDYesRB->setText(QApplication::translate("addShowDialog", "Yes", 0));
        DDDNoRB->setText(QApplication::translate("addShowDialog", "No", 0));
        subLabel->setText(QApplication::translate("addShowDialog", "Subtitles", 0));
        subYesRB->setText(QApplication::translate("addShowDialog", "Yes", 0));
        subNoRB->setText(QApplication::translate("addShowDialog", "No", 0));
        languageLabel->setText(QApplication::translate("addShowDialog", "Language", 0));
        languageCBB->clear();
        languageCBB->insertItems(0, QStringList()
         << QApplication::translate("addShowDialog", "English", 0)
         << QApplication::translate("addShowDialog", "French", 0)
         << QApplication::translate("addShowDialog", "German", 0)
         << QApplication::translate("addShowDialog", "Spanish", 0)
         << QApplication::translate("addShowDialog", "Swedish", 0)
        );
        priceLabel->setText(QApplication::translate("addShowDialog", "Price", 0));
    } // retranslateUi

};

namespace Ui {
    class addShowDialog: public Ui_addShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSHOWDIALOG_H
