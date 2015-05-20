#ifndef TOOLBARSUMMARY_H
#define TOOLBARSUMMARY_H


#include <QObject>
#include <QToolBar>
#include <QLabel>
#include "toolbutton.h"
#include "models/task.h"

namespace Ui {
class MainWindow;
}


class ToolBarSummary : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    Ui::MainWindow *ui;

public:
    explicit ToolBarSummary(Ui::MainWindow *ui);
    ~ToolBarSummary();
};

#endif // TOOLBARSUMMARY_H
