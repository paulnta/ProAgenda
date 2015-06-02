#include "course.h"

Course* Course::instance = NULL;

Course::Course()
{
    model = new QSqlRelationalTableModel(0, SqlConnection::getInstance()->getDatabase());
    model->setTable("Course");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    moduleIndex = model->fieldIndex("moduleId");
    semesterIndex = model->fieldIndex("semesterId");

    model->setRelation(moduleIndex, QSqlRelation("Module", "id", "name"));
    model->setRelation(semesterIndex, QSqlRelation("Semester", "id", "name"));
    update();
}

Course::~Course()
{
    // Nettoyer le modèle de libérer les ressources utilisées pour le gérer
    // model->clear();
    // Supprimer le pointeur de l'instance;
    delete instance;
    // Supprimer le pointeur du modèle
    delete model;
}

int Course::getModuleIndex() const
{
    return moduleIndex;
}

int Course::getSemesterIndex() const
{
    return semesterIndex;
}

void Course::update()
{
    model->select();
}


Course* Course::getInstance()
{
    if(instance == NULL) {
        instance = new Course;
    }

    return instance;
}

QSqlRelationalTableModel* Course::getModel() const
{
    return model;
}

int Course::rowCount() const
{
    return model->rowCount();
}
