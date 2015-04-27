#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T19:01:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProAgenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    toolbutton.cpp \
    edittoolbar.cpp \
    testwidget.cpp \
    testcalendar.cpp \
    mywidget.cpp \
    vsemesterfill.cpp \
    vsummary.cpp \
    sqlconnection.cpp

HEADERS  += mainwindow.h \
    toolbutton.h \
    edittoolbar.h \
    testwidget.h \
    testcalendar.h \
    mywidget.h \
    vsemesterfill.h \
    sqlconnection.h \
    vsummary.h

FORMS    += mainwindow.ui \
    testwidget.ui \
    testcalendar.ui \
    mywidget.ui \
    vsemesterfill.ui \
    vsummary.ui

RESOURCES += \
    ressources.qrc

CONFIG += c++11
