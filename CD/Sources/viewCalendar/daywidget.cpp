#include "daywidget.h"

DayWidget::DayWidget(QWidget *parent) : QWidget(parent)
{
    dayName = new QLabel;
    dayNumber = new QLabel;

    QVBoxLayout* currenDayLayout = new QVBoxLayout;
    currenDayLayout->addWidget(dayName,0,Qt::AlignCenter);
    currenDayLayout->addWidget(dayNumber,0,Qt::AlignCenter);
    setLayout(currenDayLayout);
    dayName->setStyleSheet("QLabel{font-size: 16px;}");
    dayNumber->setStyleSheet("QLabel{font-size: 50px}");
}

DayWidget::~DayWidget()
{
    delete dayName;
    delete dayNumber;
}

void DayWidget::setDayNumber(int noDay)
{
    dayNumber->setText(QString::number(noDay));
}

void DayWidget::setDayName(QString dayName)
{
    this->dayName->setText(dayName);
}

