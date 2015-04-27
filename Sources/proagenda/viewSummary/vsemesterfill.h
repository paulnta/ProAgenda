#ifndef VSEMESTERFILL_H
#define VSEMESTERFILL_H

#include <QWidget>

#include "vsummary.h"

namespace Ui {
class VSemesterFill;
}

class VSemesterFill : public QWidget
{
    Q_OBJECT

public:
    explicit VSemesterFill(QWidget *parent = 0);
    ~VSemesterFill();

    void setVSummary(VSummary* value) {
        vSummary = value;
    }

private slots:
    void on_btnAdd_clicked();

private:
    Ui::VSemesterFill *ui;
    VSummary *vSummary;
};

#endif // VSEMESTERFILL_H
