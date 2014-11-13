/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_movies;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_shows;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_info;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QTableWidget *tableWidget_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 685);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_movies = new QWidget(widget);
        widget_movies->setObjectName(QStringLiteral("widget_movies"));
        verticalLayout_6 = new QVBoxLayout(widget_movies);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_movies);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        tableWidget = new QTableWidget(widget_movies);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_6->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_2 = new QPushButton(widget_movies);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(widget_movies);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(widget_movies);

        widget_shows = new QWidget(widget);
        widget_shows->setObjectName(QStringLiteral("widget_shows"));
        verticalLayout_5 = new QVBoxLayout(widget_shows);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_shows);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        tableWidget_2 = new QTableWidget(widget_shows);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_5->addWidget(tableWidget_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        pushButton_4 = new QPushButton(widget_shows);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_6->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget_shows);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout->addWidget(widget_shows);

        widget_info = new QWidget(widget);
        widget_info->setObjectName(QStringLiteral("widget_info"));
        verticalLayout = new QVBoxLayout(widget_info);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_info);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        textBrowser = new QTextBrowser(widget_info);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(widget_info);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_7->addWidget(pushButton_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout->addWidget(widget_info);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        tableWidget_3 = new QTableWidget(widget_2);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));

        horizontalLayout_8->addWidget(tableWidget_3);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(10, -1, -1, -1);
        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_9->addWidget(lineEdit);

        pushButton_6 = new QPushButton(widget_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_9->addWidget(pushButton_6);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tableWidget_5 = new QTableWidget(widget_6);
        tableWidget_5->setObjectName(QStringLiteral("tableWidget_5"));

        verticalLayout_3->addWidget(tableWidget_5);


        horizontalLayout_8->addWidget(widget_6);


        verticalLayout_2->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Filmer:", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "L\303\244gg till", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Ta bort", 0));
        label_2->setText(QApplication::translate("MainWindow", "Visningar:", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "L\303\244gg till", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Ta bort", 0));
        label_3->setText(QApplication::translate("MainWindow", "Information:", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Redigera", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "S\303\266k", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
