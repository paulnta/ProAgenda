#include "verticalheadercalendar.h"

VerticalHeaderCalendar::VerticalHeaderCalendar(QWidget* parent): CalendarColumn(parent)
{
    for(int j=0; j < CalendarColumn::nbHours ; j++){
        addRow(new QLabel(QString("%1:00").arg(j)), Qt::AlignTop);
    }
}

VerticalHeaderCalendar::~VerticalHeaderCalendar()
{

}

