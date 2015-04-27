#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "viewTask/type.h"
#include <QDate>
#include <QString>
#include <QLayout>

class TaskModel
{
public:
    TaskModel(QString name, QString description, QDate termDate);
    ~TaskModel();
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

    Type getType() const;
    void setType(const Type &value);

private:
    QString name;
    QString description;
    QDate termDate;
    double note;
    int priority;
    bool finished;
    double coefficient;
    Type type;
};

#endif // TASKMODEL_H
