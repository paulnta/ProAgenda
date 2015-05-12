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

QVariant TreeModel::data(const QModelIndex &index, int role) const
{

    if(role == Qt::DecorationRole && index.parent().isValid()){
        return QVariant(QColor("#b0d8fa"));
    }

    return QStandardItemModel::data(index,role);
}


