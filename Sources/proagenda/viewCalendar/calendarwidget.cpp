#include "calendarwidget.h"
#include "ui_calendarwidget.h"


CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);
    QList<QLabel*> days;
    days << new QLabel("lundi") << new QLabel("mardi") << new QLabel("mercredi")
         << new QLabel("jeudi") << new QLabel("vendredi") << new QLabel("Samedi") << new QLabel("dimanche");


    for(int i=0; i < days.size(); i++){
        ui->grid->addWidget(days.at(i),0,i,1,1,Qt::AlignTop);
    }

}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}
