#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QTreeView>
#include <QWidget>
#include <QDebug>
#include <QToolButton>
#include <QStackedWidget>

#include "viewCalendar/calendarwidget.h"
#include "viewCalendar/toolbarcalendar.h"

#include "viewSummary/vsummary.h"
#include "viewSummary/sidebarsummary.h"
#include "viewSummary/toolbarsummary.h"

#include "viewTask/sidebartask.h"
#include "viewTask/taskdisplay.h"
#include "viewTask/toolbartask.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;

    // Views
    taskDisplay* taskDisp;
    CalendarWidget* calendarWidget;
    VSummary* viewSummary;

    // Sidebars
    SideBarTask* sideBarTask;
    SideBarSummary* sideBarSummary;

    // ToolBars
    QToolBar* toolBarTask;
    QToolBar* toolBarCalendar;
    QToolBar* toolBarSummary;
    QStackedWidget* toolBarStackedWidget;

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    SideBarTask* getSideBarTask();
    SideBarSummary* getSideBarSummary();

private slots:
    void on_actionGoToTask_triggered();
    void on_actionGoToCal_triggered();
    void on_actionGoToResume_triggered();

private:
    void initMainToolbar();
    void initEditToolBar();

};


#endif // MAINWINDOW_H
