#include "headerhours.h"

int HeaderHours::nbHoursPerDay = 24;
int HeaderHours::nbHoursPerPage = 12;
int HeaderHours::beginHour = 0;

HeaderHours::HeaderHours(QWidget *parent) : QWidget(parent)
{

    QGridLayout* layout = new QGridLayout;

    for(int i = 0; i < HeaderHours::nbHoursPerDay; i++){
        QWidget* gridDay = new QWidget();
        gridDay->setMinimumHeight(50);
        QLabel* label = new QLabel(QString("%1").arg(i),gridDay);
        layout->addWidget(gridDay,i,0,1,1);
    }

    setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

}

HeaderHours::~HeaderHours()
{

}

