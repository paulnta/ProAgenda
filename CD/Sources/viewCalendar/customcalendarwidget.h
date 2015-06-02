#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QCalendarWidget>
#include <QPainter>
#include <QPoint>

/*!
 * \brief  MiniCalendar modifié pour une amélioration du design
 * La navigation entre les dates est géré manuellement pour
 * plus de fonctionnalités.
 */
class CustomCalendarWidget : public QCalendarWidget
{
public:
    CustomCalendarWidget();
    ~CustomCalendarWidget();

protected:

    /*!
     * \brief Méthode de QCalendarWidget reféfinie afin de gérer le dessin des cellules
     * du calendrier.
     *
     * \param painter: Painter permettant de dessiner des formes
     * \param rect: zone dans laquelle il est possible de dessiner (largeur et hauter d'une cellule)
     * \param date: date de la cellule
     */
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    /*!
     * \brief Initialisation des feuilles de styles
     */
    void initStyleSheet();
};

#endif // CUSTOMCALENDARWIDGET_H
