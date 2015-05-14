#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T18:03:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        landingwin.cpp \
    mainwindow.cpp \
    merc.cpp \
    stadium.cpp \
    heap.cpp \
    mst.cpp

HEADERS  += landingwin.h \
    mainwindow.h \
    merc.h \
    stadium.h \
    heap.h \
    mst.h

FORMS    += landingwin.ui \
    mainwindow.ui

RESOURCES += \
    pics.qrc \
    files.qrc
