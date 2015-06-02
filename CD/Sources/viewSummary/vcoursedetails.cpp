#include "vcoursedetails.h"
#include "ui_vcoursedetails.h"

#include "vsummary.h"

VCourseDetails::VCourseDetails(QWidget *parent, VSummary *vSummary) :
    QWidget(parent),
    ui(new Ui::VCourseDetails)
{
    ui->setupUi(this);

    this->vSummary = vSummary;
}

VCourseDetails::~VCourseDetails()
{
    delete ui;
}

void VCourseDetails::prepare(QSqlRecord course) {
    this->course = course;

    loadTabTask();
    loadTabLesson();
    loadTabGeneralView();
}

void VCourseDetails::loadTabTask() {
    SummaryUtils::clearLayout(ui->layoutTask);

    // On crée le tableau pour l'affiche des notes
    QTableWidget *tblWidget = new QTableWidget;
    tblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tblWidget->setColumnCount(3);
    tblWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Nom"));
    tblWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Description"));
    tblWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Note"));

    // On récupère le nombre de tâches pour avoir le nombre de lignes dans la table
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM Task WHERE courseId = " + course.value("id").toString());
    query.next();
    tblWidget->setRowCount(query.value(0).toInt());

    // On parcourt toutes les tâches et on les ajoutes dans la table
    query.exec("SELECT * FROM Task WHERE courseId = " + course.value("id").toString());
    int row = 0;
    while(query.next()) {
        tblWidget->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        tblWidget->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        tblWidget->setItem(row, 2, new QTableWidgetItem(query.value(4).toString()));
        row++;
    }

    // On redimensionne la table pour qu'elle prenne toutes l'espace disponible
    tblWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->layoutTask->addWidget(tblWidget);
}

void VCourseDetails::loadTabGeneralView() {
    SummaryUtils::clearLayout(ui->layoutGeneralView);

    QLabel *lblText = new QLabel;
    ui->layoutGeneralView->setAlignment(Qt::AlignTop);

    // On parcourt les moyennes
    QList<Average> averages = SummaryUtils::getAllAveragesInCourse(course.value("id").toInt());
    for(int i = averages.length() - 1; i >= 0; i--) {
        // Lorsqu'on tombe sur la moyenne du cours on l'affiche en conséquence
        if(averages.at(i).name == "course") {
            // Moyenne vaut 0 = pas de note dans le cours
            if(averages.at(i).value == 0.f) {
                lblText->setText("Moyenne actuelle dans ce cours : - ");
            }
            else {

                // On affiche une couleur différente en fonction de la note (< 4 en orange et < que le seuil en rouge sinon en vert).

                lblText->setText("Moyenne actuelle dans ce cours(hors examen) : " + QString::number(averages.at(i).value, 'f', 1));
                lblText->setStyleSheet("color: green");
                if(averages.at(i).value < 4.f) {
                    lblText->setStyleSheet("color: orange");
                }
                if(averages.at(i).value < course.value("threshold").toFloat()) {
                    lblText->setStyleSheet("color: red");
                }
            }

            ui->layoutGeneralView->addWidget(lblText);
        }
        // Lorsqu'on tombe sur la moyenne des tâches par type, on les affiche en conséquence
        else {

            // On affiche la moyenne des tâches par type.
            // On affiche une couleur différente en fonction de la note (< 4 en orange et < que le seuil en rouge sinon en vert).

            QLabel *lbl = new QLabel("           Moyenne des " + averages.at(i).name + "(s) : " + QString::number(averages.at(i).value, 'f', 1));
            lbl->setStyleSheet("color: green");
            if(averages.at(i).value < 4.f) {
                lbl->setStyleSheet("color: orange");
            }
            if(averages.at(i).value < course.value("threshold").toFloat()) {
                lbl->setStyleSheet("color: red");
            }
            ui->layoutGeneralView->addWidget(lbl);

        }
    }
}

void VCourseDetails::loadTabLesson() {
    SummaryUtils::clearLayout(ui->layoutLesson);

    QSqlQuery query;
    query.exec("SELECT * FROM Lesson WHERE courseId = " + course.value("id").toString());

    QWidget *central = new QWidget;
    QScrollArea *scroll = new QScrollArea;
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->setAlignment(Qt::AlignTop);
    scroll->setWidget(central);
    scroll->setWidgetResizable(true);
    scroll->setContentsMargins(0, 0, 0, 0);

    int i = 0;
    while(query.next()) {
        VLessonFill *v = new VLessonFill(0, 0, vSummary);
        v->setEditionMode(true);
        v->setFieldsValue(query.value("id").toInt(), query.value("name").toString(), query.value("startHour").toString(), query.value("endHour").toString(), query.value("dayOfWeek").toInt(), query.value("courseId").toInt());
        layout->addWidget(v);
        i++;
    }

    // On ajoute un autre widget pour l'ajout d'une nouvelle leçon
    layout->addWidget(new VLessonFill(0, course.value("id").toInt(), vSummary));

    ui->layoutLesson->addWidget(scroll);
}

void VCourseDetails::refreshLessons() {
    loadTabLesson();
}
