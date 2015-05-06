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
#include <QDateTimeEdit>
#include "sqlconnection.h"
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QSqlRelationalDelegate>

#include "models/task.h"

namespace Ui {
class taskWidget;
}
class SideBarTask;

class taskCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit taskCheckBox(SideBarTask* sidebar, QWidget *parent = 0, Task* task = 0);
    void setSelected(bool enable);

protected:
    virtual void mousePressEvent(QMouseEvent* event);

    ~taskCheckBox();

private:
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QLabel* taskName;
    QWidget* priority;
    QWidget* type;
    QDateTimeEdit* termDate;
    Task* task;
    SideBarTask* sidebar;
    QDataWidgetMapper* mapper;
    int typeIndex;

    static QString defaultCSS;
    static QString selectedCSS;

signals:
    void editTask(Task* task);

public slots:
    void updateTaskWidget();
};

#endif // TASKWIDGET_H
