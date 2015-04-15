#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialisation des Barres d'outils
    initMainToolbar();
    initEditToolBar();

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

}

void MainWindow::on_actionGoToTask_triggered()
{
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToResume->setChecked(false);
    this->ui->actionAddTask->setChecked(true);
}

void MainWindow::on_actionGoToCal_triggered()
{
    this->ui->actionGoToResume->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);
    this->ui->actionGoToCal->setChecked(true);
}

void MainWindow::on_actionGoToResume_triggered()
{
    this->ui->actionGoToCal->setChecked(false);
    this->ui->actionGoToTask->setChecked(false);
    this->ui->actionGoToResume->setChecked(true);
}

