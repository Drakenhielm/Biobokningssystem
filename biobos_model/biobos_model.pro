#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T10:59:30
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = biobos_model
TEMPLATE = app


SOURCES += main.cpp \
    custommodel.cpp \
    mainwindow.cpp \
    DatabaseHandler/databasehandler.cpp \
    DatabaseHandler/imagehandler.cpp \
    DatabaseHandler/sqlhandler.cpp \
    Model/basemodel.cpp \
    Model/bookingmodel.cpp \
    Model/hallmodel.cpp \
    Model/moviemodel.cpp \
    Model/seatmodel.cpp \
    Model/showmodel.cpp

HEADERS  += \
    custommodel.h \
    mainwindow.h \
    DatabaseHandler/databasehandler.h \
    DatabaseHandler/imagehandler.h \
    DatabaseHandler/sqlhandler.h \
    Model/basemodel.h \
    Model/bookingmodel.h \
    Model/hallmodel.h \
    Model/moviemodel.h \
    Model/seatmodel.h \
    Model/showmodel.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    style.css

RESOURCES += \
    imgtest.qrc
