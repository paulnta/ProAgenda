#include "vlessonfill.h"
#include "ui_vlessonfill.h"

#include "vsummary.h"

VLessonFill::VLessonFill(QWidget *parent, int courseId, VSummary *vSummary) :
    QWidget(parent),
    ui(new Ui::vlessonfill) {

    ui->setupUi(this);

    // Rempli le combobox avec les jours de la semaine
    for(int i = 0; i < 7; i++){
        ui->cbxDay->addItem(QDate::longDayName(i + 1));
    }

    ui->groupBox->setTitle("Nouvelle leçon");
    ui->btnDelete->setVisible(false);

    currentCourseId = courseId;
    this->vSummary = vSummary;
}

VLessonFill::~VLessonFill() {
    delete ui;
}

void VLessonFill::setFieldsValue(int id, QString name, QString startHour, QString endHour, int dayOfWeek, int courseId) {
    currentLessonId = id;
    currentCourseId = courseId;
    ui->edtName->setText(name);
    ui->edtStartHour->setText(startHour);
    ui->edtEndHour->setText(endHour);
    ui->cbxDay->setCurrentIndex(dayOfWeek - 1);
    ui->groupBox->setTitle(name + " le " + QDate::longDayName(dayOfWeek) + " de " + startHour + " à " + endHour);
}

void VLessonFill::setEditionMode(bool value) {
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

void VLessonFill::on_btnAdd_clicked() {
    // Contrôles de saisie
    if(ui->edtName->text() == "" || ui->edtEndHour->text() == "" || ui->edtStartHour->text() == "") {
        SummaryUtils::messageBoxOkCancel("Un des champs est vide!");
        return;
    }
    QRegExp hourExp("([0-1]?[0-9]|[2]?[0-3]):[0-5][0-9]");
    if(!ui->edtStartHour->text().contains(hourExp)) {
        SummaryUtils::messageBoxOkCancel("L'heure de début n'est pas correcte! (format : xx:xx) ");
        return;
    }
    if(!ui->edtEndHour->text().contains(hourExp)) {
        SummaryUtils::messageBoxOkCancel("L'heure de fin n'est pas correcte! (format : xx:xx) ");
        return;
    }


    // En mode édition
    if(editionMode) {
        QSqlQuery query;
        query.prepare("UPDATE Lesson SET name = :name, startHour = :startHour, endHour = :endHour, dayOfWeek = :dayOfWeek, courseId = :courseId WHERE id = :id");
        query.bindValue(":id", currentLessonId);
        query.bindValue(":name", ui->edtName->text());
        query.bindValue(":startHour", ui->edtStartHour->text());
        query.bindValue(":endHour", ui->edtEndHour->text());
        query.bindValue(":dayOfWeek", ui->cbxDay->currentIndex() + 1);
        query.bindValue(":courseId", currentCourseId);
        query.exec();
    }
    // Sinon c'est un ajout
    else {

        // On crée le modèle qu'on affecte à la table Lesson
        QSqlTableModel model;
        model.setEditStrategy(QSqlTableModel::OnManualSubmit);
        model.setTable("Lesson");
        model.select();

        // On crée le record pour un ajout
        QSqlRecord record = model.record();
        record.setValue("name", ui->edtName->text());
        record.setValue("startHour", ui->edtStartHour->text());
        record.setValue("endHour", ui->edtEndHour->text());
        record.setValue("dayOfWeek", ui->cbxDay->currentIndex() + 1);
        record.setValue("courseId", currentCourseId);

        model.insertRecord(-1, record);
        model.submitAll();
    }

    vSummary->refreshLessons();
}

void VLessonFill::on_btnDelete_clicked() {
    int ret = SummaryUtils::messageBoxOkCancel("Etes-vous sûr de vouloir supprimer cette leçon ?");

    if(ret == QMessageBox::Ok) {
        // On supprime les leçons correspondantes à l'id
        SummaryUtils::execQueryOnDatabase("DELETE FROM Lesson WHERE id = " + QString::number(currentLessonId));

        vSummary->refreshLessons();
    }
}
