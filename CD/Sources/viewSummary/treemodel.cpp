#include "treemodel.h"

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QStandardItemModel(parent)
{
}

TreeModel::TreeModel(int rows, int columns, QObject *parent)
    : QStandardItemModel(rows,columns,parent)
{

}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    return QStandardItemModel::data(index,role);
}
