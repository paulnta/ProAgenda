#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QCheckBox>
#include <QTextEdit>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QSignalMapper>
#include <QDateTimeEdit>
#include "sqlconnection.h"
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QPushButton>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>

#include "models/task.h"
#include "termdate.h"
#include "priority.h"
#include "gradedialogbox.h"


namespace Ui {
class taskWidget;
}
class SideBarTask;

/*!
 *  @class TaskCheckBox
 * Cette classe a pour objectif de lier une checkbox signifiant la complétion d'une tâche
 * à cette tâche
 */
class TaskCheckBox : public QWidget
{
    Q_OBJECT

public:
    /*!
     *  @brief Constructeur
     *  Constructeur de la classe  TaskCheckBox
     *  @param sidebar: pointeur sur le widget de la barre latérale
     *  @param row : ligne de la tâche traitée
     *  @param parent : widget parent
     */
    explicit TaskCheckBox(SideBarTask* sidebar, int row, QWidget *parent = 0);
    /*!
     *  @brief Changement de design
     *  Changement de design d'une tâche si elle est séléctionne
     *  @param enable: true si la tâche est séléctionnée
     */
    void setSelected(bool enable);

    /*!
     *  @brief retourne la ligne de la tâche
     *  @return la ligne de la tâche
     */
    int getRow();
    /*!
     *  @brief Emet un signal lorsque la tâche est modifiée
     */
    void emitEditTask();
protected:

    /*!
     *  @brief Evénement de souris
     *  Lorsque l'on clique sur la checkbox celle si change de style
     *  et la tâche passe en mode terminé
     *  @param event: non utilisé
     */
    virtual void mousePressEvent(QMouseEvent* event);
    /*!
     *  @brief Destructeur
     *  Destructeur de la classe  TaskCheckBox
     */
    ~TaskCheckBox();

private:
    QPushButton* removeTaskBtn;
    Ui::taskWidget *ui;
    QCheckBox* checkbox;
    QLabel* taskName;
    Priority* priority;
    TermDate  * termDate;
    SideBarTask* sidebar;
    QLabel* course;
    QLabel* desc;
    QLabel* grade;
    QLabel* coefficient;
    int typeIndex;
    int row;
    gradedialogbox *dialogNote;

    QDataWidgetMapper* mapper;
    QSqlRelationalTableModel* model;

    static QString defaultCSS;
    static QString selectedCSS;

signals:

    /*!
     *  @brief signal lorsqu'une tâche est éditée
     *  @param int : la ligne de la tâche
     */
    void editTask(int);
    /*!
     *  @brief signal lorsqu'une tâche est suprimée
     *  @param int : la ligne de la tâche
     */
    void removeTask(int);
    /*!
     *  @brief signal lorsque la liste de tâche doit être rafraichie
     */
    void needRefreshTask();

public slots:
    /*!
     *  @brief récupère la ligne de la tâche courante
     */
    void updateTaskWidget();

    /*!
     *  @brief suppression de la tâche courante
     */
    void onRemoveTaskClicked();
    /*!
     *  @brief Lorsque la checkbox est validée
     *  @param int : la ligne de la tâche
     */
    void checkboxChecked(int);
    /*!
     *  @brief Lorsque la checkbox est cliquée
     *  @param bool : true si la checkbox est séléctionnée, false si elle est déséléctionnée
     *
     */
    void checkBoxClicked(bool);
    /*!
     *  @brief Récupère les valeurs une fois la tâche finie
     *  Récupération de la note ainsi que du coefficient d'une tâche notée
     */
    void getGradeAndCoeff();
    /*!
     *  @brief Si la tâche ne doit pas être passée en mode terminé
     */
    void changedCanceled();
};

#endif // TASKWIDGET_H
