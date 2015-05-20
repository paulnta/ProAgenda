#include "task.h"
#include "sqlconnection.h"

#include <QMessageBox>
#include "viewTask/taskdisplay.h"

Task* Task::instance = NULL;

Task::Task()
{
    model = new QSqlRelationalTableModel(0);
    model->setTable("Task");
    // De base par termDate, il faudra surement faire une fonction dans le model de tri

    /// Le Tris Pose problème lors de la modification d'une tâche,
    /// Les numéros de lignes (row) deviennent du grand n'importe quoi!
    //model->setSort(model->fieldIndex("termDate"), Qt::DescendingOrder);

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    courseIndex = model->fieldIndex("courseId");
    model->setRelation(courseIndex, QSqlRelation("Course", "id", "name"));
    update();
}

int Task::getCourseIndex() const
{
    return courseIndex;
}

void Task::update()
{
    model->select();
}

Task::~Task()
{
    // Nettoyer le modèle de libérer les ressources utilisées pour le gérer
    model->clear();
    // Supprimer le pointeur de l'instance;
    delete instance;
    // Supprimer le pointeur du modèle
    delete model;
}

Task* Task::getInstance()
{
    if(instance == NULL) {
        instance = new Task;
    }

    return instance;
}

QSqlRelationalTableModel* Task::getModel() const
{
    return model;
}

void Task::addTask()
{
    QSqlRecord record = model->record();

    record.setValue(1,"Nouvelle tâche ...");
    record.setValue(8,1);
    record.setValue(9,1);

    model->insertRecord(-1,record);
    model->submitAll();

    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error : ", model->lastError().text());
    }

    emit newTask();
}

/// Le Tris Pose problème lors de la modification d'une tâche,
/// Les numéros de lignes (row) deviennent du grand n'importe quoi!
void Task::sortBy(const QString &field,const Qt::SortOrder &order)
{
    model->setSort(model->fieldIndex(field), order);
    update();
}

void Task::filterBy(const QString &filter) {
    model->setFilter(filter);
    update();
}

void Task::removeTask(const int row)
{
    model->removeRow(row);
    model->submitAll();

    // Affichage d'erreur
    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error : ", model->lastError().text());
    }
}

int Task::rowCount() const
{
    return model->rowCount();
}

