#ifndef TASKLISTITEM_H
#define TASKLISTITEM_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QDataWidgetMapper>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlRelationalTableModel>

#include "priority.h"
#include "sidebartask.h"
#include "termdate.h"
#include "gradedialogbox.h"


class TaskListItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskListItem(int row, QWidget* parent = 0);
    ~TaskListItem();

private:

    QWidget* taskWidgetWrapper;
    QHBoxLayout* taskLayout;

    int row;
    static QString defaultCSS;
    static QString selectedCSS;

    QCheckBox* checkbox;
    QLabel* taskName;
    Priority* priority;
    QLabel* course;
    QLabel* desc;
    gradedialogbox *dialogNote;

    QDataWidgetMapper* mapper;
    QSqlRelationalTableModel* model;
    void setUpLayout();
signals:

    void editTask(int);
    void needRefreshTask();

public slots:
    void updateTaskWidget();
    void checkboxChecked(int);
    void checkBoxClicked(bool);
    void getGradeAndCoeff();
    void changedCanceled();
};

#endif // TASKLISTITEM_H
