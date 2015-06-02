#ifndef HOURCAL
#define HOURCAL

#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

/*!
 * \brief HourCal rempli chaque ligne de d'une colonne.
 * Les lignes représente des heure.
 *
 * Cette classe est utilitaire.
 * Plusieurs instance de cette classe sont crée afin d'afficher
 * une ligne de séparation au niveau des heures du calendrier.
 */
class HourCal : public QWidget{

    Q_OBJECT

public:

    explicit HourCal(QWidget* parent = 0) : QWidget(parent){
    }

    ~HourCal(){

    }

    /*!
     * \brief paintEvent redéfini afin de pouvoir dessiner une ligne
     * en dessous de chaque ligne
     * \param event type de l'évenement
     */
    void paintEvent(QPaintEvent *event)
    {
        event->accept();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(QColor(230,230, 230, 255));
        painter.drawLine(0,0, width(),0);
    }

};

#endif // HOURCAL

