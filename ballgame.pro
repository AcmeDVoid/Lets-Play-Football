#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T21:25:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ballgame
TEMPLATE = app

DEPENDPATH += src
INCLUDEPATH += include


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/splashscreen.cpp \
           src/administrator.cpp \
           src/administrator_login.cpp \
           src/stadium.cpp \
           src/DateAccessors.cpp \
           src/DateConstDest.cpp \
           src/DateMutators.cpp \
           src/DateUtilities.cpp \
           src/DateValidate.cpp \
           src/souvenir.cpp \
           src/stadiumlist.cpp \
           src/errorcheck.cpp \
           src/viewstadiumwindow.cpp \
           src/addstadium.cpp\
           src/changesouvenir.cpp \
    src/shoppingmenu.cpp \
    src/changeintvalue.cpp \
    src/shoppingsummarywindow.cpp \
    src/viewrevenue.cpp \
    src/modifystadium.cpp \
    src/modifystadiumselector.cpp


HEADERS  += include/mainwindow.h \
            include/splashscreen.h \
            include/administrator.h \
            include/administrator_login.h \
            include/stadium.h \
            include/Date.h \
            include/souvenir.h \
            include/stadiumlist.h \
            include/errorcheck.h \
            include/viewstadiumwindow.h \
            include/addstadium.h \
            include/changesouvenir.h \
    include/shoppingmenu.h \
    include/changeintvalue.h \
    include/shoppingsummarywindow.h \
    include/viewrevenue.h \
    include/modifystadium.h \
    include/modifystadiumselector.h

FORMS    += ui/mainwindow.ui \
            ui/splashscreen.ui \
            ui/administrator.ui \
            ui/administrator_login.ui \
            ui/viewstadiumwindow.ui \
            ui/addstadium.ui \
            ui/changesouvenir.ui \
            ui/tripplanner.ui \
    ui/shoppingmenu.ui \
    ui/changeintvalue.ui \
    ui/shoppingsummarywindow.ui \
    ui/viewrevenue.ui \
    ui/modifystadium.ui \
    ui/modifystadiumselector.ui

RESOURCES += \
    assets/img.qrc

RC_FILE = myapp.rc
