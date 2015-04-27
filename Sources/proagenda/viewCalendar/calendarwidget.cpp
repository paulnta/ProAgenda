#include "calendarwidget.h"
#include "ui_calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}
