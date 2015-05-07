#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>

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
    typedef QList<taskCheckBox*> taskList;

    taskCheckBox* selectedWidget;
    taskList* tasks;
    QVBoxLayout* layout;
    Ui::taskDisplay *ui;
    MainWindow* main_ui;
    QSqlRelationalTableModel *model;

protected:
    void keyReleaseEvent(QKeyEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void isUpdated();


public slots:
    void updateTaskWidget();
    void selectWidget(int row);

};

#endif // TASKDISPLAY_H
