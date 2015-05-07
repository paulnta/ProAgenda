#ifndef EDITTOOLBAR_H
#define EDITTOOLBAR_H

#include <QObject>
#include <QToolBar>
#include <QDebug>
#include <QLabel>
#include "toolbutton.h"
#include "models/task.h"

namespace Ui {
class MainWindow;
}

class EditToolBar : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    ToolButton* addButton;
    QAction* addTask;
    QAction* addUnit;
    Ui::MainWindow *ui;
    QLabel* myLabel;

public:
    explicit EditToolBar(Ui::MainWindow *ui);
    ~EditToolBar();

signals:
    void newTask();

private slots:
    void onAddtaskTriggered();
    void onAddunitTriggered();
};

#endif // EDITTOOLBAR_H
