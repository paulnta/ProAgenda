#ifndef TESTTREEVIEW_H
#define TESTTREEVIEW_H

#include <QWidget>
#include <QTreeView>

class TestTreeView : public QWidget
{
    Q_OBJECT
public:
    explicit TestTreeView(QWidget *parent = 0);
    ~TestTreeView();

signals:

public slots:
    void update(QModelIndex, QModelIndex);
};

#endif // TESTTREEVIEW_H
