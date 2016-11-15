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
    SortedLists.cpp \
    mainvoid.cpp \
    log_in.cpp \
    password.cpp

HEADERS  += mainwindow.h \
    StadiumList.h \
    Stadium.h \
    MyHeader.h \
    StadiumNode.h \
    SortedLists.h \
    mainvoid.h \
    log_in.h \
    password.h

FORMS    += mainwindow.ui \
    mainvoid.ui \
    log_in.ui

RESOURCES += \
    image.qrc
