#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T11:56:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basemodel.cpp \
    databasehandler.cpp \
    moviemodel.cpp \
    showmodel.cpp \
    hallview.cpp

HEADERS  += mainwindow.h \
    basemodel.h \
    databasehandler.h \
    moviemodel.h \
    showmodel.h \
    hallview.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    Mainwindow.pro.user \
    Mainwindow.pro.user.81ecaa1 \
    Mainwindow.pro.user.e8fc351
