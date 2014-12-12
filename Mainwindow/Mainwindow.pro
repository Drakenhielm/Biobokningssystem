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
    hall_list/hall_list.cpp \
    add_show/addshowdialog.cpp \
    DatabaseHandler/imagehandler.cpp \
    add_movie/add_Movie.cpp \

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
    Model/imagehandler.h \
    add_show/addshowdialog.h \
    DatabaseHandler/imagehandler.h \
    add_movie/add_Movie.h \
    hall_list/hall_list.h

FORMS    += \
    add_hall/hall.ui \
    hall_list/hall_list.ui \
    mainwindow.ui \
    add_show/addshowdialog.ui \
    add_movie/add_Movie.ui \

OTHER_FILES += \
    Mainwindow.pro.user \
    Mainwindow.pro.user.81ecaa1 \
    Mainwindow.pro.user.e8fc351 \
    images/avatar.jpg \
    images/Bad_boys_two.jpg

RESOURCES += \
    resource.qrc
