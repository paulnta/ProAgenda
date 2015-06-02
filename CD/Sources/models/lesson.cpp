#include "lesson.h"
#include "course.h"

Lesson* Lesson::instance = NULL;

Lesson::Lesson()
{
    model = new QSqlRelationalTableModel(0, SqlConnection::getInstance()->getDatabase());
    model->setTable("Lesson");
    sortBy(DAY_OF_WEEK);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    courseIndex = model->fieldIndex("courseId");

    model->setRelation(courseIndex, QSqlRelation("Course", "id", "name"));
    update();
}

Lesson::~Lesson()
{
    // Nettoyer le modèle de libérer les ressources utilisées pour le gérer
    // model->clear();
    // Supprimer le pointeur de l'instance;
    delete instance;
    // Supprimer le pointeur du modèle
    delete model;
}

Lesson::Sorting Lesson::getCurrentSort() const
{
    return currentSort;
}

void Lesson::setCurrentSort(const Sorting &value)
{
    currentSort = value;
}

int Lesson::getCourseIndex() const
{
    return courseIndex;
}

void Lesson::update(bool needClear)
{
    model->select();

    if(needClear) {
        //emit modelFiltered();
    }else {
        //emit modelUpdated();
    }

}

Lesson* Lesson::getInstance()
{
    if(instance == NULL) {
        instance = new Lesson;
    }

    return instance;
}

QSqlRelationalTableModel* Lesson::getModel() const
{
    return model;
}

void Lesson::sortBy(Sorting sort,const Qt::SortOrder &order)
{
    switch(sort){
    case DAY_OF_WEEK:
        model->setSort(model->fieldIndex("dayOfWeek"), order);
        break;
    }

    currentSort = sort;
    update();
}

int Lesson::rowCount() const
{
    return model->rowCount();
}
