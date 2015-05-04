#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T18:03:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        landingwin.cpp \
    mainwindow.cpp \
    adminwindow.cpp

HEADERS  += landingwin.h \
    mainwindow.h \
    MainHeader.h \
    adminwindow.h

FORMS    += landingwin.ui \
    mainwindow.ui \
    adminwindow.ui

RESOURCES += \
    pics.qrc
