#ifndef SIDEBARCALENDAR_H
#define SIDEBARCALENDAR_H

#include <QWidget>
#include "customcalendarwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QToolButton>

#include "daywidget.h"
#include "viewCalendar/minitasklist.h"


/*!
 * \brief Sidebar de la vue Calendrier.
 *
 * La Sidebar fourni un miniCalendrier et peut switcher
 * sur une liste de tâches si l'utilisateur selectionner un jour
 * dans l'entête du calendrier
 *
 * Le miniCalendrier sert à naviguer entre les semaines affichées dans le calendrier.
 */
class SideBarCalendar : public QWidget
{
    Q_OBJECT

private:

    QWidget* viewMiniCalendar;
    QWidget* viewMiniTaskList;
    MiniTaskList* miniTaskList;
    QStackedWidget* stackedWidget;
    QVBoxLayout* layoutMiniCalendar;
    QVBoxLayout* layoutList;
    CustomCalendarWidget* miniCal;
    QLabel* month;
    QLabel* year;
    QToolButton* returnBtn;
    DayWidget* currentDayList;
    DayWidget* currentDayCal;

    /*!
     * \brief Initialisation du layout de la vue MiniCalendrier
     */
    void setUpViewMiniCalendar();

    /*!
     * \brief Initialisation du layout de la vue "liste des tâches"
     */
    void setUpViewMiniTaskList();
public:
    /**
     * @brief Constructeur
     * @param parent
     */
    explicit SideBarCalendar(QWidget *parent = 0);
    ~SideBarCalendar();

    /*!
     * \brief Récupération du Widget MiniCalendar
     */
    CustomCalendarWidget* getMinicalendar();

    /*!
     * \brief Récupération du widget MiniTaskList
     * \return
     */
    MiniTaskList* getMiniTaskList();

public slots:
    /*!
     * \brief Mise à jour des informations de la sidebar suite à
     * un changement de mois depuis le miniCalendrier
     */
    void pageChanged(int, int);

    /*!
     * \brief Aller à la date du jour.
     */
    void onTodayClicked();

    /*!
     * \brief Lors d'un clique sur un jour, on met à jour les informations
     * du numéro de jour et du nom de jour en cours.
     */
    void onDayClicked();

    /*!
     * \brief Affichage du miniCalendrier
     * La Sidebar contient une pile de widget. Elle switch sur le wigdet voulue.
     */
    void showMiniTaskList();

    /*!
     * \brief showMiniCalendar
     * La Sidebar contient une pile de widget. Elle switch sur le wigdet voulue.
     */
    void showMiniCalendar();
};

#endif // SIDEBARCALENDAR_H
