#ifndef TOOLBARTASK_H
#define TOOLBARTASK_H

#include <QObject>
#include <QToolBar>
#include <QLabel>
#include "toolbutton.h"
#include "models/task.h"

namespace Ui {
class MainWindow;
}


class ToolBarTask : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    ToolButton* addButton;
    QAction* addTask;
    QAction* addUnit;
    QLabel* myLabel;
    Ui::MainWindow *ui;

public:
    explicit ToolBarTask(Ui::MainWindow *ui);
    ~ToolBarTask();

signals:
    void newTask();

private slots:
    void onAddtaskTriggered();
    void onAddunitTriggered();
};


#endif // TOOLBARTASK_H
