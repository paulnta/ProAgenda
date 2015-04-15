#ifndef EDITTOOLBAR_H
#define EDITTOOLBAR_H

#include <QObject>
#include <QToolBar>
#include <QDebug>
#include "toolbutton.h"


class EditToolBar : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    ToolButton* addButton;
    QAction* addTask;
    QAction* addUnit;

public:
    EditToolBar();
    ~EditToolBar();

private slots:
    void onAddtaskTriggered();
    void onAddunitTriggered();
};

#endif // EDITTOOLBAR_H
