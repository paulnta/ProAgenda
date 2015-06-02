#include "vsemesterfill.h"
#include "ui_vsemesterfill.h"

#include "vsummary.h"

VSemesterFill::VSemesterFill(QWidget *parent, VSummary *vSummary) :
    QWidget(parent),
    ui(new Ui::VSemesterFill)
{
    ui->setupUi(this);

    ui->btnDelete->setVisible(false);

    ui->dteStart->setDate(QDate::currentDate());
    ui->dteEnd->setDate(QDate::currentDate());

    this->vSummary = vSummary;
}

VSemesterFill::~VSemesterFill()
{
    delete ui;
}

void VSemesterFill::on_btnAdd_clicked() {
    // Contrôles de saisie
    if(ui->edtName->text() == "") {
        SummaryUtils::messageBoxOkCancel("Le nom du semestre est vide !");
        return;
    }
    if(ui->dteStart->date() > ui->dteEnd->date()) {
        SummaryUtils::messageBoxOkCancel("La date de début se trouve après la date de fin !");
        return;
    }

    // En mode édition
    if(editionMode) {
        QSqlQuery query;
        query.prepare("UPDATE Semester SET name = :name, startDate = :startDate, endDate = :endDate WHERE id = :id");
        query.bindValue(":id", currentSemesterId);
        query.bindValue(":name", ui->edtName->text());
        query.bindValue(":startDate", ui->dteStart->text());
        query.bindValue(":endDate", ui->dteEnd->text());
        query.exec();
    }
    // Sinon c'est un ajout
    else {
        // On crée le modèle qu'on affecte à la table Semester
        QSqlTableModel model;
        model.setEditStrategy(QSqlTableModel::OnManualSubmit);
        model.setTable("Semester");
        model.select();

        // On crée le record pour un ajout
        QSqlRecord record = model.record();
        record.setValue("name", ui->edtName->text());
        record.setValue("startDate", ui->dteStart->text());
        record.setValue("endDate", ui->dteEnd->text());

        // On ajoute et on valide
        model.insertRecord(-1, record);
        model.submitAll();
    }


    vSummary->refreshSideBar();
}

void VSemesterFill::setFieldsValue(int id, QString name, QDate startDate, QDate endDate) {
    ui->edtName->setText(name);
    ui->dteStart->setDate(startDate);
    ui->dteEnd->setDate(endDate);
    currentSemesterId = id;
}

void VSemesterFill::setEditionMode(bool value) {
    if(value == false) {
        ui->btnAdd->setText("Ajouter");
        ui->btnDelete->setVisible(false);
    }
    else {
        ui->btnAdd->setText("Modifier");
        ui->btnDelete->setVisible(true);
    }

    editionMode = value;
}


void VSemesterFill::on_btnDelete_clicked()
{
    int ret = SummaryUtils::messageBoxOkCancel("Etes-vous sûr de vouloir supprimer ce semestre (tous les cours s'y trouvant seront également supprimé) ?");

    if(ret == QMessageBox::Ok) {

        // On parcourt tous les cours liés au semestre choisi
        QSqlQuery query;
        query.exec("SELECT * FROM Course WHERE semesterId = " + QString::number(currentSemesterId));
        while(query.next()) {
            int courseId = query.value("id").toInt();

            // On supprime toutes les leçons liées au cours
            SummaryUtils::execQueryOnDatabase("DELETE FROM Lesson WHERE courseId = " + QString::number(courseId));
            // On supprime toutes les tâches liées au cours
            SummaryUtils::execQueryOnDatabase("DELETE FROM Task WHERE courseId = " + QString::number(courseId));
            // On supprime le cours
            SummaryUtils::execQueryOnDatabase("DELETE FROM Course WHERE id = " + QString::number(courseId));
        }

        // Enfin on supprime le semestre
        SummaryUtils::execQueryOnDatabase("DELETE FROM Semester WHERE id = " + QString::number(currentSemesterId));

        // On refresh
        vSummary->refreshSideBar();
        vSummary->emptyVSemesterFill();
    }
}
