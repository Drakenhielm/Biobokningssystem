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
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QAction *actionAdd_movie;
    QAction *actionAdd_show;
    QAction *actionAdd_hall;
    QAction *actionDelete_movie;
    QAction *actionDelete_show;
    QAction *actionDelete_hall;
    QAction *actionBook;
    QAction *actionDelete_booking;
    QAction *actionEdit_text;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_movies;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QListView *listView_movies;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_movies_add;
    QPushButton *pushButton_movies_delete;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_shows;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QTableWidget *tableWidget_show;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_show_add;
    QPushButton *pushButton_show_delete;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_info;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextBrowser *textBrowser_info;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_info_edit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QTableWidget *tableWidget_search;
    QMenuBar *menuBar;
    QMenu *menuAdd_movie;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 685);
        actionAdd_movie = new QAction(MainWindow);
        actionAdd_movie->setObjectName(QStringLiteral("actionAdd_movie"));
        actionAdd_show = new QAction(MainWindow);
        actionAdd_show->setObjectName(QStringLiteral("actionAdd_show"));
        actionAdd_hall = new QAction(MainWindow);
        actionAdd_hall->setObjectName(QStringLiteral("actionAdd_hall"));
        actionDelete_movie = new QAction(MainWindow);
        actionDelete_movie->setObjectName(QStringLiteral("actionDelete_movie"));
        actionDelete_show = new QAction(MainWindow);
        actionDelete_show->setObjectName(QStringLiteral("actionDelete_show"));
        actionDelete_hall = new QAction(MainWindow);
        actionDelete_hall->setObjectName(QStringLiteral("actionDelete_hall"));
        actionBook = new QAction(MainWindow);
        actionBook->setObjectName(QStringLiteral("actionBook"));
        actionDelete_booking = new QAction(MainWindow);
        actionDelete_booking->setObjectName(QStringLiteral("actionDelete_booking"));
        actionEdit_text = new QAction(MainWindow);
        actionEdit_text->setObjectName(QStringLiteral("actionEdit_text"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
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

        listView_movies = new QListView(widget_movies);
        listView_movies->setObjectName(QStringLiteral("listView_movies"));

        verticalLayout_6->addWidget(listView_movies);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_movies_add = new QPushButton(widget_movies);
        pushButton_movies_add->setObjectName(QStringLiteral("pushButton_movies_add"));

        horizontalLayout_4->addWidget(pushButton_movies_add);

        pushButton_movies_delete = new QPushButton(widget_movies);
        pushButton_movies_delete->setObjectName(QStringLiteral("pushButton_movies_delete"));

        horizontalLayout_4->addWidget(pushButton_movies_delete);

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

        tableWidget_show = new QTableWidget(widget_shows);
        tableWidget_show->setObjectName(QStringLiteral("tableWidget_show"));

        verticalLayout_5->addWidget(tableWidget_show);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        pushButton_show_add = new QPushButton(widget_shows);
        pushButton_show_add->setObjectName(QStringLiteral("pushButton_show_add"));

        horizontalLayout_6->addWidget(pushButton_show_add);

        pushButton_show_delete = new QPushButton(widget_shows);
        pushButton_show_delete->setObjectName(QStringLiteral("pushButton_show_delete"));

        horizontalLayout_6->addWidget(pushButton_show_delete);

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

        textBrowser_info = new QTextBrowser(widget_info);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));

        verticalLayout->addWidget(textBrowser_info);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton_info_edit = new QPushButton(widget_info);
        pushButton_info_edit->setObjectName(QStringLiteral("pushButton_info_edit"));

        horizontalLayout_7->addWidget(pushButton_info_edit);

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
        lineEdit_search = new QLineEdit(widget_6);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));

        horizontalLayout_9->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(widget_6);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout_9->addWidget(pushButton_search);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tableWidget_search = new QTableWidget(widget_6);
        tableWidget_search->setObjectName(QStringLiteral("tableWidget_search"));

        verticalLayout_3->addWidget(tableWidget_search);


        horizontalLayout_8->addWidget(widget_6);


        verticalLayout_2->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 22));
        menuAdd_movie = new QMenu(menuBar);
        menuAdd_movie->setObjectName(QStringLiteral("menuAdd_movie"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAdd_movie->menuAction());
        menuAdd_movie->addAction(actionAdd_movie);
        menuAdd_movie->addAction(actionAdd_show);
        menuAdd_movie->addAction(actionAdd_hall);
        menuAdd_movie->addSeparator();
        menuAdd_movie->addAction(actionBook);
        menuAdd_movie->addAction(actionDelete_booking);
        menuAdd_movie->addSeparator();
        menuAdd_movie->addAction(actionDelete_movie);
        menuAdd_movie->addAction(actionDelete_show);
        menuAdd_movie->addAction(actionDelete_hall);
        menuAdd_movie->addSeparator();
        menuAdd_movie->addAction(actionEdit_text);
        menuAdd_movie->addSeparator();
        menuAdd_movie->addAction(actionQuit);
        menuAdd_movie->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_movie->setText(QApplication::translate("MainWindow", "Add movie", 0));
        actionAdd_show->setText(QApplication::translate("MainWindow", "Add show", 0));
        actionAdd_hall->setText(QApplication::translate("MainWindow", "Add hall", 0));
        actionDelete_movie->setText(QApplication::translate("MainWindow", "Delete movie", 0));
        actionDelete_show->setText(QApplication::translate("MainWindow", "Delete show", 0));
        actionDelete_hall->setText(QApplication::translate("MainWindow", "Delete hall", 0));
        actionBook->setText(QApplication::translate("MainWindow", "Book", 0));
        actionDelete_booking->setText(QApplication::translate("MainWindow", "Delete booking", 0));
        actionEdit_text->setText(QApplication::translate("MainWindow", "Edit text", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Qui", 0));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "Qui", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Movies:", 0));
        pushButton_movies_add->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_movies_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_2->setText(QApplication::translate("MainWindow", "Show:", 0));
        pushButton_show_add->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_show_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_3->setText(QApplication::translate("MainWindow", "Information:", 0));
        textBrowser_info->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.Helvetica Neue DeskInterface'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pushButton_info_edit->setText(QApplication::translate("MainWindow", "Edit", 0));
        pushButton_search->setText(QApplication::translate("MainWindow", "Search", 0));
        menuAdd_movie->setTitle(QApplication::translate("MainWindow", "Manage", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
