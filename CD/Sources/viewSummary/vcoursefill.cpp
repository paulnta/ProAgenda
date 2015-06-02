#include "vcoursefill.h"
#include "ui_vcoursefill.h"

#include "vsummary.h"

VCourseFill::VCourseFill(QWidget *parent, VSummary *vSummary) :
    QWidget(parent),
    ui(new Ui::VCourseFill) {

    ui->setupUi(this);

    fillComboBox();

    ui->btnDelete->setVisible(false);
    this->vSummary = vSummary;
}

VCourseFill::~VCourseFill() {
    delete ui;
}

void VCourseFill::setFieldsValue(int id, QString name, QString description, float threshold, float weighting, QString color, int semesterId, int moduleId) {
    fillComboBox();

    ui->edtName->setText(name);
    ui->edtDescription->setText(description);
    ui->edtThreshold->setText(QString::number(threshold));
    ui->edtWeighting->setText(QString::number(weighting));
    setCbxSelectedItem(ui->cbxSemester, semesterId);

    // En fonction de l'id du module dans la DB, on sélectionne aucun
    if(moduleId == 0) {
        ui->cbxModule->setCurrentText("Aucun");
    }
    // Ou le module en question
    else {
        setCbxSelectedItem(ui->cbxModule, moduleId);
    }

    currentCourseId = id;
    currentColor = QColor(color);

    // On modifie la couleur du label pour qu'elle corresponde à celle de la DB
    ui->lblColor->setStyleSheet("border: 1px solid black; background-color: " + color);
}

void VCourseFill::setCbxSelectedItem(QComboBox *cbx, int dbId) {
    QModelIndex index;
    QAbstractItemModel *model = cbx->model();
    int ndx = 0;
    for (int i = 0; i < model->rowCount(); ++i)
    {
        index = cbx->model()->index(i, 0);
        if (model->data(index) == dbId)
        {
            ndx = i;
            break;
        }
    }
    cbx->setCurrentIndex(ndx);
}

int VCourseFill::getCbxSelectedItemDbIndex(QComboBox *cbx) {
    QAbstractItemModel *model = cbx->model();
    QModelIndex index = cbx->model()->index(cbx->currentIndex(), 0);
    return model->data(index).toInt();
}

void VCourseFill::setEditionMode(bool value) {
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

void VCourseFill::fillComboBox() {
    // Si le modèle existe, on le supprime
    if (semesterModel == 0)
        delete semesterModel;

    // On crée le modèle et on rempli le combobox en fonction de celui-ci
    semesterModel = new QSqlTableModel;
    semesterModel->setTable("Semester");
    semesterModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    semesterModel->select();
    ui->cbxSemester->clear();
    ui->cbxSemester->setModel(semesterModel);
    ui->cbxSemester->setModelColumn(semesterModel->fieldIndex("name"));


    // Si le modèle existe, on le supprime
    if (moduleModel == 0)
        delete moduleModel;

    // On crée le modèle et on rempli le combobox en fonction de celui-ci
    moduleModel = new QSqlTableModel;
    moduleModel->setTable("Module");
    moduleModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    moduleModel->select();
    ui->cbxModule->clear();
    ui->cbxModule->setModel(moduleModel);
    ui->cbxModule->setModelColumn(moduleModel->fieldIndex("name"));
    ui->cbxModule->addItem("Aucun");
    ui->cbxModule->setCurrentText("Aucun");
}

void VCourseFill::on_btnAdd_clicked() {

    // Contrôles de saisie
    if(ui->edtName->text() == "" || ui->edtDescription->text() == "" || ui->edtThreshold->text() == "" || ui->edtWeighting->text() == "") {
        SummaryUtils::messageBoxOkCancel("Un des champs est vide !");
        return;
    }
    QRegExp numberExp("([0-9].[0-9])|([0-9])");
    if(!ui->edtThreshold->text().contains(numberExp) || !ui->edtWeighting->text().contains(numberExp)) {
        SummaryUtils::messageBoxOkCancel("Le format du seuil ou du poids est incorrect !");
        return;
    }

    // Comme le module est facultatif, on regarde si l'utilisateur en a choisi 1, si ce n'est pas le cas on laisse
    // l'id 0 (aucun module) sinon on sélectionne le bon
    int moduleId = 0;
    if(ui->cbxModule->currentText() != "Aucun") {
        moduleId = getCbxSelectedItemDbIndex(ui->cbxModule);
    }

    // En mode édition
    if(editionMode) {
        QSqlQuery query;
        query.prepare("UPDATE Course SET name = :name, description = :description, threshold = :threshold, weighting = :weighting, moduleId = :moduleId, color = :color, semesterId = :semesterId WHERE id = :id");
        query.bindValue(":id", currentCourseId);
        query.bindValue(":name", ui->edtName->text());
        query.bindValue(":description", ui->edtDescription->text());
        query.bindValue(":threshold", ui->edtThreshold->text());
        query.bindValue(":weighting", ui->edtWeighting->text());
        query.bindValue(":color", currentColor.name());
        query.bindValue(":moduleId", moduleId);
        query.bindValue(":semesterId", getCbxSelectedItemDbIndex(ui->cbxSemester));
        query.exec();
    }
    // Sinon c'est un ajout
    else {

        // On crée le modèle qu'on affecte à la table Course
        QSqlTableModel model;
        model.setEditStrategy(QSqlTableModel::OnManualSubmit);
        model.setTable("Course");
        model.select();

        // On crée le record pour un ajout
        QSqlRecord record = model.record();
        record.setValue("name", ui->edtName->text());
        record.setValue("description", ui->edtDescription->text());
        record.setValue("threshold", ui->edtThreshold->text());
        record.setValue("weighting", ui->edtWeighting->text());
        record.setValue("color", currentColor.name());
        record.setValue("moduleId", moduleId);
        record.setValue("semesterId", getCbxSelectedItemDbIndex(ui->cbxSemester));

        // On ajoute et on valide
        model.insertRecord(-1, record);
        model.submitAll();
    }

    vSummary->refreshSideBar();
    vSummary->refreshModules();
}

void VCourseFill::on_btnDelete_clicked() {
    int ret = SummaryUtils::messageBoxOkCancel("Etes-vous sûr de vouloir supprimer ce cours (toutes les tâches et leçons liées à ce cours seront également supprimées) ?");

    if(ret == QMessageBox::Ok) {
        // On supprime toutes les leçons liées au cours
        SummaryUtils::execQueryOnDatabase("DELETE FROM Lesson WHERE courseId = " + QString::number(currentCourseId));
        // On supprime toutes les tâches liées au cours
        SummaryUtils::execQueryOnDatabase("DELETE FROM Task WHERE courseId = " + QString::number(currentCourseId));
        // On supprime le cours
        SummaryUtils::execQueryOnDatabase("DELETE FROM Course WHERE id = " + QString::number(currentCourseId));


        vSummary->refreshSideBar();
        vSummary->refreshModules();
    }
}

void VCourseFill::on_btnColor_clicked() {
    // On affiche un QColorDialog et on modifie la couleur en conséquence
    QColor color = QColorDialog::getColor();
    if(color.isValid()) {
        ui->lblColor->setStyleSheet("border: 1px solid black; background-color : " + color.name());
        currentColor = color;
    }
}
