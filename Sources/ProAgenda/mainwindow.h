#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QToolButton>
#include <toolbutton.h>
#include <edittoolbar.h>
#include <testwidget.h>
#include "testcalendar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    EditToolBar* editToolBar;
    TestWidget* testWidget;
    TestWidget* testWidget2;
    QWidget* testWidget3;
    TestCalendar* miniCalendar;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initResume();
private slots:
    void on_actionGoToTask_triggered();
    void on_actionGoToCal_triggered();
    void on_actionGoToResume_triggered();

private:
    void initMainToolbar();
    void initEditToolBar();
    void initSideBar();
};


#endif // MAINWINDOW_H
