#include "tasktype.h"


TaskType::TaskType()
{

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
