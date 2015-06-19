#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T10:16:42
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtModelViewDemo
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    MyTableItem.cpp \
    MyTableModel.cpp

HEADERS  += MainWindow.h \
    MyTableItem.h \
    MyTableModel.h

FORMS    += MainWindow.ui
