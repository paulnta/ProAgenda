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

    /// Le Tris Pose problème l'aura de la modification d'une tâche,
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

void Task::update() {
    model->select();
}

Task::~Task()
{
    delete instance;
}

Task* Task::getInstance() {
    if(instance == NULL) {
        instance = new Task;
    }

    return instance;
}

QSqlRelationalTableModel* Task::getModel(){
    return model;
}

void Task::addTask(){

    QSqlRecord record = model->record();

    record.setValue(1,"new Task");
    record.setValue(8,1);
    record.setValue(9,1);

    model->insertRecord(-1,record);
    model->submitAll();

    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error", model->lastError().text());
    }

    emit newTask();

}

void Task::removeTask(int row)
{
    model->removeRow(row);
    model->submitAll();
    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error", model->lastError().text());
    }
}

int Task::rowCount()
{
    return model->rowCount();
}

