#include "toolbarcalendar.h"

ToolBarCalendar::ToolBarCalendar(Ui::MainWindow *ui) : ui(ui)
{
    setIconSize(QSize(20,20));
    setLayoutDirection(Qt::RightToLeft);

    this->addWidget(new ToolButton("Example", ":/icons/img/icons/ic_today_48px.svg"));

}

ToolBarCalendar::~ToolBarCalendar()
{

}

