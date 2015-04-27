#include "tasktype.h"


TaskType::TaskType()
{

}

TaskType::TaskType(QString name, double weighting):name(name),weighting(weighting){

}

QString TaskType::getName() const
{
    return name;
}

void TaskType::setName(const QString &value)
{
    name = value;
}

double TaskType::getWeighting() const
{
    return weighting;
}

void TaskType::setWeighting(double value)
{
    weighting = value;
}

TaskType::~TaskType()
{

}
