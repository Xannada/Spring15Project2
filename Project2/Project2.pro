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
    adminwindow.cpp \
    BinarySearchTree.cpp \
    stadium.cpp \
    adminlogin.cpp \
    newmerchandise.cpp \
    teaminfo.cpp \
    merc.cpp

HEADERS  += landingwin.h \
    mainwindow.h \
    MainHeader.h \
    adminwindow.h \
    BinarySearchTree.h \
    stadium.h \
    adminlogin.h \
    newmerchandise.h \
    teaminfo.h \
    merc.h

FORMS    += landingwin.ui \
    mainwindow.ui \
    adminwindow.ui \
    adminlogin.ui \
    newmerchandise.ui \
    teaminfo.ui

RESOURCES += \
    pics.qrc \
    files.qrc
