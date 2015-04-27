#ifndef TASKTYPE_H
#define TASKTYPE_H

#include <QString>

class TaskType
{
    QString name;
    double weighting;

public:
    TaskType();
    ~TaskType();
    QString getName() const;
    void setName(const QString &value);
    double getWeighting() const;
    void setWeighting(double value);
};

#endif // TASKTYPE_H
