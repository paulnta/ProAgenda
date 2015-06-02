#include "vmodulefill.h"
#include "ui_vmodulefill.h"

#include "vsummary.h"

VModuleFill::VModuleFill(QWidget *parent, VSummary *vSummary) :
    QWidget(parent),
    ui(new Ui::VModuleFill) {
    ui->setupUi(this);

    ui->btnDelete->setVisible(false);
    this->vSummary = vSummary;
}

VModuleFill::~VModuleFill() {
    delete ui;
}

void VModuleFill::setEditionMode(bool value) {
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

void VModuleFill::setFieldsValue(unsigned int id, QString name, QString description, float threshold) {
    currentModuleId = id;
    ui->edtName->setText(name);
    ui->edtDescription->setText(description);
    ui->edtThreshold->setText(QString::number(threshold));
    ui->groupBox->setTitle(name);

    // On calcule la moyenne du module
    int totalWeighting = 0;
    float totalAverage = 0.f;
    QSqlQuery courseQuery;
    courseQuery.exec("SELECT * FROM Course WHERE moduleId = " + QString::number(id));
    while(courseQuery.next()) {
        QList<Average> averages = SummaryUtils::getAllAveragesInCourse(courseQuery.value("id").toInt());

        // On calcule le poids total
        totalWeighting += courseQuery.value("weighting").toInt();
        // On augmente la moyenne en fonction du poids du cours
        totalAverage += averages.at(averages.length() - 1).value * courseQuery.value("weighting").toInt();
    }

    if(totalWeighting > 0.f) {
        // On calcule la moyenne finale
        float moduleAverage = totalAverage / (float)totalWeighting;

        // On arrondi
        moduleAverage = floor((moduleAverage + 0.05f) * 10.f) / 10.f;


        // On modifie le label et sa couleur en fonction de la note obtenue
        ui->lblAverage->setStyleSheet("color: green");
        ui->lblAverage->setText("Moyenne : " + QString::number(moduleAverage, 'f', 1));

        if(moduleAverage < 4.f) {
            ui->lblAverage->setStyleSheet("color: orange");
        }
        if(moduleAverage < ui->edtThreshold->text().toFloat()) {
            ui->lblAverage->setStyleSheet("color: red");
        }
    }
}

void VModuleFill::on_btnAdd_clicked() {
    // Contrôles de saisie
    if(ui->edtName->text() == "" || ui->edtDescription->text() == "" || ui->edtThreshold->text() == "") {
        SummaryUtils::messageBoxOkCancel("Les valeurs entrées sont incorrectes, un champs est vide !");
        return;
    }
    QRegExp thresholdExp("([0-9].[0-9])|([0-9])");
    if(!ui->edtThreshold->text().contains(thresholdExp)) {
        SummaryUtils::messageBoxOkCancel("Le seuil entré est incorrect !");
        return;
    }


    // En mode édition
    if(editionMode) {
        QSqlQuery query;
        query.prepare("UPDATE Module SET name = :name, description = :description, threshold = :threshold WHERE id = :id");
        query.bindValue(":id", currentModuleId);
        query.bindValue(":name", ui->edtName->text());
        query.bindValue(":description", ui->edtDescription->text());
        query.bindValue(":threshold", ui->edtThreshold->text());
        query.exec();
    }
    // Sinon c'est un ajout
    else {
        // On crée le modèle qu'on affecte à la table Module
        QSqlTableModel model;
        model.setEditStrategy(QSqlTableModel::OnManualSubmit);
        model.setTable("Module");
        model.select();

        // On crée le record pour un ajout
        QSqlRecord record = model.record();
        record.setValue("name", ui->edtName->text());
        record.setValue("description", ui->edtDescription->text());
        record.setValue("threshold", ui->edtThreshold->text());

        // On ajoute et on valide
        model.insertRecord(-1, record);
        model.submitAll();
    }

    vSummary->refreshModules();
}

void VModuleFill::on_btnDelete_clicked() {
    int ret = SummaryUtils::messageBoxOkCancel("Etes-vous sûr de vouloir supprimer cet module ?");

    if(ret == QMessageBox::Ok) {
        // On modifie les cours pour qu'il ne dépende plus du module supprimé
        QSqlQuery query;
        query.prepare("UPDATE Course SET moduleId = 0 WHERE moduleId = :id");
        query.bindValue(":id", currentModuleId);
        query.exec();

        // On supprime le module
        SummaryUtils::execQueryOnDatabase("DELETE FROM Module WHERE id = " + QString::number(currentModuleId));

        vSummary->refreshModules();
    }
}
