#include "calendarwidget.h"


CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);

    QLabel* month = new QLabel("mars 2015");
    QFont titles;
    titles.setPixelSize(20);
    month->setFont(titles);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(30,100);
    slider->setValue(50);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(changeHeightHours(int)));
//      connect(slider, SIGNAL(valueChanged(int)), ui->scrollArea->verticalScrollBar(), SLOT(setValue(int)));

    ui->header->addWidget(month);
    ui->header->addStretch(1);
    ui->header->addWidget(slider);

    QList<QLabel*> days;
    days << new QLabel("") << new QLabel("lundi") << new QLabel("mardi") << new QLabel("mercredi")
         << new QLabel("jeudi") << new QLabel("vendredi") << new QLabel("Samedi") << new QLabel("dimanche");

    QList<Lesson> empty;
    QList<Lesson> lun;
    QList<Lesson> mar;
    QList<Lesson> mer;
    QList<Lesson> jeu;
    QList<Lesson> ven;
    QList<Lesson> sam;
    QList<Lesson> dim;

    lun << Lesson("SLO",QTime(8,30), QTime(10,0), 1)  << Lesson("PCO",QTime(10,30), QTime(12,0), 1) << Lesson("SLO",QTime(13,0), QTime(14,0), 1);
    mar << Lesson("GEN",QTime(9,15), QTime(12,0), 2)  << Lesson("SIO",QTime(13,0),QTime(14,35), 2)  << Lesson("PRO",QTime(15,0), QTime(17,0), 2);
    mer << Lesson("RES",QTime(8,0), QTime(10,0), 2)  << Lesson("SIO",QTime(13,0),QTime(15,0), 2)  << Lesson("GEN",QTime(15,0), QTime(17,0) ,3);
    jeu << Lesson("MCR",QTime(9,0),QTime(12,0), 2)   << Lesson("POO",QTime(13,0), QTime(15,0),4)     << Lesson("SER",QTime(15,0), QTime(17,0),4);
    ven << Lesson("PCO",QTime(8,0),QTime(10,0), 2) << Lesson("POO",QTime(10,0),QTime(12,0), 2);

    QList< QList<Lesson>* > lessons;
    lessons.append(&empty);
    lessons.append(&lun);
    lessons.append(&mar);
    lessons.append(&mer);
    lessons.append(&jeu);
    lessons.append(&ven);
    lessons.append(&sam);
    lessons.append(&dim);



    for(int i = 0; i < CalendarDay::nbDay; i++){

        // Header days
        ui->gridDays->addWidget(days.at(i),1,i+1,1,1,0);

        // grid day
        QGridLayout* day = new QGridLayout;
        daysGrid.append(day);

        day->setMargin(0);
        day->setSpacing(0);

        // Column day
        CalendarDay* columnDay = new CalendarDay(i);
        columnDay->setLayout(day);
        columnDay->setLessons(*lessons.at(i));

        for(int j=0; j < CalendarDay::nbHours; j++){

            day->setRowMinimumHeight(j,CalendarDay::heightHour);

            if(i!=0)
                day->addWidget(new HourCal,j,0,0);
            else
                day->addWidget(new QLabel(QString("%1:00").arg(j)),j,0,Qt::AlignTop);
        }

        ui->grid->addWidget(columnDay,0,i,0);
    }

    ui->grid->setSpacing(0);

}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}


void CalendarWidget::changeHeightHours(int height)
{

    CalendarDay::heightHour = height;

    for (int i=0; i < CalendarDay::nbDay; i++){
        for(int j=0; j < CalendarDay::nbHours; j++){
            daysGrid.at(i)->setRowMinimumHeight(j, CalendarDay::heightHour);
            ui->scrollArea->verticalScrollBar()->setValue(CalendarDay::heightHour*6);
        }
    }
}

