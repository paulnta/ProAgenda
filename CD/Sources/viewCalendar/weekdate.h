#ifndef WEEKDATE_H
#define WEEKDATE_H

#include <QLabel>
#include <QDate>
#include <QMouseEvent>


/*!
 * \brief WeekDate un mélange de QLabel et de QDate
 *
 * Il peut s'afficher en tant que QLabel dans l'entete du
 * Calendrier et peut être vue en tant que QDate afin que la colonne
 * du calendrier correspondante sache quelle date doit être affichée.
 */
class WeekDate : public QLabel, public QDate
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur
     * \param parent : Widget parent
     */
    WeekDate(QWidget* parent = 0);
    ~WeekDate();

    /*!
     * \brief setDate: modification de la date
     */
    void setDate(QDate date);

signals:
    /*!
     * \brief signal que le widget à été selectionné par un clic
     */
    void daySelected(QDate);

protected:
    /*!
     * \brief redéfini afin de capturer les événements de clic de souris
     * sur ce widget
     */
    void mousePressEvent(QMouseEvent *);
};

#endif // WEEKDATE_H
