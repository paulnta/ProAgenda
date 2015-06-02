#ifndef VMODULEFILL_H
#define VMODULEFILL_H

#include <QSqlQuery>
#include <QSqlRecord>
#include <QWidget>

#include "summaryutils.h"

class VSummary;

namespace Ui {
class VModuleFill;
}


/*! \class VModuleFill
 * \brief Classe representant la zone de modification des
 *      données d'un module.
 *
 *  La classe affiche le module courant et permet la modification de
 *  celui-ci ou l'ajout d'un nouveau module.
 */
class VModuleFill : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VModuleFill
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le VModuleFill (vue résumé).
     *
     */
    explicit VModuleFill(QWidget *parent = 0, VSummary *vSummary = 0);

    /*!
     * \brief Destructeur de la classe VModuleFill
     */
    ~VModuleFill();

    /*!
     * \brief Rempli les champs de l'interface.
     *
     *  \param id : Identifiant du module
     *  \param name : Nom du module
     *  \param description : Description du module
     *  \param threshold : Seuil du module
     */
    void setFieldsValue(unsigned int id, QString name, QString description, float threshold);

    /*!
     * \brief Modifie l'état de la vue (ajout ou édition).
     *
     *  \param value : Est-ce qu'on est en modification (true) ou en ajout (false).
     */
    void setEditionMode(bool value);

private slots:
    // Actions lors du clique sur les boutons
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();

private:
    Ui::VModuleFill *ui;
    bool editionMode = false;
    unsigned int currentModuleId;
    VSummary *vSummary;
};

#endif // VMODULEFILL_H
