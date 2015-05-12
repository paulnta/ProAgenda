#ifndef TREEMODEL
#define TREEMODEL

#include <QSqlRelationalTableModel>
#include <QStandardItemModel>

class TreeModel : public QStandardItemModel
{
    Q_OBJECT

public:
    TreeModel(const QString &data, QObject *parent = 0);
    TreeModel( int rows, int columns, QObject * parent = 0 );
    ~TreeModel();
    QVariant data(const QModelIndex &index, int role) const;

private:

};


#endif // TREEMODEL

