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

/*!
*  @class taskDisplay
*  Classe gérant l'afficahge d'une liste de tâche
*/
class taskDisplay : public QWidget
{
    Q_OBJECT

public:
    /*!
    *  @brief Constructeur
    *  Contructeur de la classe taskDisplay
    *  @param main_ui : fenêtre principale
    *  @param parant : widget parent
    */
    explicit taskDisplay( MainWindow* main_ui, QWidget *parent = 0);

    /*!
    *  @brief Création de la liste des tâches
    */
    void setUpTaskList();

    /*!
    *  @brief Destructeur
    *  Destructeur de la classe taskDisplay
    */
    ~taskDisplay();

    /*!
    *  @brief Destruction de la liste des tâches
    */
    void clearView();
private:

    typedef QList<TaskCheckBox*> TypeTaskList;

    QWidget* listTask;
    TaskCheckBox* selectedWidget;
    int idSelectedWidget;
    TypeTaskList* tasks;
    QVBoxLayout* layout;
    Ui::taskDisplay *ui;
    MainWindow* main_ui;
    QSqlRelationalTableModel *model;
    Task* modelTask;

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

    /*!
    *  @brief Création d'un objet TaskCheckBox
    *  TaskCheckBoxy est composé de la tâche ainsi que de la checkbox
    *  @param modelRow : la ligne de la tâche
    */
    TaskCheckBox *createTaskItem(int modelRow);
signals:
    /*!
    *  @brief Signal émit lorqu'une tâche est modifiée
    */
    void isUpdated();
    /*!
    *  @brief Signal émit lorqu'une tâche est insérée
    *  @param int  : la ligne de la tâche
    */
    void taskInserted(int);

public slots:

    /*!
    *  @brief Rafraichissement de la liste des tâches
    *  @param selection  : la ligne de la tâche
    */
    void refreshTaskList(int selection = 0);
    /*!
    *  @brief Rafraichissement d'une tâche
    */
    void updateTaskWidget();
    /*!
    *  @brief Ajout d'une tâche
    *  @param int  : la ligne de la tâche
    */
    void addTask(int);
    /*!
    *  @brief Séléction d'une tâche
    *   Changement du design de la tâche séléctionnée
    *  @param int  : la ligne de la tâche
    */
    void selectWidget(int);

    /*!
    *  @brief Suppression d'une tâche
    *  @param row  : la ligne de la tâche
    */
    void removeTask(int row);

    /*!
    *  @brief Avant insertion d'une tâche
    *   Mise des valeurs par défaut de la  tâche
    *  @param QSqlRecord  : valeur de la tâche
    */
    void beforeInsert(QSqlRecord&);
    /*!
    *  @brief Récupération de la tâche précédemment séléctionnée
    *   En cas de tri il se peut que la tâche séléctionnée soit perdu
    *   afin de garder la séléction retrieveSelection est appellée
    */
    void retrieveSelection();

};

#endif // TASKDISPLAY_H
