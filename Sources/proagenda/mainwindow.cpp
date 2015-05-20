#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QListView>
#include <QListWidget>
#include <QPushButton>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //init Database and models
    SqlConnection::getInstance();

    // Initialisation des sidebars
    sideBarTask = new SideBarTask;
    sideBarSummary = new SideBarSummary;
    viewSummary = new VSummary(this);

    // Initialisation des vues
    taskDisp = new taskDisplay(this);
    calendarWidget = new CalendarWidget;

    // Initialisation des Barres d'outils
    initMainToolbar();
    initEditToolBar();

    // Initialisation des Sidebars
    ui->viewAddTask->addWidget(sideBarTask);
    ui->viewSidebarSummary->addWidget(sideBarSummary);

    // initialisation des vues
    ui->viewTask->addWidget(taskDisp);
    ui->viewCalendar->addWidget(calendarWidget);
    ui->viewResume->addWidget(viewSummary);

    // Widgets Affiché par defaut au démmarge
    ui->stackedWidgetCentral->setCurrentIndex(0); // taskWidget (position 0 dans la stackWidget)
    ui->stackedWidgetSide->setCurrentIndex(0);    // addtaskWidget (position 0 dans la stackWidget)
    toolBarStackedWidget->setCurrentIndex(0);     // toolBarTask (position 0 dans la toolBarStackedWidget)

    connect(Task::getInstance(),SIGNAL(newTask()), taskDisp, SLOT(addTask()));
    connect(sideBarTask->getMapper(), SIGNAL(currentIndexChanged(int)), taskDisp, SLOT(selectWidget(int)));
}

void MainWindow::initEditToolBar(){

    toolBarStackedWidget = new QStackedWidget;
    this->ui->editLayout->addWidget(toolBarStackedWidget);

    toolBarTask = new ToolBarTask(ui);
    toolBarCalendar = new ToolBarCalendar(ui);
    toolBarSummary = new ToolBarSummary(ui);

    toolBarStackedWidget->addWidget(toolBarTask);
    toolBarStackedWidget->addWidget(toolBarCalendar);
    toolBarStackedWidget->addWidget(toolBarSummary);

}

void MainWindow::initMainToolbar(){

    setUnifiedTitleAndToolBarOnMac(true);

    /* Centrage des bouton dans la ToolBar
    =======================================*/

    // Ajout de widget vide à gauche et à droite
    QWidget* spacerLeft = new QWidget(this->ui->mainToolBar);
    QWidget* spacerRight = new QWidget(this->ui->mainToolBar);

    // Les widgets Occupe une place maximum horizontalment (Expanding)
    spacerLeft->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    spacerRight->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    this->ui->mainToolBar->insertWidget(this->ui->actionGoToTask,spacerLeft);
    this->ui->mainToolBar->addWidget(spacerRight);
    this->ui->actionGoToTask->setChecked(true);
}

/**
 * Lors d'un clique sur un bouton de la vue, On affiche le widget Correspondant
 *
 * Pour Switcher d'une vue à l'autre, le contenu principale est un stackedWidget.
 * les fonction : setCurrentIndex et SetCurrentWidgetpermettent d'afficher le widget voulu.
 *
 * @brief MainWindow::on_actionGoToTask_triggered
 */
void MainWindow::on_actionGoToTask_triggered()
{
    // On Séléctionne tâche
    this->ui->actionAddTask->setChecked(true);

    // On désélectionne les 2 autres
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToResume->setChecked(false);

    //On switch vers le widget viewTask
    this->ui->stackedWidgetCentral->setCurrentWidget(this->ui->taskWidget);
    this->ui->stackedWidgetSide->setCurrentWidget(this->ui->addTaskWidget);
    toolBarStackedWidget->setCurrentWidget(toolBarTask);
}

void MainWindow::on_actionGoToCal_triggered()
{
    // On Séléctionne tâche
    this->ui->actionGoToCal->setChecked(true);

    // On désélectionne les 2 autres
    this->ui->actionGoToResume->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);

    //On switch vers le widget viewCalendar
    this->ui->stackedWidgetCentral->setCurrentWidget(this->ui->calendarWidget);
    toolBarStackedWidget->setCurrentWidget(toolBarCalendar);
}

void MainWindow::on_actionGoToResume_triggered()
{
    // On Séléctionne tâche
    this->ui->actionGoToResume->setChecked(true);

    // On désélectionne les 2 autres
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);

    //On affiche le widget ViewResume
    this->ui->stackedWidgetCentral->setCurrentWidget(this->ui->resumeWidget);
    this->ui->stackedWidgetSide->setCurrentWidget(this->ui->summaryWidget);
    toolBarStackedWidget->setCurrentWidget(toolBarSummary);
}

SideBarTask *MainWindow::getSideBarTask()
{
    return sideBarTask;
}

SideBarSummary *MainWindow::getSideBarSummary()
{
    return sideBarSummary;
}

MainWindow::~MainWindow()
{
    delete ui;

    delete taskDisp;
    delete viewSummary;
    delete calendarWidget;

    delete sideBarTask;
    delete sideBarSummary;

    delete toolBarTask;
    delete toolBarCalendar;
    delete toolBarSummary;
    delete toolBarStackedWidget;
}
