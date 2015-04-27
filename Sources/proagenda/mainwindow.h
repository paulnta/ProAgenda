#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QTreeView>
#include <QWidget>
#include <QDebug>
#include <QToolButton>

#include "edittoolbar.h"
#include "viewTask/sidebartask.h"
#include "viewCalendar/calendarwidget.h"
#include "viewTask/taskdisplay.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    EditToolBar* editToolBar;
    SideBarTask* sideBarTask;

public:
    explicit MainWindow(QWidget *parent = 0);
    SideBarTask* getSideBarTask();
    ~MainWindow();

private slots:
    void on_actionGoToTask_triggered();
    void on_actionGoToCal_triggered();
    void on_actionGoToResume_triggered();

private:
    void initMainToolbar();
    void initEditToolBar();

};


#endif // MAINWINDOW_H
