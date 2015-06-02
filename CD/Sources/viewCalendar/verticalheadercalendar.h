#ifndef VERTICALHEADERCALENDAR_H
#define VERTICALHEADERCALENDAR_H

#include "calendarcolumn.h"

/*!
 * \brief HeaderVertical du Calendrier
 *
 * Affiche la première colonne de la grille du calendrier contenant
 * une heure dans chaque ligne
 */
class VerticalHeaderCalendar : public CalendarColumn
{
public:
    /*!
     * \brief Constructeur
     * \param parent: widget parent
     */
    explicit VerticalHeaderCalendar(QWidget* parent = 0);
    ~VerticalHeaderCalendar();
};

#endif // VERTICALHEADERCALENDAR_H
