#ifndef SIDEBARTASK_H
#define SIDEBARTASK_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QKeyEvent>
#include "sqlconnection.h"
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QSqlRelationalDelegate>
#include "viewTask/tristatebutton.h"


class Task;

namespace Ui {
class sideBarTask;
}

/*! @class SideBarTask
 *  Classe gérant le widget de la bar latérale
 */
class SideBarTask : public QWidget
{
    Q_OBJECT

public:
    /*!
     *  @brief Constructeur
     *  Constructeur de la classe SideBarTask
     *  @param parent : widget parent
     */
    explicit SideBarTask(QWidget *parent = 0);
    /*!
     *  @brief Destructeur
     *  Destructeur de la classe SideBarTask
     */
    ~SideBarTask();

    /*!
     *  @brief Récupère le pointeur sur le mapper de données
     *  @return le pointeur sur le mapper
     */
    QDataWidgetMapper* getMapper();

private:
    Ui::sideBarTask *ui;
    QVBoxLayout* layout;
    QComboBox *courseDropDown ;

    QLineEdit *taskName;
    QWidget *radioButtons;
    QTextEdit *description;
    QCheckBox *hasTerm;
    QDateTimeEdit *termDate;
    TriStateButton* priority;
    TriStateButton* taskType;
    QPushButton *btnSubmit;
    QSqlTableModel *relModel;
    QSqlRelationalTableModel *model;
    QLabel* debugRow; // debug

    // SQL RELATIONAL
    QDataWidgetMapper *mapper;
    int courseIndex;

protected:

    /*!
     *  @brief Evenement lorqu'une touche est relâchée
     *  Lorsque la touche entrée est relâchée les données
     *  de la tâche en édition sont sauvegardée
     *  @param event : la touche relâchée
     */
    void keyReleaseEvent(QKeyEvent* event);

signals:
    /*!
     *  @brief signal de modification d'une tâche
     */
    void isUpdated();

    /*!
     *  @brief signal rafraichissement
     *  Lorsque la liste des tâches à besoin d'être
     *  rafraichie ce signal est envoyé
     */
    void needRefresh();
    /*!
     *  @brief signal de changement de séléction
     *  Lorsque la liste des tâches est modifié la ligne de la tâche est gardée en mémoire
     *  afin de rester séléctionnée après un tri par exemple
     *  @param int : la ligne de la tâche
     */
    void changeSelection(int);

public slots:
    /*!
     *  @brief chargement des tâches
     *  La tâche est chargée dans la SideBar
     *  @param int : la ligne de la tâche
     */
    void loadTask(int);
    /*!
     *  @brief sauvegarde des changement
     *  La tâche est enregistrée dans la base de donnée
     *  @param int : la ligne de la tâche
     */
    void submitTask();
};

#endif // SIDEBARTASK_H
