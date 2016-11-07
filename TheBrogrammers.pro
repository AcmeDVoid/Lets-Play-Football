#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T20:57:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheBrogrammers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    StadiumList.cpp \
    Stadium.cpp \
    ReadFromFile.cpp \
    StadiumListUI.cpp

HEADERS  += mainwindow.h \
    StadiumList.h \
    Stadium.h \
    StadiumNote.h \
    MyHeader.h \
    StadiumListUI.h

FORMS    += mainwindow.ui \
    stadiumlistui.ui
