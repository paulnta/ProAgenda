#include "calendarwidget.h"
#include "mainwindow.h"

CalendarWidget::CalendarWidget(MainWindow *mainWindow) :
    QWidget(mainWindow),
    ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);
    main_ui = mainWindow;

    // Selectionner dans base de données
    model = Lesson::getInstance()->getModel();
    courseIndex = Lesson::getInstance()->getCourseIndex();
    relModel = model->relationModel(courseIndex);

    setUpLayout();

    connect(main_ui->getSideBarCalendar()->getMinicalendar(), SIGNAL(clicked(QDate)),
            this, SLOT(updateCurrentWeek(QDate)));

    connect(main_ui->getToolBarCalendar()->getSlider(), SIGNAL(valueChanged(int)),
            this, SLOT(changeHeightHours(int)));

    connect(this, SIGNAL(selectionUpdated()),
            main_ui->getSideBarCalendar()->getMiniTaskList(), SLOT(refreshTaskList()));
}

void CalendarWidget::setUpLayout()
{
    createHorizontalHeader();

    vHeader = new VerticalHeaderCalendar;
    ui->grid->addWidget(vHeader,0,0);

    for(int i = 0; i < 7; i++){
        ColumnDay* columnDay = new ColumnDay(model, weekDates.at(i));
        ui->grid->addWidget(columnDay,0,i+1,0);
        daysGrid.append(columnDay);

        connect(main_ui, SIGNAL(to_cal_triggered()), columnDay, SLOT(updateValues()));
        connect(columnDay, SIGNAL(lessonSelected(int)), this, SLOT(deselectOthers(int)));
        connect(columnDay, SIGNAL(lessonSelected(QDate,QString)), this, SLOT(getTasksByLesson(QDate,QString)));
        connect(columnDay, SIGNAL(columnDaySelected(int)), this, SLOT(deselectAll()));
    }

    ui->grid->setSpacing(0);
}

void CalendarWidget::createHorizontalHeader(){

     for(int i = 0; i < CalendarColumn::nbDay; i++){

         // Nom des jours dans l'entête
         if(i > 0){
             WeekDate* dayName = new WeekDate;
             weekDates.append(dayName);
             ui->gridDays->addWidget(dayName,1,i);
             connect(dayName, SIGNAL(daySelected(QDate)), this, SLOT(getTasksByDate(QDate)));

         } else {
             ui->gridDays->addWidget(new QLabel,1,i);
         }
     }

     updateCurrentWeek(QDate::currentDate());
}


void CalendarWidget::updateCurrentWeek(QDate currrentDate){

    int currentDayOfWeek = currrentDate.dayOfWeek();

    for(int i=0; i < weekDates.size(); i++){
        QDate date = QDate(currrentDate).addDays(-currentDayOfWeek+1+i);
        weekDates.at(i)->setDate(date);
    }
}


QScrollBar *CalendarWidget::getVerticalScrollbar()
{
    return this->ui->scrollArea->verticalScrollBar();
}

void CalendarWidget::changeHeightHours(int height)
{
    for (int i=0; i < daysGrid.size(); i++){
        daysGrid.at(i)->setRowsMinimumHeight(height);
    }
}

void CalendarWidget::getTasksByLesson(QDate date, QString courseName){

    Task::getInstance()->filterByLesson(date,courseName);
    emit selectionUpdated();
    main_ui->getSideBarCalendar()->showMiniTaskList();
}

void CalendarWidget::getTasksByDate(QDate date){

    Task::getInstance()->filterByDateRange(date,date);
    emit selectionUpdated();
    main_ui->getSideBarCalendar()->showMiniTaskList();
}

void CalendarWidget::deselectOthers(int dayOfWeek){

    for(int i=0; i < daysGrid.size(); i++){
        if(daysGrid.at(i)->getDayOfWeek() != dayOfWeek){
            daysGrid.at(i)->deselectLesson();
        }
    }
}

void CalendarWidget::deselectAll(){

    for(int i=0; i < daysGrid.size(); i++){
        daysGrid.at(i)->deselectLesson();
    }

    main_ui->getSideBarCalendar()->showMiniCalendar();
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}
