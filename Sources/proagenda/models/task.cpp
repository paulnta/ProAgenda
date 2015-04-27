#include "task.h"

Task::Task(int id, QString name, QString description, QDate termDate,
           double note, int priority,bool finished, double coefficient,
           TaskType* taskType, int courseId):
    id(id),name(name), description(description),termDate(termDate),
    note(note), priority(priority), finished(finished), coefficient(coefficient),
    taskType(taskType), courseId(courseId)
{

}

Task::Task(const Task& task){

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

