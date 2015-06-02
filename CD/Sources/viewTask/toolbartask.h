#ifndef TOOLBARTASK_H
#define TOOLBARTASK_H

#include <QObject>
#include <QToolBar>
#include <QLabel>
#include <QPushButton>

#include "utils/toolbutton.h"
#include "models/task.h"

namespace Ui {
class MainWindow;
}

/*!
*  @class ToolBarTask
*  Widget de la vue tâche permettant la création d'une nouvelle
*  tâche
*/
class ToolBarTask : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    Task* modelTask;
    QPushButton* addButton;
    QPushButton* sortButtonDate;
    QPushButton* sortButtonCourse;
    QPushButton* filterButtonToDo;
    QPushButton* filterButtonDone;
    Ui::MainWindow *ui;

    /*!
    *  @brief Mise en place de la toolbar
    */
    void setUpLayout();
    /*!
    *  @brief Initilisation des bouttons de tris
    */
    void initSorting();
    /*!
    *  @brief Initilisation des bouttons de filtres
    */
    void initFilters();
    /*!
    *  @brief Initilisation des fichiers de design
    */
    void initStyleSheet();
public:

    /*!
    *  @brief Constructeur
    *  Constructeur de le classe ToolBarTask
    *  @param ui :Fenêtre principale
    */
    explicit ToolBarTask(Ui::MainWindow *ui);
    /*!
    *  @brief Destructeur
    *  Destructeur de le classe ToolBarTask
    */
    ~ToolBarTask();


public slots:
    /*!
    *  @brief Clique sur le boutton d'ajout d'une tâche
    */
    void onAddtaskTriggered();
    /*!
    *  @brief Clique sur le boutton de tri par date
    */
    void onSortButtonDateClicked();
    /*!
    *  @brief Clique sur le boutton de tri par cours
    */
    void onSortButtonCourseClicked();
    /*!
    *  @brief Clique sur le boutton de filtre des tâches terminées
    */
    void onFilterButtonDoneClicked();
    /*!
    *  @brief Clique sur le boutton de filtre des tâches à faire
    */
    void onFilterButtonToDoClicked();

signals:
    /*!
    *  @brief Signal lorsqu'une nouvelle tâche doit être créée
    */
    void newTask();

};


#endif // TOOLBARTASK_H
