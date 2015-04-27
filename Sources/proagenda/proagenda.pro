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
    viewTask/taskwidget.cpp \
    viewCalendar/calendarwidget.cpp \
    viewSummary/vsemesterfill.cpp \
    viewSummary/vsummary.cpp \
    sqlconnection.cpp \
    viewSummary/sidebarsummary.cpp \
    models/task.cpp \
    models/tasktype.cpp \
    models/course.cpp \
    models/module.cpp \
    models/semester.cpp \
    models/lesson.cpp

HEADERS  += mainwindow.h \
    edittoolbar.h \
    toolbutton.h \
    viewTask/sidebartask.h \
    viewTask/taskdisplay.h \
    viewTask/taskwidget.h \
    viewCalendar/calendarwidget.h \
    viewTask/tristatebutton.h \
    viewSummary/vsemesterfill.h \
    viewSummary/vsummary.h \
    sqlconnection.h \
    viewSummary/sidebarsummary.h \
    models/task.h \
    models/tasktype.h \
    models/course.h \
    models/module.h \
    models/semester.h \
    models/lesson.h

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