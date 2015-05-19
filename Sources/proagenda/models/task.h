#ifndef TASK_H
#define TASK_H

#include "taskType.h"
#include <QDate>
#include <QString>
#include <QLayout>
#include <QSqlRecord>

#include <QSqlRelationalTableModel>

class Task : public QObject
{
    Q_OBJECT

private:

    Task();
    static Task* instance;
    int courseIndex;

    // SQL RELATIONAL
    QSqlRelationalTableModel *model;

public:
    ~Task();

    void update();
    static Task* getInstance();
    QSqlRelationalTableModel* getModel();

    int getCourseIndex() const;
    void addTask();

signals:
    void newTask();

};

#endif // TASK_H
