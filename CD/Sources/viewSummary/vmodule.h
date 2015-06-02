#ifndef VMODULE_H
#define VMODULE_H

#include <QLayout>
#include <QScrollArea>
#include <QWidget>

#include "vmodulefill.h"

class VSummary;

namespace Ui {
class VModule;
}

/*! \class VModule
 * \brief Classe représentant l'affichage des différents modules.
 *
 *  La classe affiche la liste des modules (dans des VModuleFill).
 */
class VModule : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VModule
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le VModule (vue résumé).
     *
     */
    explicit VModule(QWidget *parent = 0, VSummary* vSummary = 0);

    /*!
     * \brief Destructeur de la classe VModule
     */
    ~VModule();

private:
    Ui::VModule *ui;
};

#endif // VMODULE_H
