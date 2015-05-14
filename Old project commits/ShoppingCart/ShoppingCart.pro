#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T09:53:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShoppingCart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    heap.cpp \
    item.cpp \
    shoppingdisplay.cpp

HEADERS  += mainwindow.h \
    heap.h \
    item.h \
    shoppingdisplay.h

FORMS    += mainwindow.ui \
    shoppingdisplay.ui
