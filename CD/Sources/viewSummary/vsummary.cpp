#include "vsummary.h"
#include "ui_vsummary.h"

#include <QtSql/QtSql>
#include "vsemesterfill.h"
#include "vcoursefill.h"
#include "sqlconnection.h"
#include "utils.h"
#include "mainwindow.h"
#include "testtreeview.h"

VSummary::VSummary(MainWindow* mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VSummary),
    mainWindow(mainWindow)
{
    ui->setupUi(this);

    // Vue d'ajout et de modification des semestres
    vSemesterFill = new VSemesterFill(0, this);
    ui->layoutFill->addWidget(vSemesterFill);

    // Vue d'ajout et de modification des cours
    vCourseFill = new VCourseFill(0, this);

    // Vue d'affichage du détails des cours
    vCourseDetails = new VCourseDetails(0, this);

    // Vue d'affichage des modules
    vModule = new VModule(0, this);
    ui->layoutDisplay->addWidget(vModule);

    // Création et affichage du TreeView à droite
    ttv = new SideBarTreeView(0, this);
    mainWindow->getSideBarSummary()->getLayout()->addWidget(ttv);
}

VSummary::~VSummary()
{
    delete ui;
}

void VSummary::refreshSideBar() {

    // Sauvegarde l'état du treeView et l'élément sélectionné
    QStringList list;
    foreach(QModelIndex index, ttv->getTreeModel()->getPersistentIndexList()) {
        if(ttv->getTreeView()->isExpanded(index)) {
            list << index.data(Qt::DisplayRole).toString();
        }
    }

    // On supprime le widget
    mainWindow->getSideBarSummary()->getLayout()->removeWidget(ttv);
    delete ttv;


    // On recrée la sideBar
    ttv = new SideBarTreeView(0, this);

    // On la remet dans son état précédent
    foreach(QString item, list) {
        QModelIndexList items = ttv->getTreeModel()->match(ttv->getTreeModel()->index(0, 0), Qt::DisplayRole, QVariant::fromValue(item));
        if(!items.isEmpty()) {
            ttv->getTreeView()->setExpanded(items.first(), true);
        }
    }
    // On sélectionne le 1er élément pour la mise à jour
    ttv->getTreeView()->selectionModel()->setCurrentIndex(ttv->getTreeModel()->index(0, 0), QItemSelectionModel::SelectCurrent);

    // On l'ajoute à la fenêtre
    mainWindow->getSideBarSummary()->getLayout()->addWidget(ttv);
}

void VSummary::refreshModules() {
    ui->layoutDisplay->removeWidget(vModule);
    delete vModule;

    vModule = new VModule(0, this);
    ui->layoutDisplay->addWidget(vModule);
}

void VSummary::refreshLessons() {
    vCourseDetails->refreshLessons();
}

void VSummary::emptyVSemesterFill() {
    ui->layoutFill->removeWidget(vSemesterFill);
    delete vSemesterFill;

    vSemesterFill = new VSemesterFill(0, this);
    ui->layoutFill->addWidget(vSemesterFill);
}

void VSummary::emptyVCourseFill() {
    ui->layoutFill->removeWidget(vCourseFill);
    delete vCourseFill;

    vCourseFill = new VCourseFill(0, this);
    ui->layoutFill->addWidget(vCourseFill);
}

void VSummary::addCourse() {
    delete vCourseFill;
    vCourseFill = new VCourseFill(0, this);

    removeWidgetInLayout(ui->layoutFill, vSemesterFill);
    ui->layoutFill->addWidget(vCourseFill);
}

void VSummary::addSemester() {
    delete vSemesterFill;
    vSemesterFill = new VSemesterFill(0, this);

    removeWidgetInLayout(ui->layoutFill, vCourseFill);

    ui->layoutFill->addWidget(vSemesterFill);
}

void VSummary::switchViews(bool isSemesterView) {
    // Lorsqu'on change de vue, on enlève celles liées au cours et on met celles
    // liées au semestre et inversement
    if(isSemesterView) {
        ui->layoutFill->addWidget(vSemesterFill);
        removeWidgetInLayout(ui->layoutFill, vCourseFill);

        ui->layoutDisplay->addWidget(vModule);
        removeWidgetInLayout(ui->layoutDisplay, vCourseDetails);
    }
    else {
        ui->layoutFill->addWidget(vCourseFill);
        removeWidgetInLayout(ui->layoutFill, vSemesterFill);

        ui->layoutDisplay->addWidget(vCourseDetails);
        removeWidgetInLayout(ui->layoutDisplay, vModule);
    }
}

void VSummary::removeWidgetInLayout(QLayout *layout, QWidget *widget) {
    layout->removeWidget(widget);
    widget->setParent(NULL);
}
