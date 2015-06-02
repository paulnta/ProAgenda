#include "sidebarcalendar.h"
#include <QDebug>
SideBarCalendar::SideBarCalendar(QWidget *parent) : QWidget(parent)
{
    stackedWidget = new QStackedWidget(this);
    viewMiniCalendar = new QWidget;
    viewMiniTaskList = new QWidget;

    stackedWidget->addWidget(viewMiniCalendar);
    stackedWidget->addWidget(viewMiniTaskList);

    stackedWidget->setCurrentIndex(0);

    setUpViewMiniCalendar();
    setUpViewMiniTaskList();
}

void SideBarCalendar::setUpViewMiniCalendar(){

    miniCal = new CustomCalendarWidget;
    QToolButton* next = new QToolButton;
    QToolButton* prev = new QToolButton;
    QPushButton* today = new QPushButton("Aujourd'hui");
    year = new QLabel(QString::number(miniCal->selectedDate().year()));
    month = new QLabel(QDate::longMonthName(miniCal->selectedDate().month()));

    QString styleToolButton = "QToolButton {background-color: rgba(0,0,0,0)}";
    QSize sizeToolButton(24,24);
    next->setIcon(QIcon(":/icons/img/icons/ic_chevron_right_48px.svg"));
    next->setStyleSheet(styleToolButton);
    next->setIconSize(sizeToolButton);
    next->setCursor(Qt::PointingHandCursor);

    prev->setIcon(QIcon(":/icons/img/icons/ic_chevron_left_48px.svg"));
    prev->setStyleSheet(styleToolButton);
    prev->setIconSize(sizeToolButton);
    prev->setCursor(Qt::PointingHandCursor);

    /* Infos jour sélectionné
     * Contient : No du jour et nom du jour de la semaine
     */
    currentDayCal = new DayWidget;
    currentDayCal->setDayName(QDate::longDayName(miniCal->selectedDate().dayOfWeek()));
    currentDayCal->setDayNumber(miniCal->selectedDate().day());

    /* Header
     * Contient: Bouton next, prev, mois et année
     */
    QWidget* header = new QWidget;
    header->setStyleSheet("QLabel{font-size: 16px;}");
    QHBoxLayout* headerLayout = new QHBoxLayout;
    headerLayout->addWidget(prev);
    headerLayout->addStretch(1);
    headerLayout->addWidget(month);
    headerLayout->addWidget(year);
    headerLayout->addStretch(1);
    headerLayout->addWidget(next);
    header->setLayout(headerLayout);

    /*
     * Layout principale
     * Contient: Header et Calendar
     */
    layoutMiniCalendar = new QVBoxLayout;

    layoutMiniCalendar->addWidget(currentDayCal);
    layoutMiniCalendar->addWidget(header);
    layoutMiniCalendar->addWidget(today, 0, Qt::AlignCenter);
    layoutMiniCalendar->addWidget(miniCal, 0, Qt::AlignHCenter);
    layoutMiniCalendar->addStretch(1);
    miniCal->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    miniCal->setFixedHeight(280);
    miniCal->setFixedWidth(280);

    connect(prev, SIGNAL(clicked()), miniCal, SLOT(showPreviousMonth()));
    connect(next, SIGNAL(clicked()), miniCal, SLOT(showNextMonth()));
    connect(miniCal, SIGNAL(currentPageChanged(int,int)), this, SLOT(pageChanged(int,int)));
    connect(miniCal, SIGNAL(selectionChanged()), this, SLOT(onDayClicked()));
    connect(today, SIGNAL(clicked()), this, SLOT(onTodayClicked()));

    viewMiniCalendar->setLayout(layoutMiniCalendar);
}

void SideBarCalendar::setUpViewMiniTaskList(){




    currentDayList = new DayWidget;
    currentDayList->setDayName(QDate::longDayName(miniCal->selectedDate().dayOfWeek()));
    currentDayList->setDayNumber(miniCal->selectedDate().day());
    miniTaskList = new MiniTaskList;
    layoutList = new QVBoxLayout;

    returnBtn = new QToolButton;
    returnBtn->setIcon(QIcon(":/icons/img/icons/ic_chevron_left_48px.svg"));
    returnBtn->setText("Calendrier");
    returnBtn->setCursor(Qt::PointingHandCursor);
    returnBtn->setStyleSheet("border: none");
    returnBtn->setIconSize(QSize(30,30));

    layoutList->addWidget(returnBtn,0,Qt::AlignLeft);
    layoutList->addWidget(currentDayList);
    layoutList->addWidget(miniTaskList);
    layoutList->addStretch(1);

    viewMiniTaskList->setLayout(layoutList);
    connect(returnBtn, SIGNAL(clicked()), this, SLOT(showMiniCalendar()));
}

SideBarCalendar::~SideBarCalendar()
{
    delete layoutMiniCalendar;
    delete miniCal;
    delete month;
    delete year;
}

CustomCalendarWidget *SideBarCalendar::getMinicalendar()
{
    return miniCal;
}

MiniTaskList *SideBarCalendar::getMiniTaskList()
{
    return miniTaskList;
}

void SideBarCalendar::showMiniTaskList()
{
    stackedWidget->setCurrentWidget(viewMiniTaskList);
}

void SideBarCalendar::showMiniCalendar()
{
    stackedWidget->setCurrentWidget(viewMiniCalendar);
}

void SideBarCalendar::pageChanged(int year, int month)
{
    this->month->setText(QDate::longMonthName(month));
    this->year->setText(QString::number(year));
}

void SideBarCalendar::onDayClicked(){

    currentDayList->setDayName(QDate::longDayName(miniCal->selectedDate().dayOfWeek()));
    currentDayList->setDayNumber(miniCal->selectedDate().day());

    currentDayCal->setDayName(QDate::longDayName(miniCal->selectedDate().dayOfWeek()));
    currentDayCal->setDayNumber(miniCal->selectedDate().day());
}

void SideBarCalendar::onTodayClicked()
{
    miniCal->setSelectedDate(QDate::currentDate());
}





