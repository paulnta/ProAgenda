#ifndef TREEMODEL
#define TREEMODEL

#include <QStandardItemModel>

/*! \class TreeModel
 * \brief Classe héritée de QStandardItemModel et qui correspond au model pour le TreeView
 *
 * Correspond au model pour un TreeView.
 */
class TreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe TreeModel
     *
     * \param data : La valeur à affecter.
     * \param parent : Le parent du TreeModel
     *
     */
    TreeModel(const QString &data, QObject *parent = 0);

    /*!
     * \brief Constructeur de la classe TreeModel
     *
     * \param rows : Le nombre de lignes.
     * \param columns : Le nombre de colonnes
     * \param parent : Le parent du TreeModel
     *
     */
    TreeModel( int rows, int columns, QObject * parent = 0);

    /*!
     * \brief Retourne la donnée (stockée dans le modèle) à l'index "index" en fonction du rôle.
     *
     * \param rows : Le nombre de lignes.
     * \param columns : Le nombre de colonnes
     * \param parent : Le parent du TreeModel
     *
     */
    QVariant data(const QModelIndex &index, int role) const;

    /*!
     * \brief Retourne la liste des  indices persistants
     *
     * La méthode persistentIndexList() dans QStandardItemModel est
     * privée, il fallait la rendre accessible de l'exterieur.
     *
     * \return La liste des indices persistants.
     *
     */
    QModelIndexList getPersistentIndexList() {
        return this->persistentIndexList();
    }

private:

};


#endif // TREEMODEL

