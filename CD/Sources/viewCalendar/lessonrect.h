#ifndef LESSONRECT_H
#define LESSONRECT_H

#include <QObject>
#include <QSqlRecord>
#include <QVariant>
#include <QTime>

#include "models/lesson.h"

/*!
 * \brief LessonRect représente une leçon du calendrier
 *
 * Ce n'est pas cet objet qui est directement affiché. Il est utliser
 * pour stocker une lesson provenant de la base de donnée et de précalculer
 * certaine valeurs qui serviront à dessiner le rectangle.
 *
 */
class LessonRect: public QObject
{
    Q_OBJECT

    QSqlRecord record;
    double startTimeInHours;
    double endTimeInHours;

public:
    /*!
     * \brief Constructeur
     * \param parent: Objet parent
     */
    explicit LessonRect(const QSqlRecord&, QObject* parent = 0);
    ~LessonRect();

    /*!
     * \brief récupère l'heure de début de la leçon en heure (décimale)
     */
    double getStartTimeInHours() const;

    /*!
     * \brief récupère l'heure de fin de la leçon en heure (décimale)
     * \return
     */
    double getEndTimeInHours() const;

    /*!
     * \brief Calcule et retourne la taille en pixel de la leçon dans le calendrier
     * \param heightForHours: Taille en pixel que doit prendre un rectangle de 1 heure
     */
    double getHeight(double heightForHours) const;

    /*!
     * \brief Retourne la position y en pixel du rectangle de la leçon
     * \param heightForHours: Taille en pixel que doit prendre un rectangle de 1 heure.
     * \return
     */
    double getY(double heightForHours) const;

    /*!
     * \brief Test si l'heure passé en paramètre se trouve dans entre l'heure de début de la leçon
     * et son heure de fin.
     *
     * Utile pour savoir quel leçon à été selectionné suite à un clic de souris dans le calendrier.
     *
     * \param hour: heure à tester
     * \return
     */
    bool intersect(double hour) const;

    /*!
     * \brief récupère l'id stocké dans la base de donnée de la leçon.
     * Cette valeure est utilisée comme identifiant de leçon selectionnée.
     * \return
     */
    int getId() const;

    /*!
     * \brief récupère le nom d'une leçon
     * \return
     */
    QString getName() const;

    /*!
     * \brief récupère le nom du cours auquel appartient la leçon
     */
    QString getCourseName();

};

#endif // LESSONRECT_H
