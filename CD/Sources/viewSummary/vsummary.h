#ifndef VSUMMARY_H
#define VSUMMARY_H

#include <QWidget>
#include "vsemesterfill.h"
#include "vcoursefill.h"
#include "vcoursedetails.h"
#include "vmodule.h"

namespace Ui {
class VSummary;
}

class MainWindow;
class SideBarTreeView;

/*! \class VSummary
 * \brief Classe représentant l'affichage lors du clique sur l'ongle résumé (vue résumé).
 *
 *  Elle va afficher les informations correspondant à la vue résumé.
 *     - La liste des semestres, des cours et des modules
 *     - La possiblités de modifier divers informations (cours, semestres, modules et leçons)
 *     - La présentation des informations pour les cours (notes ...)
 */
class VSummary : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VSummary.
     */
    explicit VSummary(MainWindow* mainWindow, QWidget *parent = 0);

    /*!
       *  \brief Destructeur de la classe VSummary.
       */
    ~VSummary();

    /*!
       *  \brief Change la vue entre cours et semestre.
       *
       *  Lors d'un clique sur un cours ou un semestre on "switch" sur la vue
       *  correspondante (cours si clique sur un cours et semestre si clique sur
       *  un semestre).
       *
       * \param isSemesterView : Est-ce qu'on affiche un cours (false) ou un semestre (true).
       */
    void switchViews(bool isSemesterView);

    /*!
       *  \brief Rafraichissement de l'affichage des modules.
       *
       *
       *  Rafraichissement de l'affichage des modules
       *  dans la fenêtre résumé.
       *  Lors de l'ajout/modification d'un module.
       *
       */
    void refreshModules();

    /*!
       *  \brief Rafraichissement de l'affichage des leçons.
       *
       *
       *  Rafraichissement de l'affichage des leçon
       *  d'un cours dans la fenêtre résumé.
       *  Lors de l'ajout/modification d'une leçon
       *
       */
    void refreshLessons();

    /*!
       *  \brief Rafraichissement de la side bar (TreeView).
       *
       *
       *  Rafraichissement de la side bar (TreeView).
       *  Lors de l'ajout/modification d'un cours/semestre.
       *
       */
    void refreshSideBar();

    /*!
       *  \brief Réinitialise et vide la vue d'ajout/modification des semestres et le layout correspondant
       */
    void emptyVSemesterFill();

    /*!
       *  \brief Réinitialise et vide la vue d'ajout/modification des cours et le layout correspondant
       */
    void emptyVCourseFill();

    /*!
       *  \brief Modifie la vue cours pour l'ajout d'un cours et modifie le layout correspondant.
       */
    void addCourse();

    /*!
       *  \brief Modifie la vue cours pour l'ajout d'un cours et le layout correspondant.
       */
    void addSemester();

    VSemesterFill *vSemesterFill;
    VCourseFill *vCourseFill;
    VCourseDetails *vCourseDetails;
    SideBarTreeView *ttv;

private:
    Ui::VSummary *ui;
    MainWindow *mainWindow;
    VModule *vModule;

    // Enlève le widget passé en paramètre du layout passé en paramètre
    void removeWidgetInLayout(QLayout *layout, QWidget *widget);
};

#endif // VSUMMARY_H
