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

    modelTask = Task::getInstance();
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
    selectWidget(0);

    // Différents signaux du model et de la sidebar demendant à la vue de se rafrachir complétement
    connect(modelTask, SIGNAL(modelFiltered()), this, SLOT(refreshTaskList()));
    connect(main_ui->getSideBarTask(), SIGNAL(needRefresh()), this, SLOT(refreshTaskList()));

    // A l'insertion du nouvelle tâche dans le modèle, On remplit quelques valeurs par défaut
    connect(model, SIGNAL(beforeInsert(QSqlRecord&)), this, SLOT(beforeInsert(QSqlRecord&)));

    /*
     * Lors d'une mise à jour du model, on s'assure que la selection est toujours correct
     * en fonction des changements opéré dans le model, l'orde peut changer
     */
    connect(main_ui->getSideBarTask(), SIGNAL(isUpdated()), this, SLOT(retrieveSelection()));
    connect(modelTask, SIGNAL(modelUpdated()), SLOT(retrieveSelection()));
}

/**
 * @brief taskDisplay::setUpTaskList initialise/réinitialise la liste des tâches
 *
 * La liste des tâches et représentée par un layout vertical contenant
 * des widgets TaskCheckBox.
 */
void taskDisplay::setUpTaskList()
{
    // S'assurer que la vue est propre
    clearView();


    // Création de widget mappé avec le model
    for(int i = 0; i < model->rowCount();i++){
        qDebug() << "CLear :" << model->record(i).value("name");
        layout->addWidget(createTaskItem(i),0, Qt::AlignTop);
    }

    // alignement des tâche en haut
    layout->addStretch(1);
}


/*!
 * \brief taskDisplay::createTaskItem crée un widget (TaskCheckbox).
 * \param modelRow: No de ligne du model
 * \return le widget créé
 */
TaskCheckBox *taskDisplay::createTaskItem(int modelRow){

    TaskCheckBox* taskCheckBox = new TaskCheckBox(main_ui->getSideBarTask(), modelRow);
    tasks->append(taskCheckBox);

    // Un changement depuis la sidebar ou le model doit mettre à jour chaque elements
    connect(main_ui->getSideBarTask(), SIGNAL(isUpdated()), taskCheckBox, SLOT(updateTaskWidget()));
    connect(modelTask, SIGNAL(modelUpdated()), taskCheckBox, SLOT(updateTaskWidget()));

    // Suppression d'une tâche
    connect(taskCheckBox, SIGNAL(removeTask(int)), this, SLOT(removeTask(int)));
    // Fin d'une tâche
    connect(taskCheckBox, SIGNAL(needRefreshTask()), this, SLOT(refreshTaskList()));

    return taskCheckBox;
}

/*!
 * \brief taskDisplay::clearView efface la liste des éléments du layout
 */
void taskDisplay::clearView(){

    // Chaques widgets du layout est supprimé
    QLayoutItem* child;
    while((child = layout->takeAt(0)) != 0){
        delete child->widget();
        delete child;
    }

    // Le widget référencé par selectedWidget a été désalloué
    selectedWidget = NULL;

    // suppression de la liste de TaskCheckBox
    tasks->clear();
}

void taskDisplay::refreshTaskList(int rowToSelect){
    setUpTaskList();
    selectWidget(rowToSelect);
}

void taskDisplay::addTask(int row){
    refreshTaskList(row);
}

void taskDisplay::removeTask(int row){
    modelTask->removeTask(row);
    refreshTaskList();
}

void taskDisplay::beforeInsert(QSqlRecord& record)
{
    record.setValue("name", "Nouvelle tâche");
    record.setValue("priority", 1);
    record.setValue("termDate", QDateTime::currentDateTime().addDays(1));
    record.setValue("isFinished", modelTask->getCurrentFilter() != Task::TODO);
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
    if(tasks->size() > 0){
        main_ui->showSidebar();
        selectedWidget = tasks->at(row);
        selectedWidget->setSelected(true);
        idSelectedWidget = model->record(row).value("id").toInt();

        if(main_ui->getSideBarTask()->getMapper()->currentIndex() != row){
            main_ui->getSideBarTask()->getMapper()->setCurrentIndex(row);
        }

    } else {
        main_ui->hideSidebar();
        qDebug() << "ERROR SELECTION";
    }
}

void taskDisplay::retrieveSelection(){

    int row = modelTask->findRowById(idSelectedWidget);

    if(row != -1){
        selectWidget(row);
        if(main_ui->getSideBarTask()->getMapper()->currentIndex() != row){
            main_ui->getSideBarTask()->getMapper()->setCurrentIndex(row);
        }
        qDebug() << "now select " << row;
    }
    else
        qDebug() << "unable to find selection";
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

