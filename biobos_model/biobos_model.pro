#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T10:59:30
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = biobos_model
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasehandler.cpp \
    basemodel.cpp \
    moviemodel.cpp

HEADERS  += mainwindow.h \
    databasehandler.h \
    basemodel.h \
    moviemodel.h

FORMS    += mainwindow.ui
