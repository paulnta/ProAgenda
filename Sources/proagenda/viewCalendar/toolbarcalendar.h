#ifndef TOOLBARCALENDAR_H
#define TOOLBARCALENDAR_H

#include <QObject>
#include <QToolBar>
#include <QLabel>
#include "toolbutton.h"
#include "models/task.h"

namespace Ui {
class MainWindow;
}


class ToolBarCalendar : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    Ui::MainWindow *ui;

public:
    explicit ToolBarCalendar(Ui::MainWindow *ui);
    ~ToolBarCalendar();
};

#endif // TOOLBARCALENDAR_H
