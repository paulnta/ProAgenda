#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QSignalMapper>
#include <QDebug>
#include <QMouseEvent>

#include "taskmodel.h"

namespace Ui {
class taskWidget;
}
class SideBarTask;

class taskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit taskWidget(SideBarTask* sidebar, QWidget *parent = 0, TaskModel* task = 0);

protected:
    virtual void mousePressEvent(QMouseEvent* event){ emit editTask(task); }

    ~taskWidget();

private:
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QWidget* taskName;
    TaskModel* task;
    SideBarTask* sidebar;

signals:
    void editTask(TaskModel* task);

};

#endif // TASKWIDGET_H
