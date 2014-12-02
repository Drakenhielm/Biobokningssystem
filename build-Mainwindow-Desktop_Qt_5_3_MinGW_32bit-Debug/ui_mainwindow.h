/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QSplitter *splitter;
    QWidget *widget_movies;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_movies;
    QListView *listView_movies;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_movies_add;
    QPushButton *pushButton_movies_delete;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_shows;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_shows;
    QTableView *tableView_show;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_show_add;
    QPushButton *pushButton_show_delete;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_info;
    QVBoxLayout *verticalLayout;
    QLabel *label_movieinfo;
    QTextBrowser *textBrowser_info;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_info_edit;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QWidget *widget_hallview_info;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_num_of_seats;
    QComboBox *comboBox;
    QLabel *label_phone;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_hallview_info_delete;
    QPushButton *pushButton_hallview_info_book;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_bookings;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QComboBox *comboBox_search;
    QTableView *tableView_search;
    QMenuBar *menuBar;
    QMenu *menuAdd_movie;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(892, 658);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setCursor(QCursor(Qt::ArrowCursor));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_movies = new QWidget(splitter);
        widget_movies->setObjectName(QStringLiteral("widget_movies"));
        widget_movies->setMinimumSize(QSize(0, 0));
        verticalLayout_6 = new QVBoxLayout(widget_movies);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_movies = new QLabel(widget_movies);
        label_movies->setObjectName(QStringLiteral("label_movies"));

        verticalLayout_6->addWidget(label_movies);

        listView_movies = new QListView(widget_movies);
        listView_movies->setObjectName(QStringLiteral("listView_movies"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView_movies->sizePolicy().hasHeightForWidth());
        listView_movies->setSizePolicy(sizePolicy1);
        listView_movies->setMinimumSize(QSize(10, 0));

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

        splitter->addWidget(widget_movies);
        widget_shows = new QWidget(splitter);
        widget_shows->setObjectName(QStringLiteral("widget_shows"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_shows->sizePolicy().hasHeightForWidth());
        widget_shows->setSizePolicy(sizePolicy2);
        widget_shows->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(widget_shows);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_shows = new QLabel(widget_shows);
        label_shows->setObjectName(QStringLiteral("label_shows"));

        verticalLayout_5->addWidget(label_shows);

        tableView_show = new QTableView(widget_shows);
        tableView_show->setObjectName(QStringLiteral("tableView_show"));
        sizePolicy1.setHeightForWidth(tableView_show->sizePolicy().hasHeightForWidth());
        tableView_show->setSizePolicy(sizePolicy1);
        tableView_show->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_show->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_show->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_show->horizontalHeader()->setDefaultSectionSize(75);
        tableView_show->horizontalHeader()->setHighlightSections(false);
        tableView_show->horizontalHeader()->setMinimumSectionSize(1);
        tableView_show->verticalHeader()->setVisible(false);
        tableView_show->verticalHeader()->setCascadingSectionResizes(false);
        tableView_show->verticalHeader()->setDefaultSectionSize(20);
        tableView_show->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_5->addWidget(tableView_show);

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

        splitter->addWidget(widget_shows);
        widget_info = new QWidget(splitter);
        widget_info->setObjectName(QStringLiteral("widget_info"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_info->sizePolicy().hasHeightForWidth());
        widget_info->setSizePolicy(sizePolicy3);
        widget_info->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(widget_info);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_movieinfo = new QLabel(widget_info);
        label_movieinfo->setObjectName(QStringLiteral("label_movieinfo"));

        verticalLayout->addWidget(label_movieinfo);

        textBrowser_info = new QTextBrowser(widget_info);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));
        sizePolicy1.setHeightForWidth(textBrowser_info->sizePolicy().hasHeightForWidth());
        textBrowser_info->setSizePolicy(sizePolicy1);

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

        splitter->addWidget(widget_info);

        horizontalLayout->addWidget(splitter);


        verticalLayout_2->addWidget(widget);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        splitter_2 = new QSplitter(widget_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        frame->setPalette(palette);
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 9, 9, 9);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setEnabled(true);
        sizePolicy4.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy4);
        frame_3->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(frame_3);

        widget_hallview_info = new QWidget(frame);
        widget_hallview_info->setObjectName(QStringLiteral("widget_hallview_info"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget_hallview_info->sizePolicy().hasHeightForWidth());
        widget_hallview_info->setSizePolicy(sizePolicy5);
        widget_hallview_info->setMinimumSize(QSize(153, 0));
        verticalLayout_7 = new QVBoxLayout(widget_hallview_info);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 0, -1, 0);
        label_6 = new QLabel(widget_hallview_info);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_7->addWidget(label_6);

        verticalSpacer = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        groupBox = new QGroupBox(widget_hallview_info);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_num_of_seats = new QLabel(groupBox);
        label_num_of_seats->setObjectName(QStringLiteral("label_num_of_seats"));

        verticalLayout_4->addWidget(label_num_of_seats);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy6);
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setMaximumSize(QSize(155, 16777215));
        comboBox->setFont(font);

        verticalLayout_4->addWidget(comboBox);

        label_phone = new QLabel(groupBox);
        label_phone->setObjectName(QStringLiteral("label_phone"));

        verticalLayout_4->addWidget(label_phone);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(155, 16777215));
        lineEdit->setFont(font);

        verticalLayout_4->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_hallview_info_delete = new QPushButton(groupBox);
        pushButton_hallview_info_delete->setObjectName(QStringLiteral("pushButton_hallview_info_delete"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pushButton_hallview_info_delete->sizePolicy().hasHeightForWidth());
        pushButton_hallview_info_delete->setSizePolicy(sizePolicy7);
        QFont font1;
        font1.setPointSize(8);
        pushButton_hallview_info_delete->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_hallview_info_delete);

        pushButton_hallview_info_book = new QPushButton(groupBox);
        pushButton_hallview_info_book->setObjectName(QStringLiteral("pushButton_hallview_info_book"));
        sizePolicy7.setHeightForWidth(pushButton_hallview_info_book->sizePolicy().hasHeightForWidth());
        pushButton_hallview_info_book->setSizePolicy(sizePolicy7);
        pushButton_hallview_info_book->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_hallview_info_book, 0, Qt::AlignLeft);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_7->addWidget(groupBox);


        horizontalLayout_3->addWidget(widget_hallview_info);

        splitter_2->addWidget(frame);
        widget_6 = new QWidget(splitter_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        sizePolicy5.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy5);
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_bookings = new QLabel(widget_6);
        label_bookings->setObjectName(QStringLiteral("label_bookings"));

        verticalLayout_3->addWidget(label_bookings);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, -1, -1, -1);
        lineEdit_search = new QLineEdit(widget_6);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));

        horizontalLayout_9->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(widget_6);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout_9->addWidget(pushButton_search);

        comboBox_search = new QComboBox(widget_6);
        comboBox_search->setObjectName(QStringLiteral("comboBox_search"));

        horizontalLayout_9->addWidget(comboBox_search);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tableView_search = new QTableView(widget_6);
        tableView_search->setObjectName(QStringLiteral("tableView_search"));
        sizePolicy.setHeightForWidth(tableView_search->sizePolicy().hasHeightForWidth());
        tableView_search->setSizePolicy(sizePolicy);
        tableView_search->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_search->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_search->setCornerButtonEnabled(false);
        tableView_search->horizontalHeader()->setHighlightSections(false);
        tableView_search->verticalHeader()->setVisible(false);
        tableView_search->verticalHeader()->setDefaultSectionSize(20);
        tableView_search->verticalHeader()->setHighlightSections(false);
        tableView_search->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_3->addWidget(tableView_search);

        splitter_2->addWidget(widget_6);

        horizontalLayout_2->addWidget(splitter_2);


        verticalLayout_2->addWidget(widget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 892, 21));
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
        label_movies->setText(QApplication::translate("MainWindow", "Movies:", 0));
        pushButton_movies_add->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_movies_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_shows->setText(QApplication::translate("MainWindow", "Shows:", 0));
        pushButton_show_add->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_show_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_movieinfo->setText(QApplication::translate("MainWindow", "Information:", 0));
        textBrowser_info->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.Helvetica Neue DeskInterface'; font-size:13pt;\"><br /></p></body></html>", 0));
        pushButton_info_edit->setText(QApplication::translate("MainWindow", "Edit", 0));
        label_6->setText(QApplication::translate("MainWindow", "Hall info", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Book", 0));
        label_num_of_seats->setText(QApplication::translate("MainWindow", "Number of seats", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        label_phone->setText(QApplication::translate("MainWindow", "Phone", 0));
        pushButton_hallview_info_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        pushButton_hallview_info_book->setText(QApplication::translate("MainWindow", "Book", 0));
        label_bookings->setText(QApplication::translate("MainWindow", "Bookings:", 0));
        lineEdit_search->setInputMask(QString());
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QApplication::translate("MainWindow", "Phone", 0));
        pushButton_search->setText(QApplication::translate("MainWindow", "Search", 0));
        comboBox_search->clear();
        comboBox_search->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "All shows", 0)
         << QApplication::translate("MainWindow", "Selected show", 0)
        );
        menuAdd_movie->setTitle(QApplication::translate("MainWindow", "Manage", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
