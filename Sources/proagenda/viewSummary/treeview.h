#ifndef TREEVIEW
#define TREEVIEW

#include <QTreeView>
#include <QDebug>

class TreeView : public QTreeView{

    Q_OBJECT

public:

    explicit TreeView(QWidget* parent = 0) :QTreeView(parent){}
    ~TreeView(){}

signals:


protected slots:

    /**
     * Lors d'une modification des donnée
     * Resultat: mettre à jour le model
     * @brief dataChanged
     * @param topLeft
     * @param bottomRight
     * @param roles
     */
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
    {

        if(!topLeft.parent().isValid()){
            qDebug() << "SEMESTRE" << topLeft.row() << " UPDATED to" << topLeft.data().toString();
        } else {
            qDebug() << "COUSE" << topLeft.row() << " UPDATED to" << topLeft.data().toString();
        }

    }

    /**
     * Lors  de la selection d'un element
     * Résultat: mettre a jour la vue principale
     * @brief currentChanged
     * @param current
     * @param previous
     */
    void currentChanged(const QModelIndex &current, const QModelIndex &previous)
    {
        // SEMESTRE
        if(!current.parent().isValid()){
            qDebug() << "SEMESTRE: "<< current.row() << current.data().toString();
        } else {
            qDebug() << "COURSE: " << current.row() << current.data().toString();
        }
    }


};

#endif // TREEVIEW

