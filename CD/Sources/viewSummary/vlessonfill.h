#ifndef VLESSONFILL_H
#define VLESSONFILL_H

#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QWidget>

#include "summaryutils.h"

namespace Ui {
class vlessonfill;
}

class VSummary;


/*! \class VLessonFill
 * \brief Classe representant la zone de modification des
 *      données d'une leçon.
 *
 *  La classe affiche la leçon courante et permet la modification de
 *  celle-ci ou l'ajout d'une nouvelle leçon.
 */
class VLessonFill : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VLessonFill
     *
     * \param parent : Le widget parent.
     * \param courseId : L'id du cours qui contient la leçon en cours.
     * \param summary : Fenêtre contenant le VModuleFill (vue résumé).
     *
     */
    explicit VLessonFill(QWidget *parent = 0, int courseId = 0, VSummary *vSummary = 0);

    /*!
     * \brief Destructeur de la classe VLessonFill
     */
    ~VLessonFill();

    /*!
     * \brief Rempli les champs de l'interface.
     *
     *  \param id : Identifiant de la leçon
     *  \param name : Nom de la leçon
     *  \param startHour : Heure de début de la leçon
     *  \param endHour : Heure de fin de la leçon
     *  \param dayOfWeek : Indice du jour de la semaine de la leçon
     *  \param courseId : Identifiant du cours correspondant à la leçon
     */
    void setFieldsValue(int id, QString name, QString startHour, QString endHour, int dayOfWeek, int courseId);

    /*!
     * \brief Modifie l'état de la vue (ajout ou édition).
     *
     *  \param value : Est-ce qu'on est en modification (true) ou en ajout (false).
     */
    void setEditionMode(bool value);

private slots:
    // Actions lors du clique sur les boutons
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();

private:
    Ui::vlessonfill *ui;
    bool editionMode = false;
    int currentLessonId;
    int currentCourseId;
    VSummary *vSummary;
};

#endif // VLESSONFILL_H
