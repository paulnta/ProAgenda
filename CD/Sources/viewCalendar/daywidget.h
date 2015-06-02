#ifndef DAYWIDGET_H
#define DAYWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

/*!
 * \brief Classe utilitaire permettant d'afficher le nom d'un jour
 * ainsi sa date. Le numéro du jour est affiché en grand en dessous
 * du nom du jour.
 */
class DayWidget : public QWidget
{
    Q_OBJECT

    QLabel *dayNumber;
    QLabel *dayName;

public:
    /*!
     * \brief Constructeur
     * \param widget parent
     */
    explicit DayWidget(QWidget *parent = 0);
    ~DayWidget();

    /*!
     * \brief Modifier la numéro du jour
     * \param noDay: numéro du jour
     */
    void setDayNumber(int noDay);

    /*!
     * \brief Modification du nom du jour de la semaine
     * \param dayName: nom du jour
     */
    void setDayName(QString dayName);

};

#endif // DAYWIDGET_H
