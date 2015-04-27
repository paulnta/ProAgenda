#include "taskmodel.h"

TaskModel::TaskModel(QString name, QString description, QDate termDate):
    name(name), description(description),termDate(termDate)
{

}

TaskModel::TaskModel(const TaskModel& task){

}

TaskModel::~TaskModel()
{

}


QString TaskModel::getName(){
    return name;
}

bool TaskModel::isFinished()
{
    return finished;
}
QString TaskModel::getDescription() const
{
    return description;
}

void TaskModel::setDescription(const QString &value)
{
    description = value;
}
QDate TaskModel::getTermDate() const
{
    return termDate;
}

void TaskModel::setTermDate(const QDate &value)
{
    termDate = value;
}
double TaskModel::getNote() const
{
    return note;
}

void TaskModel::setNote(double value)
{
    note = value;
}
int TaskModel::getPriority() const
{
    return priority;
}

void TaskModel::setPriority(int value)
{
    priority = value;
}
bool TaskModel::getFinished() const
{
    return finished;
}

void TaskModel::setFinished(bool value)
{
    finished = value;
}
double TaskModel::getCoefficient() const
{
    return coefficient;
}

void TaskModel::setCoefficient(double value)
{
    coefficient = value;
}
Type TaskModel::getType() const
{
    return type;
}

void TaskModel::setType(const Type &value)
{
    type = value;
}







