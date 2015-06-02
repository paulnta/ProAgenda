#include "minitasklist.h"

MiniTaskList::MiniTaskList(QWidget *parent): QWidget(parent)
{
    taskInstance = Task::getInstance();
    model = taskInstance->getModel();
    // Layout principale affichant une liste vertical de TaskCheckBox
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    setFixedWidth(300);
    setFixedHeight(400);
    setUpTaskList();
}

MiniTaskList::~MiniTaskList()
{

}

void MiniTaskList::MiniTaskList::setUpTaskList()
{
    // S'assurer que la vue est propre
    clearView();

    if(model->rowCount() == 0){
        layout->addWidget(new QLabel("Pas de tâche.."));
    }
    // Création de widget mappé avec le model
    for(int i = 0; i < model->rowCount();i++)
        layout->addWidget(createTaskItem(i),0, Qt::AlignTop);

    // alignement des tâche en haut
    layout->addStretch(1);
}

void MiniTaskList::clearView()
{
    // Chaques widgets du layout est supprimé
    QLayoutItem* child;
    while((child = layout->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }

    // suppression de la liste de TaskCheckBox
    items.clear();
}

void MiniTaskList::refreshTaskList(){
    setUpTaskList();
}


TaskListItem *MiniTaskList::createTaskItem(int modelRow)
{
    TaskListItem* taskItem = new TaskListItem(modelRow);
    items.append(taskItem);

    // Un changement depuis la sidebar ou le model doit mettre à jour chaque elements
    connect(taskInstance, SIGNAL(modelUpdated()), taskItem, SLOT(updateTaskWidget()));

    // Fin d'une tâche
    connect(taskItem, SIGNAL(needRefreshTask()), this, SLOT(refreshTaskList()));

    return taskItem;
}
