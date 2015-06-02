#ifndef TOOLBARSUMMARY_H
#define TOOLBARSUMMARY_H

#include <QMenu>
#include <QToolBar>

#include "utils/toolbutton.h"
#include "vsummary.h"

namespace Ui {
class MainWindow;
}

/*! \class ToolBarSummary
 * \brief Classe représentant la tool bar (barre affiché au sommet de la vue)
 *
 * Elle contient seulement le bouton d'ajout des cours et semestres.
 */
class ToolBarSummary : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

private:
    Ui::MainWindow *ui;
    ToolButton* addButton;
    QAction* addSemester;
    QAction* addCourse;
    VSummary *vSummary;

public:
    /*!
     * \brief Constructeur de la classe ToolBarSummary
     *
     * \param ui : La fenêtre principale du programme
     * \param vSummary : La fenêtre contenant le VCourseFill (vue résumé).
     *
     */
    explicit ToolBarSummary(Ui::MainWindow *ui, VSummary *vSummary);

    /*!
     * \brief Destructeur de la classe VCourseFill
     */
    ~ToolBarSummary();

private slots:
    // Actions lors du clique sur les boutons
    virtual void onAddCourseTriggered();
    virtual void onAddSemesterTriggered();
};

#endif // TOOLBARSUMMARY_H
