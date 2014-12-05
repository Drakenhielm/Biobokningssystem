#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T11:56:22
#
#-------------------------------------------------

QT       += core gui sql
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hallview.cpp \
    Model/basemodel.cpp \
    Model/bookingmodel.cpp \
    Model/hallmodel.cpp \
    Model/moviemodel.cpp \
    Model/seatmodel.cpp \
    Model/showmodel.cpp \
    DatabaseHandler/databasehandler.cpp \
    add_hall/hall.cpp \
    add_movie/confirmaddmovie.cpp \
    add_movie/popup.cpp \
    add_show/addshowdialog.cpp \
    Model/imagehandler.cpp

HEADERS  += mainwindow.h \
    hallview.h \
    Model/basemodel.h \
    Model/bookingmodel.h \
    Model/hallmodel.h \
    Model/moviemodel.h \
    Model/seatmodel.h \
    Model/showmodel.h \
    DatabaseHandler/databasehandler.h \
    add_hall/hall.h \
    add_movie/confirmaddmovie.h \
    add_movie/popup.h \
    add_show/addshowdialog.h \
    Model/imagehandler.h

FORMS    += mainwindow.ui \
    add_hall/hall.ui \
    add_movie/confirmaddmovie.ui \
    add_movie/popup.ui \
    add_show/addshowdialog.ui

OTHER_FILES += \
    Mainwindow.pro.user \
    Mainwindow.pro.user.81ecaa1 \
    Mainwindow.pro.user.e8fc351 \
    images/avatar.jpg \
    images/Bad_boys_two.jpg

RESOURCES += \
    resource.qrc
