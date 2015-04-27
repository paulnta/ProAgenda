#include "vsemesterfill.h"
#include "ui_vsemesterfill.h"

#include "sqlconnection.h"

#include <QDebug>

VSemesterFill::VSemesterFill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VSemesterFill)
{
    ui->setupUi(this);
}

VSemesterFill::~VSemesterFill()
{
    delete ui;
}

void VSemesterFill::on_btnAdd_clicked()
{
    QString name = this->ui->edtName->text();
    QString startDate = this->ui->dteStart->text();
    QString endDate = this->ui->dteEnd->text();

    QString strQuery = "INSERT INTO Semester (name, startDate, endDate) VALUES (:name, :startDate, :endDate)";

    QSqlQuery query(SqlConnection::getDatabase());
    query.prepare(strQuery);
    query.bindValue(":name", name);
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    query.exec();

    vSummary->refreshSemestersList();

    ui->edtName->setText("");
    ui->edtName->setFocus();
}
