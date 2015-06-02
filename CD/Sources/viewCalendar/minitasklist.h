#ifndef MINITASKLIST_H
#define MINITASKLIST_H
#include <QWidget>
#include <QLabel>
#include <QList>
#include <QSqlRelationalTableModel>

#include "viewTask/tasklistitem.h"


/*!
 * \brief MiniTaskList est une vue personnalisée d'une model Task
 * Elle affiche une liste allégé de tâches
 */
class MiniTaskList : public QWidget
{
    Q_OBJECT

private:

    QVBoxLayout* layout;
    QList<TaskListItem*> items;
    QSqlRelationalTableModel* model;
    Task* taskInstance;

public:
    /*!
     * \brief Constructeur
     * \param parent: widget parent
     */
    explicit MiniTaskList(QWidget* parent = 0);
    ~MiniTaskList();

    /*!
     * \brief Construction de la liste des tâche selon
     * l'état courant du model
     */
    void setUpTaskList();

    /*!
     * \brief Efface la liste des tâches
     */
    void clearView();

    /*!
     * \brief Création d'un élément de la liste
     * \param modelRow: numéro de ligne du model correspondant à l'élement voulu.
     *
     * L'élément de la liste est mappé en fonction du numéro de ligne du model Task
     * Ainsi chaque ligne se mettra à jour si le model est changé.
     */
    TaskListItem *createTaskItem(int modelRow);

public slots:
    /*!
     * \brief rafraichissment de la liste des tâche
     * Efface la liste des tâche est reconstruit la liste selon le nouvel état du model
     */
    void refreshTaskList();

};

#endif // MINITASKLIST_H
