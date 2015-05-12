#ifndef TREEDELEGATE
#define TREEDELEGATE


#include <QDebug>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QPainter>

class TreeDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:

    typedef QStyledItemDelegate SUPER;
    TreeDelegate(QObject* parent=0) : SUPER(parent) {}

//    QWidget* createEditor(QWidget* parent,
//                          const QStyleOptionViewItem& option,
//                          const QModelIndex& index) const;


    void paint(QPainter* painter,
               const QStyleOptionViewItem& option,
               const QModelIndex& index) const{

        if(index.parent().isValid()){

            painter->setBrush(QBrush(QColor("#000000")));
            painter->drawRect(option.rect.left(),option.rect.top(),option.decorationSize.width(),option.decorationSize.height());
            painter->drawText(option.rect.left() + option.decorationSize.width() + 2, option.rect.top(),option.rect.width(), option.rect.height(),
                              Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

        } else {
            SUPER::paint(painter,option,index);
        }

    }


//    void setEditorData(QWidget* editor,
//                       const QModelIndex& index) const;

//    void setModelData(QWidget* editor,
//                      QAbstractItemModel* model,
//                      const QModelIndex& index) const;
};


#endif // TREEDELEGATE

