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
}

void MainWindow::initMainToolbar(){


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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editToolBar;

}
