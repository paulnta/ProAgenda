#ifndef TOOLBARCALENDAR_H
#define TOOLBARCALENDAR_H

#include <QObject>
#include <QToolBar>
#include <QLabel>
#include "utils/toolbutton.h"
#include "utils/spacer.h"
#include "models/task.h"
#include <QSlider>

namespace Ui {
class MainWindow;
}

/*!
 * \brief ToolBarCalendar est la barre d'outil de la vue Calendrier.
 * Elle affiche le slider permettant de zoomer sur la vue calendrier
 */
class ToolBarCalendar : public QToolBar
{
    Q_OBJECT // Macro Qt : Nécéssaire pour ajouter des Slot

    Ui::MainWindow *ui;
    QSlider* slider;

public:
    /*!
     * \brief Constructeur
     * \param ui : la MainWindow
     */
    explicit ToolBarCalendar(Ui::MainWindow *ui);
    ~ToolBarCalendar();

    /*!
     * \brief retourne le slider
     */
    QSlider *getSlider();
};

#endif // TOOLBARCALENDAR_H
