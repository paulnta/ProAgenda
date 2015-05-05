#include "task.h"
#include "sqlconnection.h"

QSqlRelationalTableModel *Task::model = NULL;
int Task::typeIndex = 0;

Task::Task(int id, QString name, QString description, QDate termDate,
           double note, int priority,bool finished, double coefficient,
           TaskType* taskType, int courseId):
    id(id),name(name), description(description),termDate(termDate),
    note(note), priority(priority), finished(finished), coefficient(coefficient),
    taskType(taskType), courseId(courseId), row(0)
{

}


Task::Task(const QSqlRecord &values, const int& row):
    id(values.value("id").toInt()),name(values.value("name").toString()), description(values.value("description").toString()),termDate(values.value("termDate").toDate()),
    note(values.value("note").toDouble()), priority(values.value("priority").toInt()), finished(values.value("finished").toBool()), coefficient(values.value("coefficient").toDouble()),
    taskType(NULL), courseId(values.value("courseId").toInt()), row(row)
{

}

Task::~Task()
{

}


QString Task::getName(){
    return name;
}

bool Task::isFinished()
{
    return finished;
}
QString Task::getDescription() const
{
    return description;
}

void Task::setDescription(const QString &value)
{
    description = value;
}
QDate Task::getTermDate() const
{
    return termDate;
}

void Task::setTermDate(const QDate &value)
{
    termDate = value;
}
double Task::getNote() const
{
    return note;
}

void Task::setNote(double value)
{
    note = value;
}
int Task::getPriority() const
{
    return priority;
}

void Task::setPriority(int value)
{
    priority = value;
}
bool Task::getFinished() const
{
    return finished;
}

void Task::setFinished(bool value)
{
    finished = value;
}
double Task::getCoefficient() const
{
    return coefficient;
}

void Task::setCoefficient(double value)
{
    coefficient = value;
}

TaskType Task::getTaskType() const
{
    return *taskType;
}

void Task::setTaskType(const TaskType &value)
{
    *taskType = value;
}
int Task::getTypeIndex()
{
    return typeIndex;
}

void Task::setTypeIndex(int value)
{
    typeIndex = value;
}


//Setting up the relation between the database and the model / view
//Displaying in the name of the course and not its ID

void Task::setupModel(){

    model = new QSqlRelationalTableModel(0, SqlConnection::getInstance()->getDatabase());
    model->setTable("task");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    typeIndex = model->fieldIndex("courseId");
    model->setRelation(typeIndex, QSqlRelation("course", "id", "name"));
    model->select();

}
QSqlRelationalTableModel* Task::getModel(){
    return model;
}


