#include "testcalendar.h"
#include "ui_testcalendar.h"


TestCalendar::TestCalendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestCalendar)
{
    ui->setupUi(this);
    DrawSimpleCal();

}

void TestCalendar::DrawSimpleCal(){


}

TestCalendar::~TestCalendar()
{
    delete ui;
}
