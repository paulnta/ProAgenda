#include "toolbarcalendar.h"


ToolBarCalendar::ToolBarCalendar(Ui::MainWindow *ui) : ui(ui)
{
    setIconSize(QSize(20,20));

    this->addWidget(new Spacer());
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(30,100);
    slider->setValue(50);
    slider->setFixedWidth(200);
    this->addWidget(slider);
    this->addWidget(new Spacer());

}

QSlider* ToolBarCalendar::getSlider(){
    return slider;
}

ToolBarCalendar::~ToolBarCalendar()
{

}

