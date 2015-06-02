#ifndef VCOURSEDETAILS_H
#define VCOURSEDETAILS_H

#include <cmath>
#include <QLabel>
#include <QLayout>
#include <QLayoutItem>
#include <QListWidget>
#include <QSqlQuery>
#include <QScrollArea>
#include <QSqlRecord>
#include <QTableWidget>
#include <QWidget>

#include "vlessonfill.h"

namespace Ui {
class VCourseDetails;
}

class VSummary;

/*! \class VCourseDetails
 * \brief Classe représentant l'affichage des détails des cours.
 *
 *  Représente les 3 onglets du bas lors de la sélection d'un jour.
 */
class VCourseDetails : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VCourseDetails
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le VCourseDetails (vue résumé).
     *
     */
    explicit VCourseDetails(QWidget *parent = 0, VSummary* vSummary = 0);

    /*!
     * \brief Destructeur de la classe VCourseFill
     */
    ~VCourseDetails();

    /*!
     * \brief Prépare les informations à afficher.
     *
     *  Rempli les différents onglet en fonction du cours passé en paramètre.
     *
     *  \param course : Le sql record correspondant au cours sélectionné.
     */
    void prepare(QSqlRecord course);

    /*!
     * \brief Rafraîchit la liste des leçons.
     *
     *  Rafraîchit la liste des lecçons lors de l'ajout/modification d'une leçon.
     */
    void refreshLessons();

private:
    Ui::VCourseDetails *ui;
    QSqlRecord course;
    int currentCourseId;
    VSummary *vSummary;

private:
    // Charge les informations dans les différents onglets
    void loadTabGeneralView();
    void loadTabLesson();
    void loadTabTask();
};

#endif // VCOURSEDETAILS_H
