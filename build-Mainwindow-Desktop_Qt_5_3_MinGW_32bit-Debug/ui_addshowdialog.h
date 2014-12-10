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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addShowDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *cancelShowButton;
    QPushButton *addShowButton;
    QSplitter *splitter_2;
    QWidget *layoutWidget_2;
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
    QSplitter *splitter;
    QLabel *priceLabel;
    QSpinBox *priceSpinBox;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *addShowDialog)
    {
        if (addShowDialog->objectName().isEmpty())
            addShowDialog->setObjectName(QStringLiteral("addShowDialog"));
        addShowDialog->resize(400, 536);
        layoutWidget = new QWidget(addShowDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 490, 169, 32));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        cancelShowButton = new QPushButton(layoutWidget);
        cancelShowButton->setObjectName(QStringLiteral("cancelShowButton"));

        horizontalLayout_7->addWidget(cancelShowButton);

        addShowButton = new QPushButton(layoutWidget);
        addShowButton->setObjectName(QStringLiteral("addShowButton"));

        horizontalLayout_7->addWidget(addShowButton);

        splitter_2 = new QSplitter(addShowDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(40, 20, 321, 461));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget_2 = new QWidget(splitter_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        movieLabel = new QLabel(layoutWidget_2);
        movieLabel->setObjectName(QStringLiteral("movieLabel"));

        horizontalLayout->addWidget(movieLabel);

        movieCBB = new QComboBox(layoutWidget_2);
        movieCBB->setObjectName(QStringLiteral("movieCBB"));

        horizontalLayout->addWidget(movieCBB);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        hallLabel = new QLabel(layoutWidget_2);
        hallLabel->setObjectName(QStringLiteral("hallLabel"));

        horizontalLayout_2->addWidget(hallLabel);

        hallCBB = new QComboBox(layoutWidget_2);
        hallCBB->setObjectName(QStringLiteral("hallCBB"));

        horizontalLayout_2->addWidget(hallCBB);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dateLabel = new QLabel(layoutWidget_2);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        verticalLayout->addWidget(dateLabel);

        calendarWidget = new QCalendarWidget(layoutWidget_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        timeLabel = new QLabel(layoutWidget_2);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        horizontalLayout_6->addWidget(timeLabel);

        timeEdit = new QTimeEdit(layoutWidget_2);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_6->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DDDLabel = new QLabel(layoutWidget_2);
        DDDLabel->setObjectName(QStringLiteral("DDDLabel"));

        horizontalLayout_3->addWidget(DDDLabel);

        DDDYesRB = new QRadioButton(layoutWidget_2);
        buttonGroup = new QButtonGroup(addShowDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(DDDYesRB);
        DDDYesRB->setObjectName(QStringLiteral("DDDYesRB"));

        horizontalLayout_3->addWidget(DDDYesRB);

        DDDNoRB = new QRadioButton(layoutWidget_2);
        buttonGroup->addButton(DDDNoRB);
        DDDNoRB->setObjectName(QStringLiteral("DDDNoRB"));

        horizontalLayout_3->addWidget(DDDNoRB);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        subLabel = new QLabel(layoutWidget_2);
        subLabel->setObjectName(QStringLiteral("subLabel"));

        horizontalLayout_4->addWidget(subLabel);

        subYesRB = new QRadioButton(layoutWidget_2);
        buttonGroup_2 = new QButtonGroup(addShowDialog);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(subYesRB);
        subYesRB->setObjectName(QStringLiteral("subYesRB"));

        horizontalLayout_4->addWidget(subYesRB);

        subNoRB = new QRadioButton(layoutWidget_2);
        buttonGroup_2->addButton(subNoRB);
        subNoRB->setObjectName(QStringLiteral("subNoRB"));

        horizontalLayout_4->addWidget(subNoRB);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        languageLabel = new QLabel(layoutWidget_2);
        languageLabel->setObjectName(QStringLiteral("languageLabel"));

        horizontalLayout_5->addWidget(languageLabel);

        languageCBB = new QComboBox(layoutWidget_2);
        languageCBB->setObjectName(QStringLiteral("languageCBB"));

        horizontalLayout_5->addWidget(languageCBB);


        verticalLayout_2->addLayout(horizontalLayout_5);

        splitter_2->addWidget(layoutWidget_2);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        priceLabel = new QLabel(splitter);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        splitter->addWidget(priceLabel);
        priceSpinBox = new QSpinBox(splitter);
        priceSpinBox->setObjectName(QStringLiteral("priceSpinBox"));
        priceSpinBox->setMaximum(999);
        splitter->addWidget(priceSpinBox);
        splitter_2->addWidget(splitter);

        retranslateUi(addShowDialog);

        QMetaObject::connectSlotsByName(addShowDialog);
    } // setupUi

    void retranslateUi(QDialog *addShowDialog)
    {
        addShowDialog->setWindowTitle(QApplication::translate("addShowDialog", "Dialog", 0));
        cancelShowButton->setText(QApplication::translate("addShowDialog", "Cancel", 0));
        addShowButton->setText(QApplication::translate("addShowDialog", "Submit", 0));
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
