#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T19:01:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProAgenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    toolbutton.cpp \
    edittoolbar.cpp

HEADERS  += mainwindow.h \
    toolbutton.h \
    edittoolbar.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc
