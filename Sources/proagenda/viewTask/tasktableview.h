#ifndef TASKTABLEVIEW
#define TASKTABLEVIEW

#include <QDebug>
#include <QPainter>
#include <QWidget>
#include <QTableView>
#include <QHeaderView>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QMouseEvent>

class TaskTableView : public QTableView{

    Q_OBJECT

    typedef enum{ ID, NAME, DESCRIPTION, TERMDATE, NOTE, PRIORITY, FINISHED, COEFFICIENT, TYPEID, COURSEID} FIELD;

public:

    explicit TaskTableView(QWidget* parent = 0) : QTableView(parent){
        horizontalHeader()->close();
        verticalHeader()->close();

        setShowGrid(false);
        setSelectionBehavior(QAbstractItemView::SelectRows);
//        setItemDelegate(new RowDelegate(this));
        setItemDelegateForColumn(FIELD(FINISHED) , new RowDelegate(this));
//        setEditTriggers(QAbstractItemView::AllEditTriggers);


    }
    ~TaskTableView(){}

    class CheckBoxDelegate: public QStyledItemDelegate{

    public:
        static QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options) {
          QStyleOptionButton check_box_style_option;
          QRect check_box_rect = QApplication::style()->subElementRect(
              QStyle::SE_CheckBoxIndicator,
              &check_box_style_option);
          QPoint check_box_point(view_item_style_options.rect.x() +
                                 view_item_style_options.rect.width() / 2 -
                                 check_box_rect.width() / 2,
                                 view_item_style_options.rect.y() +
                                 view_item_style_options.rect.height() / 2 -
                                 check_box_rect.height() / 2);
          return QRect(check_box_point, check_box_rect.size());
        }


        CheckBoxDelegate(QObject *parent)
          : QStyledItemDelegate(parent) {
        }

        void paint(QPainter *painter,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const {
          bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

          QStyleOptionButton check_box_style_option;
          check_box_style_option.state |= QStyle::State_Enabled;
          if (checked) {
            check_box_style_option.state |= QStyle::State_On;
          } else {
            check_box_style_option.state |= QStyle::State_Off;
          }
          check_box_style_option.rect = CheckBoxRect(option);

          QApplication::style()->drawControl(QStyle::CE_CheckBox,
                                             &check_box_style_option,
                                             painter);
        }

        // This is essentially copied from QStyledItemEditor, except that we
        // have to determine our own "hot zone" for the mouse click.
        bool editorEvent(QEvent *event,
                                           QAbstractItemModel *model,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &index) {
          if ((event->type() == QEvent::MouseButtonRelease) ||
              (event->type() == QEvent::MouseButtonDblClick)) {
            QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
            if (mouse_event->button() != Qt::LeftButton ||
                !CheckBoxRect(option).contains(mouse_event->pos())) {
              return false;
            }
            if (event->type() == QEvent::MouseButtonDblClick) {
              return true;
            }
          } else if (event->type() == QEvent::KeyPress) {
            if (static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space &&
                static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select) {
              return false;
            }
          } else {
            return false;
          }

          bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
          return model->setData(index, !checked, Qt::EditRole);
        }


    };



    class RowDelegate : public QStyledItemDelegate{
        typedef QStyledItemDelegate SUPER;

    public:
        explicit RowDelegate(QObject* parent=0) : SUPER(parent){}


        // QAbstractItemDelegate interface
    public:
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
        {
            static_cast<QTableView*>(parent())->TaskTableView::setRowHeight(index.row(),50);
            SUPER::paint(painter,option,index);
        }

        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
        {
            if(index.column() == FIELD(FINISHED))
                return new QCheckBox(parent) ;

            return SUPER::createEditor(parent,option,index);
        }


        void setEditorData(QWidget *editor, const QModelIndex &index) const
        {


            if(index.column() == FIELD(FINISHED)){

                QCheckBox* cb = static_cast<QCheckBox*>(editor);
                if(cb != 0){
                    cb->setCheckable(true);
                    cb->setChecked(true);
                }
            }

            SUPER::setEditorData(editor, index);
        }

        // QAbstractItemDelegate interface
    public:
        bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
        {
            if(index.column() == FIELD(FINISHED) && event->type() == QEvent::MouseButtonPress){
                QMouseEvent* mevent = static_cast<QMouseEvent*>(event);


//                if(option.decorationPosition.rect.inintersects(
//                            QRect(mevent->globalPos().rx(),
//                                  mevent->globalPos().ry(),
//                                  mevent->globalPos().rx(),
//                                  mevent->globalPos().ry()))){

                    bool finished = index.data(Qt::DisplayRole).toBool();
                    qDebug() << finished;
                    return model->setData(index, !finished, Qt::EditRole);

            }

        }
    };


    // QAbstractItemView interface
protected slots:

};


#endif // TASKTABLEVIEW

