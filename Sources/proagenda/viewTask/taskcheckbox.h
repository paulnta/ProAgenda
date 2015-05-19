#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QCheckBox>
#include <QTextEdit>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QSignalMapper>
#include <QDateTimeEdit>
#include "sqlconnection.h"
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>

#include "models/task.h"
#include "termdate.h"

namespace Ui {
class taskWidget;
}
class SideBarTask;

class TaskCheckBox : public QWidget
{
    Q_OBJECT

public:
    explicit TaskCheckBox(SideBarTask* sidebar, int row, QWidget *parent = 0);
    void setSelected(bool enable);

protected:
    virtual void mousePressEvent(QMouseEvent* event);

    ~TaskCheckBox();

private:
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QLabel* taskName;
    QWidget* priority;
    QDateTimeEdit  * termDate;
    SideBarTask* sidebar;
    QDataWidgetMapper* mapper;
    int typeIndex;

    int row;

    static QString defaultCSS;
    static QString selectedCSS;

signals:
    void editTask(int);

public slots:
    void updateTaskWidget();
};

#endif // TASKWIDGET_H
