#include "vsummary.h"
#include "ui_vsummary.h"

#include <QtSql/QtSql>
#include "vsemesterfill.h"
#include "sqlconnection.h"

#include "mainwindow.h"

VSummary::VSummary(MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VSummary),
    mainWindow(mainWindow)
{
    ui->setupUi(this);

    VSemesterFill* vSemesterFill = new VSemesterFill;
    vSemesterFill->setVSummary(this);
    ui->layoutFill->addWidget(vSemesterFill);

    refreshSemestersList();
}

VSummary::~VSummary()
{
    delete ui;
}

void VSummary::refreshSemestersList() {
    QStringList semesters;
    QSqlQuery query(SqlConnection::getDatabase());
    query.exec("SELECT * FROM Semester");

    while(query.next()) {
        semesters << query.value(1).toString();
    }

    QStringListModel* modelList = new QStringListModel(semesters);
    QListView* list = new QListView;
    list->setModel(modelList);

    deleteAllWidgetsInSideBarLayout();

    mainWindow->getSideBarSummary()->getLayout()->addWidget(list);
}

void VSummary::deleteAllWidgetsInSideBarLayout() {

    QLayoutItem* item;
    while ( ( item = mainWindow->getSideBarSummary()->getLayout()->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}
