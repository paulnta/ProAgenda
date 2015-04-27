#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T21:45:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proagenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    edittoolbar.cpp \
    toolbutton.cpp \
    viewTask/sidebartask.cpp \
    viewTask/taskdisplay.cpp \
    viewTask/taskmodel.cpp \
    viewTask/taskwidget.cpp \
    viewTask/type.cpp \
    viewCalendar/calendarwidget.cpp \
    viewSummary/vsemesterfill.cpp \
    viewSummary/vsummary.cpp \
    sqlconnection.cpp \
    viewSummary/sidebarsummary.cpp

HEADERS  += mainwindow.h \
    edittoolbar.h \
    toolbutton.h \
    viewTask/sidebartask.h \
    viewTask/taskdisplay.h \
    viewTask/taskmodel.h \
    viewTask/taskwidget.h \
    viewTask/type.h \
    viewCalendar/calendarwidget.h \
    viewTask/tristatebutton.h \
    viewSummary/vsemesterfill.h \
    viewSummary/vsummary.h \
    sqlconnection.h \
    viewSummary/sidebarsummary.h

FORMS    += mainwindow.ui \
    viewTask/sidebartask.ui \
    viewTask/taskdisplay.ui \
    viewTask/taskwidget.ui \
    viewCalendar/calendarwidget.ui \
    viewSummary/vsemesterfill.ui \
    viewSummary/vsummary.ui \
    viewSummary/sidebarsummary.ui

RESOURCES += \
    ressources.qrc
