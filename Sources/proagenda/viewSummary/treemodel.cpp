#include "treemodel.h"
#include <QDebug>

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QStandardItemModel(parent)
{
}

TreeModel::TreeModel(int rows, int columns, QObject *parent)
    : QStandardItemModel(rows,columns,parent)
{

}

TreeModel::~TreeModel()
{
}

/**
 * Determiner les valeurs et le type des donnée retournée par le model
 * permet d'ajouter par example une couleur, une checkbox, etc..
 */
QVariant TreeModel::data(const QModelIndex &index, int role) const
{

    if(role == Qt::DecorationRole && index.parent().isValid()){
        return QVariant(QColor("#b0d8fa"));
    }

    return QStandardItemModel::data(index,role);
}


