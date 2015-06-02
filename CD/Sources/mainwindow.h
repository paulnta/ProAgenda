#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QTreeView>
#include <QWidget>
#include <QDebug>
#include <QToolButton>
#include <QStackedWidget>
#include <QFile>

#include "viewCalendar/calendarwidget.h"
#include "viewCalendar/toolbarcalendar.h"
#include "viewCalendar/sidebarcalendar.h"

#include "viewSummary/vsummary.h"
#include "viewSummary/sidebarsummary.h"
#include "viewSummary/toolbarsummary.h"

#include "viewTask/sidebartask.h"
#include "viewTask/taskdisplay.h"
#include "viewTask/toolbartask.h"


namespace Ui {
class MainWindow;
}

/*! @class MainWindow
 *
 */
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
    SideBarCalendar* sideBarCalendar;

    // ToolBars
    QToolBar* toolBarTask;
    ToolBarCalendar* toolBarCalendar;
    QToolBar* toolBarSummary;
    QStackedWidget* toolBarStackedWidget;

public:
    /*!
     *  @brief Conctructeur
     *
     *
     * @param parent : widget parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     *  @brief Destructeur
     *
     */
    ~MainWindow();
    /*!
     *  @brief Récupère un pointeur sur une SideBarTask
     *
     * @return le pointeur sur une SideBarTask
     */
    SideBarTask* getSideBarTask();
    /*!
     *  @brief Récupère un pointeur sur une SideBarSummary
     *
     * @return le pointeur sur une SideBarSummary
     */
    SideBarSummary* getSideBarSummary();

    /*!
     *  @brief Récupère un pointeur sur une SideBarCalendar
     *   @return le pointeur sur une SideBarCalendar
     *
     */
    SideBarCalendar* getSideBarCalendar();
    /*!
     *  @brief Récupère un pointeur sur une ToolBarCalendar
     *   @return le pointeur sur une ToolBarCalendar
     *
     */
    ToolBarCalendar *getToolBarCalendar();

    /*!
     *  @brief Cache la SideBar
     *  Lorsqu'il n'y a plus de tâche listée, la SideBar est cachée
     *
     */
    void hideSidebar();
    /*!
     *  @brief Montre la SideBar
     *  Tant qu'il y à des tâches affichée, la SideBar est visible
     *
     */
    void showSidebar();

private slots:

    /*!
     *  @brief lorsque la vue tâche est séléctionnée cette fonction est solicitée
     *
     */
    void on_actionGoToTask_triggered();
    /*!
     *  @brief lorsque la vue calendrier est séléctionnée cette fonction est solicitée
     *
     */
    void on_actionGoToCal_triggered();
    /*!
     *  @brief lorsque la vue résumé est séléctionnée cette fonction est solicitée
     *
     */
    void on_actionGoToResume_triggered();

private:
    /*!
     *  @brief intialisation des éléments de la MainToolBar
     *  Comprenant les boutons de séléction des trois vues principales
     */
    void initMainToolbar();
    /*!
     *  @brief intialisation des éléments de la EditToolBar
     */
    void initEditToolBar();
    /*!
     *  @brief intialisation des éléments de design
     */
    void initStyleSheet();

signals:
    /*!
     *  @brief signal emis lorsque la vue Calendrier est appelée
     */
    void to_cal_triggered();

};


#endif // MAINWINDOW_H
