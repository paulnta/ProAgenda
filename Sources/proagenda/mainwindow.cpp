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


    // Initialisation des widgets
    sideBarTask = new SideBarTask;
    sideBarSummary = new SideBarSummary;
    taskDisp = new taskDisplay(this);

    connect(Task::getInstance(),SIGNAL(newTask()), taskDisp, SLOT(addTask()));

    // Initialisation des Barres d'outils
    initMainToolbar();
    initEditToolBar();


    // Initialisation des Sidebars
    this->ui->viewAddTask->addWidget(sideBarTask);
    this->ui->viewSidebarSummary->addWidget(sideBarSummary);

    // initialisation des vues
    this->ui->viewTask->addWidget(taskDisp);
    this->ui->viewCalendar->addWidget(new CalendarWidget);
    this->ui->viewResume->addWidget( new VSummary(this));


    // Widgets Affiché par defaut au démmarge
    this->ui->stackedWidgetCentral->setCurrentIndex(0); // taskWidget (position 0 dans la stackWidget)
    this->ui->stackedWidgetSide->setCurrentIndex(0);    // addtaskWidget (position 0 dans la stackWidget)

//    connect(editToolBar, SIGNAL(newTask(QSqlRecord,int)), taskDisp, SLOT(addTask(QSqlRecord,int)));

}

SideBarTask *MainWindow::getSideBarTask()
{
    return sideBarTask;
}

SideBarSummary *MainWindow::getSideBarSummary()
{
    return sideBarSummary;
}

void MainWindow::initEditToolBar(){

    editToolBar = new EditToolBar(ui);
    this->ui->editLayout->addWidget(editToolBar);
    QFont font("Helvetica");
    font.setWeight(QFont::Light);
    font.setPixelSize(11);
    this->editToolBar->setFont(font);
    this->ui->mainToolBar->setFont(font);
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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sideBarTask;
    delete editToolBar;
    delete sideBarSummary;
    delete taskDisp;
}
