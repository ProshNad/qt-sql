#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T22:45:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = 210319lab2database
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbclass.cpp

HEADERS  += mainwindow.h \
    dbclass.h

FORMS    += mainwindow.ui
