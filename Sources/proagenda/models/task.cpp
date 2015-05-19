#include "task.h"
#include "sqlconnection.h"

#include <QMessageBox>


Task::Task()
{
    model = new QSqlRelationalTableModel(0);
    model->setTable("Task");
    // De base par termDate, il faudra surement faire une fonction dans le model de tri
    model->setSort(model->fieldIndex("termDate"), Qt::DescendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    int courseIndex = model->fieldIndex("courseId");
    model->setRelation(courseIndex, QSqlRelation("Course", "id", "name"));
    update();
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


