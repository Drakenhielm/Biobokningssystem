#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T20:38:56
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = biobos_database
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    databasehandler.cpp \
    imagehandler.cpp \
    sqlhandler.cpp

HEADERS += \
    databasehandler.h \
    imagehandler.h \
    sqlhandler.h
