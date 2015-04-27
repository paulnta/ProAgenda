#ifndef VSUMMARY_H
#define VSUMMARY_H

#include <QWidget>

namespace Ui {
class VSummary;
}

class VSummary : public QWidget
{
    Q_OBJECT

public:
    explicit VSummary(QWidget *parent = 0);
    ~VSummary();

    void refreshSemestersList();

private:
    Ui::VSummary *ui;

private:
    void deleteAllWidgetsInSideBarLayout();
};

#endif // VSUMMARY_H
