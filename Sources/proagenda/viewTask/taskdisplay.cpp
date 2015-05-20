#include "taskdisplay.h"
#include "ui_taskdisplay.h"
#include "mainwindow.h"
#include "sqlconnection.h"

#include <QMessageBox>


taskDisplay::taskDisplay( MainWindow* main_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskDisplay),
    main_ui(main_ui)
{
    ui->setupUi(this);
    selectedWidget = NULL;
    model = Task::getInstance()->getModel();

    // Layout principale affichant une liste vertical de TaskCheckBox
    layout = new QVBoxLayout(ui->mainContent);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    // Liste des tâches
    tasks = new TypeTaskList;

    // Initialisation de la liste des tâches
    setUpTaskList();

    // Selection de la permière tâche par défaut
    if(tasks->size() > 0)
        selectWidget(0);
}

void taskDisplay::setUpTaskList()
{
    // Création de widget mappé avec le model
    for(int i = 0; i < model->rowCount();i++){
        TaskCheckBox* taskCheckBox = new TaskCheckBox(main_ui->getSideBarTask(), i);
        tasks->append(taskCheckBox);
        connect(main_ui->getSideBarTask(), SIGNAL(isUpdated()), taskCheckBox, SLOT(updateTaskWidget()));
        connect(taskCheckBox, SIGNAL(removeTask(int)), this, SLOT(removeTask(int)));
    }

    // Ajout des tâches au layout
    foreach(TaskCheckBox* task, *tasks) {
        layout->addWidget(task,0, Qt::AlignTop);
    }

    // alignement des tâche en haut
    layout->addStretch(1);
}


void taskDisplay::refreshTaskList(){

    // Clear all Items in layout
    QLayoutItem* child;
    while((child = layout->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }

    selectedWidget = NULL;
    tasks->clear();

    setUpTaskList();
    main_ui->getSideBarTask()->getMapper()->setCurrentIndex(Task::getInstance()->rowCount()-1);
}

void taskDisplay::addTask(){
    refreshTaskList();
}

void taskDisplay::removeTask(int row){
    Task::getInstance()->removeTask(row);
    refreshTaskList();
}

taskDisplay::~taskDisplay()
{
    delete ui;
    delete layout;
    delete tasks;
}

void taskDisplay::updateTaskWidget()
{
    emit isUpdated();
}

void taskDisplay::selectWidget(int row)
{

    // On remet le style par defaut à l'ancien widget selectionné
    if(selectedWidget != NULL){
        selectedWidget->setSelected(false);
    }

    // On selectionne le widget voulu
    selectedWidget = tasks->at(row);
    selectedWidget->setSelected(true);
}


void taskDisplay::keyReleaseEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Down:
        main_ui->getSideBarTask()->getMapper()->toNext();
        break;
    case Qt::Key_Up:
        main_ui->getSideBarTask()->getMapper()->toPrevious();
        break;
    case Qt::Key_Return:
        // TODO: set Task DONE !
        break;
    default:
        break;
    }
}

void taskDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        setFocus();
}

