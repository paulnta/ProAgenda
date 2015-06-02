#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QScrollBar>

#include "hourcal.h"
#include "weekdate.h"
#include "columnday.h"
#include "models/lesson.h"
#include "ui_calendarwidget.h"
#include "verticalheadercalendar.h"
#include "viewCalendar/minitasklist.h"

namespace Ui {
class CalendarWidget;
}

class MainWindow;

/*!
 * \brief La class CalendarWidget gère l'affichage des leçons et des tâches
 * dans un calendrier. Ces informations sont affichées par semaine. Il est possible de naviguer
 * entre les semaines en choisissant un jour depuis le mini calendrier de la sidebar
 *
 */
class CalendarWidget : public QWidget
{
    Q_OBJECT

private:

    QList<QLabel*> daysName;
    QList<QWidget*> daysCal;
    QList<WeekDate*> weekDates;
    QList<ColumnDay*> daysGrid;
    VerticalHeaderCalendar* vHeader;

    int courseIndex;
    QSqlTableModel *relModel;
    QSqlRelationalTableModel *model;

    Ui::CalendarWidget *ui;
    MainWindow* main_ui;

public:
    /*!
     * \brief CalendarWidget
     * \param mainWindow: la fenêtre principale
     */
    explicit CalendarWidget(MainWindow *mainWindow);

    /*!
     * \brief Getter pour la barre de défilement
     */
    QScrollBar* getVerticalScrollbar();

     ~CalendarWidget();

private:
    /*!
     * \brief Initialisation de layout
     * Crée le headerHorizontal contenant les dates de la semaine
     * Crée le headerVertival contentant les heures
     * Crée le contenu principale : une grille de jours affichant les leçons dans des rectangles
     */
    void setUpLayout();

    /*!
     * \brief création du headerHorizontal
     *
     * le header affiche des dates. Le contenu est filtrer du jour sera filtré en fonction
     * de la date du header. Les dates du header sont mise à jour en fonction de la selection courante
     * dans le mini-calendrier
     */
    void createHorizontalHeader();

public slots:
    /*!
     * \brief Change la taille du heure en pixel
     *
     * La taille est connectée à la valeur du slider situé dans la toolbar de la vue calendrier.
     * Cela permet d'avoir un effet de zoom sur le calendrier
     *
     * \param height: nouvelle taille
     */
    void changeHeightHours(int height);

    /*!
     * \brief Met à jour les dates affichée dans le calendrier
     *
     * C'est la horizontalheader qui sera modifié afin de filter les leçons et tâches selon la date du jour.
     *
     * \param currrentDate: La date qui doit être afficher dans le calendrier
     * les autres date de la même semaine seront aussi affichée.
     */
    void updateCurrentWeek(QDate currrentDate);

    /*!
     * \brief filtre le model tâche et récupère la liste de tâche dont l'échance correspond
     * à une certaine date
     */
    void getTasksByDate(QDate);

    /*!
     * \brief deselection tout les rectangles des lessons, sauf 1
     * \param dayOfWeek : numéro du jour où le rectangle à garder en selection se situe
     */
    void deselectOthers(int dayOfWeek);

    /*!
     * \brief déselectionne touts les rectangles de lesson.
     */
    void deselectAll();

    /*!
     * \brief getTasksByLesson récpère les tâche d'une leçon précise
     * \param date: date de la leçon
     * \param courseName: nom du cours de la leçon
     */
    void getTasksByLesson(QDate date, QString courseName);

signals:
    /*!
     * \brief indique que la selection d'un élement du calendrier (leçon/jour) à été selectionné
     * et que la base de donnée à été filtrée.
     */
    void selectionUpdated();
};

#endif // CALENDARWIDGET_H
