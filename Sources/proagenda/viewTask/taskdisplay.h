#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

#include <QWidget>
#include <QLayout>
#include <QStringListModel>
#include "taskmodel.h"
#include "taskwidget.h"

namespace Ui {
class taskDisplay;
}

class MainWindow;

class taskDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit taskDisplay( MainWindow* main_ui, QWidget *parent = 0);
    ~taskDisplay();

private:
    Ui::taskDisplay *ui;
    MainWindow* main_ui;
    QList<QWidget*>* tasks;
    QVBoxLayout* layout;
};

#endif // TASKDISPLAY_H
