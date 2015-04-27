#ifndef SIDEBARSUMMARY_H
#define SIDEBARSUMMARY_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class SideBarSummary;
}

class SideBarSummary : public QWidget
{
    Q_OBJECT

public:
    explicit SideBarSummary(QWidget *parent = 0);
    ~SideBarSummary();
    QVBoxLayout* getLayout();

private:
    Ui::SideBarSummary *ui;
};

#endif // SIDEBARSUMMARY_H
