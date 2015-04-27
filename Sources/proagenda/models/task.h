#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "models/tasktype.h"
#include <QDate>
#include <QString>
#include <QLayout>

class Task
{
public:
    Task(QString name, QString description, QDate termDate);
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

    TaskType getType() const;
    void setType(const TaskType &value);

private:
    QString name;
    QString description;
    QDate termDate;
    double note;
    int priority;
    bool finished;
    double coefficient;
    TaskType type;
};

#endif // TASKMODEL_H
