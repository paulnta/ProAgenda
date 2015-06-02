#ifndef TREENODE
#define TREENODE
#include <QStandardItem>

class TreeNode : public QStandardItem {

private:
    int row;
public:
    TreeNode(QString text, int row):QStandardItem(text),row(row){

    }



    // QStandardItem interface
public:
    QVariant data(int role) const{
        if(Qt::WhatsThisRole == role){
            return QVariant(row);
        }
        return QStandardItem::data(role);
    }
};

#endif // TREENODE

