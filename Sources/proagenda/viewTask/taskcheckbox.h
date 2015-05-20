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
#include <QPushButton>
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
    int getRow();

protected:
    virtual void mousePressEvent(QMouseEvent* event);
    ~TaskCheckBox();

private:
    QPushButton* removeTaskBtn;
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QLabel* taskName;
    QLabel* priority;
    QDateTimeEdit  * termDate;
    SideBarTask* sidebar;
    QDataWidgetMapper* mapper;
    int typeIndex;

    int row;

    static QString defaultCSS;
    static QString selectedCSS;

signals:
    void editTask(int);
    void removeTask(int);

public slots:
    void updateTaskWidget();
    void onRemoveTaskClicked();
};

#endif // TASKWIDGET_H
