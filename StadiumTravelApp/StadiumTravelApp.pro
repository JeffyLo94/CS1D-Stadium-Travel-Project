#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T15:28:10
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StadiumTravelApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminlogin.cpp \
    userselectionwindow.cpp \
    responsewindow.cpp \
    adminwindow.cpp \
    date.cpp \
    stadium.cpp \
    souvenir.cpp    \
    purchase.cpp \
    endtrip.cpp \
    infowindow.cpp

HEADERS  += mainwindow.h \
    adminlogin.h \
    userselectionwindow.h \
    responsewindow.h \
    adminwindow.h \
    date.h \
    stadium.h \
    souvenir.h \
    graph.h \
    purchase.h \
    graph2.h \
    endtrip.h \
    graph3.h \
    infowindow.h

FORMS    += mainwindow.ui \
    adminlogin.ui \
    userselectionwindow.ui \
    responsewindow.ui \
    adminwindow.ui \
    purchase.ui \
    endtrip.ui \
    infowindow.ui
