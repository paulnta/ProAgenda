#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include "calendarday.h"
#include "headerhours.h"
#include "hourcal.h"
#include "ui_calendarwidget.h"

#include <QRect>
#include <QScrollBar>
#include <models/lesson.h>
#include <QLabel>
#include <QSlider>
#include <QTouchEvent>

namespace Ui {
class CalendarWidget;
}

class CalendarWidget : public QWidget
{
    Q_OBJECT

    QList<QWidget*> daysCal;
    QList<QGridLayout*> daysGrid;

public:
    explicit CalendarWidget(QWidget *parent = 0);
    QScrollBar* getVerticalScrollbar(){ return this->ui->scrollArea->verticalScrollBar(); }

    ~CalendarWidget();


 public slots:
    void changeHeightHours(int height);

private:
    Ui::CalendarWidget *ui;

};

#endif // CALENDARWIDGET_H
