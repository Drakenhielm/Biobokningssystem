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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_top;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_movies;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_shows;
    QWidget *widget_info;
    QWidget *widget_down;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QWidget *widget_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1042, 721);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_top = new QWidget(centralWidget);
        widget_top->setObjectName(QStringLiteral("widget_top"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_top->sizePolicy().hasHeightForWidth());
        widget_top->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_top);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_movies = new QWidget(widget_top);
        widget_movies->setObjectName(QStringLiteral("widget_movies"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_movies->sizePolicy().hasHeightForWidth());
        widget_movies->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget_movies);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(widget_movies);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        widget = new QWidget(widget_movies);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(6, 19, 115, 32));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(152, 19, 115, 32));

        verticalLayout_2->addWidget(widget);


        horizontalLayout_2->addWidget(widget_movies);

        widget_shows = new QWidget(widget_top);
        widget_shows->setObjectName(QStringLiteral("widget_shows"));
        sizePolicy1.setHeightForWidth(widget_shows->sizePolicy().hasHeightForWidth());
        widget_shows->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(widget_shows);

        widget_info = new QWidget(widget_top);
        widget_info->setObjectName(QStringLiteral("widget_info"));
        sizePolicy1.setHeightForWidth(widget_info->sizePolicy().hasHeightForWidth());
        widget_info->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(widget_info);


        verticalLayout->addWidget(widget_top);

        widget_down = new QWidget(centralWidget);
        widget_down->setObjectName(QStringLiteral("widget_down"));
        sizePolicy.setHeightForWidth(widget_down->sizePolicy().hasHeightForWidth());
        widget_down->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_down);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_3 = new QWidget(widget_down);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_down);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget_down);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1042, 22));
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
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
