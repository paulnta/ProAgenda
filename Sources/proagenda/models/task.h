#ifndef TASK_H
#define TASK_H

#include "taskType.h"
#include <QDate>
#include <QString>
#include <QLayout>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
class Task
{
public:
    Task(int id, QString name, QString description, QDate termDate,
         double note, int priority,bool finished, double coefficient,
         TaskType* taskType, int courseId);
    Task(const QSqlRecord & values, const int& row);
    ~Task();
    QString getName();
    bool isFinished();
    QString getDescription() const;
    void setDescription(const QString &value);

    static QSqlRelationalTableModel *getModel();
    static void setupModel();


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

    static int getTypeIndex();
    static void setTypeIndex(int value);

private:
    int id;
    QString name;
    QString description;
    QDate termDate;
    double note;
    int priority;
    bool finished;
    double coefficient;
    TaskType* taskType;
    int courseId;
    const int row;
    static int typeIndex;

    // SQL RELATIONAL
    static QSqlRelationalTableModel *model;

};

#endif // TASK_H
