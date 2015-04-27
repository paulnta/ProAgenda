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

#include "models/task.h"

namespace Ui {
class taskWidget;
}
class SideBarTask;

class taskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit taskWidget(SideBarTask* sidebar, QWidget *parent = 0, Task* task = 0);

protected:
    virtual void mousePressEvent(QMouseEvent* event);

    ~taskWidget();

private:
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QWidget* taskName;
    Task* task;
    SideBarTask* sidebar;

signals:
    void editTask(Task* task);

};

#endif // TASKWIDGET_H
