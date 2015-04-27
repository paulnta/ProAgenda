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
//=======
//    TaskModel(QString name, QString description, QDate termDate);
//    TaskModel(const TaskModel& task);
//    ~TaskModel();
//>>>>>>> 7fb8b79ef52971f33d1de09529af348cdd88b578:Sources/proagenda/viewTask/taskmodel.h
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
    int id;
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
