#ifndef COLUMNDAY_H
#define COLUMNDAY_H

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include "lessonrect.h"
#include "models/lesson.h"
#include "calendarcolumn.h"


/*!
 * \brief Colonne d'un jour dans le calendrier
 *
 * Les colonnes des jours sont basée sur la classe CalendarColumn
 * Chaque ligne contient un widget vide servant uniquement à afficher une séparation
 * au niveau de chaque heures.
 *
 * Les rectangles des leçons sont dessinés par dessus le grille au moyen d'un painter.
 * Ce painter est mis à jour à chaque repaint de la fenêtre en cherchant les la liste des leçons
 * dans la base de donnée.
 *
 * Chaque repaint ne fait pas un accès à la base de donnée ce qui serait trop lourd,
 * mais recherche plutôt dans une liste stockée dans cette classe représentant le dernier état
 * de la base de donnée. Cette liste est mise à jour seulement lors du mise à jour dans la base de donnée.
 *
 */
class ColumnDay : public CalendarColumn
{
    Q_OBJECT

    int idSelectedLesson;
    QDate* date;
    QList<LessonRect*> lessPerDay;
    QSqlRelationalTableModel *modelLesson;
    QSqlRelationalTableModel *modelTask;
    Task* taskInstance;



public:
    /*!
     * \brief Constructeur
     * \param modelLesson: model observant la table Leçon
     * \param date: date courrante de la colonne
     * \param parent: widget parent
     */
    explicit ColumnDay(QSqlRelationalTableModel *modelLesson, QDate* date ,QWidget* parent = 0);
    ~ColumnDay();

    /*!
     * \brief paintEvent est redéfinie afin de pouvoir dessiner les rectangles des leçons
     * \param event: type de l'événement
     */
    void paintEvent(QPaintEvent *event);

    /*!
     * \brief séléctionne une leçon affiché sur le calendrier selon une heure
     * \param hour: heure de la leçon. L'heure cherchée doit se trouver entre l'heure de début et de fin
     * de d'une leçon.
     */
    void selectLessonByHour(double hour);

public slots:
    /*!
     * \brief récpuère les éventuels modifications effectuées dans la base de donnée
     * puis met à jour la vue calendrier
     */
    void updateValues();

    /*!
     * \brief désélectionne une leçon
     *
     * Une seule leçon peut être sélectionné par jour. Si une leçon est actuellement sélectionnée,
     * elle sera désélectionnée.
     */
    void deselectLesson();

    /*!
     * \brief séléctionne un leçon
     * \param id: id de la leçon à selectionner
     */
    void selectLesson(int id);

    /*!
     * \brief récupère le jour de la semaine courant pour cette colonne
     * \return
     */
    int getDayOfWeek();

signals:

    /*!
     * \brief indique qu'une leçon est séléctionnée
     * \param dayOfWeek: jour de la semaine. Sert à identifier dans quelle colonne
     * la sélection à été effectuée.
     */
    void lessonSelected(int dayOfWeek);

    /*!
     * \brief indique qu'une leçon est séléctionnée
     * \param date: date de la leçon
     * \param courseName: nom du cours
     */
    void lessonSelected(QDate date, QString courseName);

    /*!
     * \brief indique qu'une la colonne à été séléctionnée.
     * Ce signal est envoyé seulement quand uniquement une colonne est séléctionnée
     * Par exemple quand on clique en dehors des rectangles des leçons.
     */
    void columnDaySelected(int);

protected:
    /*!
     * \brief mousePressEvent redéfinie afin de capturer les événements de clics de souris
     * à l'intérieur d'une colonne
     */
    void mousePressEvent(QMouseEvent *);
};

#endif // COLUMNDAY_H
