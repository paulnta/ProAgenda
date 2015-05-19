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
private:
    Task();
    static Task* instance;
    // SQL RELATIONAL
    QSqlRelationalTableModel *model;

public:
    ~Task();

    void update();
    static Task* getInstance();
    QSqlRelationalTableModel* getModel();

};

#endif // TASK_H
