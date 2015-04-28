#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include "calendarday.h"
#include "headerhours.h"
#include "hourcal.h"
namespace Ui {
class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT

    QList<QWidget*> daysCal;

public:
    explicit CalendarWidget(QWidget *parent = 0);
    ~CalendarWidget();

private:
    Ui::CalendarWidget *ui;
};

#endif // CALENDARWIDGET_H
