#include "task.h"
#include "sqlconnection.h"

#include <QMessageBox>
#include "viewTask/taskdisplay.h"

Task* Task::instance = NULL;

Task::Task()
{
    model = new QSqlRelationalTableModel(0, SqlConnection::getInstance()->getDatabase());
    model->setTable("Task");
    // De base par termDate, il faudra surement faire une fonction dans le model de tri
    sortBy(BY_DATE);
    filterBy(TODO);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    typeIndex = model->fieldIndex("typeId");
    courseIndex = model->fieldIndex("courseId");

    model->setRelation(courseIndex, QSqlRelation("Course", "id", "name"));
    update();
    needRefreshView = false;
}

Task::Sorting Task::getCurrentSort() const
{
    return currentSort;
}

void Task::setCurrentSort(const Sorting &value)
{
    currentSort = value;
}

Task::Filter Task::getCurrentFilter() const
{
    return currentFilter;
}

void Task::setCurrentFilter(const Filter &value)
{
    currentFilter = value;
}



int Task::getCourseIndex() const
{
    return courseIndex;
}

int Task::getTypeIndex() const
{
    return typeIndex;
}

void Task::update(bool needClear)
{
    model->select();

    if(needClear)
        emit modelFiltered();
    else
        emit modelUpdated();

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

    record.setValue(8,1);
    record.setValue(9,1);

    model->insertRecord(-1,record);
    model->submitAll();

    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error : ", model->lastError().text());
    }

    emit newTask(findRowById(model->query().lastInsertId().toInt()));
}

void Task::sortBy(Sorting sort,const Qt::SortOrder &order)
{
    switch(sort){
    case BY_DATE:
        model->setSort(model->fieldIndex("termDate"), order);
        break;
    case BY_COURSE:
        model->setSort(courseIndex, order);
        break;
    }

    currentSort = sort;
    update();
}


void Task::filterBy(Filter filter) {
    if(model->isDirty()){
        model->submitAll();
    }

    switch(filter){
    case TODO:
        model->setFilter("isFinished = 0");
        break;
    case DONE:
        model->setFilter("isFinished = 1");
        break;
    }
    currentFilter = filter;
    update(true);

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

int Task::findRowById(int id){

    for(int i=0; i < model->rowCount(); ++i){
        if(model->record(i).value("id").toInt() == id)
            return i;
    }

    return -1;
}
