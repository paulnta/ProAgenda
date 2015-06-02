#include "calendarcolumn.h"


int CalendarColumn::heightHour = 50;
int CalendarColumn::nbDay = 8;
int CalendarColumn::nbHours = 24;

CalendarColumn::CalendarColumn(QWidget* parent) : QWidget(parent)
{
    layout = new QGridLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);
    nbRow = 0;
}

void CalendarColumn::addRow(QWidget *widget, Qt::Alignment alignment)
{
    layout->addWidget(widget,nbRow, alignment);
    layout->setRowMinimumHeight(nbRow,CalendarColumn::heightHour);
    nbRow++;
}

int CalendarColumn::getDayOfWeek()
{
    return -1;
}

void CalendarColumn::setRowsMinimumHeight(int height)
{
    for(int row = 0; row < nbRow; row++){
        layout->setRowMinimumHeight(row, height);
    }

    CalendarColumn::heightHour = height;
}

CalendarColumn::~CalendarColumn()
{
    delete layout;
}

