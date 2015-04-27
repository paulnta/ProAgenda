#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListView>
#include <QListWidget>
#include <QPushButton>
#include <QStringListModel>

#include <QDebug>
#include <QtSql/QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation des Barres d'outils
    initMainToolbar();
    initEditToolBar();
    initSideBar();

    /*Test Création de trois widget bidon
    ======================================*/

    testWidget = new TestWidget();
    testWidget2 = new TestWidget();
    testWidget3 = new QWidget();

    initResume();

    testWidget->setName("task");
    testWidget2->setName("Here the calendar");

    // Au démarrage testWidget est affiché
    // Les boutons de la MainToolBar pourront les changer
    this->ui->mainView->addWidget(testWidget);
}

void MainWindow::initResume(){


    vSemesterFill = new VSemesterFill();

    /*
    QVBoxLayout* layout = new QVBoxLayout(testWidget3);
    testWidget3 = new QWidget;

    /* First Widget
    ================

    QDirModel* model = new QDirModel;
    QTreeView* view = new QTreeView;
    view->setModel(model);

    /* Second Widget
    ================

    QStringList listCours;
    listCours << "PRO" << "MBT" << "RES" << "SIO" << "SER";
    QStringListModel* modelList = new QStringListModel(listCours);

    QListView* list = new QListView;
    list->setModel(modelList);

    layout->addWidget(view);
    layout->addWidget(list);
    testWidget3->setLayout(layout);
    */
}

void MainWindow::initSideBar(){
    miniCalendar = new TestCalendar;
    QListWidget* list = new QListWidget;
    QPushButton* button = new QPushButton("Pushbutton");
    QListWidgetItem* item = new QListWidgetItem(QIcon(":/icons/img/icons/ic_assignment_48px.svg"),"My task",list);

    this->ui->sideBar->addWidget(miniCalendar);
    this->ui->sideBar->addWidget(list);
}

void MainWindow::initEditToolBar(){

    editToolBar = new EditToolBar;
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

MainWindow::~MainWindow()
{
    delete ui;
    delete editToolBar;
    delete testWidget;
    delete testWidget2;
    delete testWidget3;
    delete miniCalendar;
}

/**
 * Lors D'un clique sur un bouton de la vue,
 * Afficher le widget Corresondant
 *
 * @brief MainWindow::on_actionGoToTask_triggered
 */
void MainWindow::on_actionGoToTask_triggered()
{
    // On désélectionne les 2 autres
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToResume->setChecked(false);

    // On Séléctionne tâche
    this->ui->actionAddTask->setChecked(true);

    // On ajoute le widget au layout (donc il s'affiche)
    this->ui->mainView->addWidget(testWidget);

    // On Supprimer les autres
    this->ui->mainView->removeWidget(testWidget2);
    this->ui->mainView->removeWidget(testWidget3);
    testWidget2->setParent(NULL); // important sinon ça ne marche pas
    testWidget3->setParent(NULL); // idem
}

// idem que pour on_actionGoToTask_triggered
void MainWindow::on_actionGoToCal_triggered()
{
    this->ui->actionGoToResume->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);
    this->ui->actionGoToCal->setChecked(true);

    this->ui->mainView->addWidget(testWidget2);
    this->ui->mainView->removeWidget(testWidget);
    this->ui->mainView->removeWidget(testWidget3);
    testWidget->setParent(NULL);
    testWidget3->setParent(NULL);

}

void MainWindow::on_actionGoToResume_triggered()
{
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);
    this->ui->actionGoToResume->setChecked(true);

    this->ui->mainView->addWidget(vSemesterFill);
    this->ui->mainView->removeWidget(testWidget2);
    this->ui->mainView->removeWidget(testWidget);
    testWidget2->setParent(NULL);
    testWidget->setParent(NULL);
}

