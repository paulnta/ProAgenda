#ifndef CALENDARCOLUMN_H
#define CALENDARCOLUMN_H

#include <QWidget>
#include <QGridLayout>
#include "hourcal.h"


/*!
 * \brief Colonne de la grille du calendrier
 *
 * Une colonne de la grille du calendrier peut contenir autant de widgets
 * que de nombre d'heures dans une journée. Ces widgets sont ajoutés dans
 * les lignes de chaque colonne.
 *
 * Cette classe est utile si on l'hérite afin de créer un verticalHeader,
 * ou pour créer la colonne d'un jour.
 */
class CalendarColumn : public QWidget
{
    Q_OBJECT

    int nbRow;
    QGridLayout* layout;

public:
    static int heightHour;
    static int nbDay;
    static int nbHours;

    /*!
     * \brief Constructeur
     * \param parent: Widget parent
     */
    explicit CalendarColumn(QWidget* parent = 0);

    /*!
     * \brief Ajout d'une ligne
     * \param widget: le widget de la ligne
     * \param alignment: Aligment du widget dans la ligne
     */
    void addRow(QWidget *widget,Qt::Alignment alignment = 0);

    /*!
     * \brief numéro du jour de la semaine de la columne
     * \return -1 si la columne ne représente pas un jour de la semaine
     */
    virtual int getDayOfWeek();
    ~CalendarColumn();

public slots:

    /**
     * @brief taille minimum des lignes
     * @param height: nouvelle taille
     */
    void setRowsMinimumHeight(int height);
};

#endif // CALENDARCOLUMN_H
