#ifndef TASK_H
#define TASK_H

#include "taskType.h"
#include <QDate>
#include <QString>
#include <QLayout>

class Task
{
public:
    Task(QString name, QString description, QDate termDate);
    Task(const Task& task);
    ~Task();
    QString getName();
    bool isFinished();
    QString getDescription() const;
    void setDescription(const QString &value);

    QDate getTermDate() const;
    void setTermDate(const QDate &value);

    double getNote() const;
    void setNote(double value);

    int getPriority() const;
    void setPriority(int value);

    bool getFinished() const;
    void setFinished(bool value);

    double getCoefficient() const;
    void setCoefficient(double value);

    TaskType getTaskType() const;
    void setTaskType(const TaskType &value);

private:
    int id;
    QString name;
    QString description;
    QDate termDate;
    double note;
    int priority;
    bool finished;
    double coefficient;
    TaskType taskType;
};

#endif // TASK_H
