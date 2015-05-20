#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableView>

#include "taskcheckbox.h"


namespace Ui {
class taskDisplay;
}

class MainWindow;

class taskDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit taskDisplay( MainWindow* main_ui, QWidget *parent = 0);
    void setUpTaskList();
    ~taskDisplay();

    void refreshTaskList();
private:
    typedef QList<TaskCheckBox*> TypeTaskList;

    QWidget* listTask;
    TaskCheckBox* selectedWidget;
    TypeTaskList* tasks;
    QVBoxLayout* layout;
    Ui::taskDisplay *ui;
    MainWindow* main_ui;
    QSqlRelationalTableModel *model;

protected:

    /**
     * Gestion des raccourcis claviers
     * Touche Up/Down pour parcourir les tâches
     *
     * @brief keyReleaseEvent
     * @param event
     */
    void keyReleaseEvent(QKeyEvent* event);

    /**
     * Gestion du click sur la vue principale
     * En cas d'un clique gauche on donne le focus à la vue
     * Cela permet d'utiliser les raccourcis claviers
     *
     * @brief mouseReleaseEvent
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void isUpdated();

public slots:
    void updateTaskWidget();
    void addTask();
    void selectWidget(int row);
    void removeTask(int row);
};

#endif // TASKDISPLAY_H
