#include "toolbarsummary.h"

ToolBarSummary::ToolBarSummary(Ui::MainWindow *ui, VSummary *vSummary): ui(ui)
{
    setIconSize(QSize(20,20));
    setLayoutDirection(Qt::RightToLeft);

    // Menu du bouton add
    QMenu* addMenu = new QMenu();
    addCourse = new QAction("Ajouter un cours",addMenu);
    addSemester = new QAction("Ajouter un semestre",addMenu);
    addMenu->addAction(addCourse);
    addMenu->addAction(addSemester);

    // Application de fonctions aux Actions du menu
    connect(addCourse, SIGNAL(triggered()), this, SLOT(onAddCourseTriggered()));
    connect(addSemester, SIGNAL(triggered()), this, SLOT(onAddSemesterTriggered()));

    // Création du bouton avec Icone
    addButton = new ToolButton("Ajouter", ":/icons/img/icons/ic_add_to_photos_48px.svg");
    this->addWidget(addButton);

    // Connexion du menu au bouton
    addButton->setMenu(addMenu);
    addButton->setPopupMode(QToolButton::InstantPopup);

    this->vSummary = vSummary;
}

ToolBarSummary::~ToolBarSummary()
{

}

void ToolBarSummary::onAddCourseTriggered()
{
    vSummary->addCourse();
}

void ToolBarSummary::onAddSemesterTriggered()
{
    vSummary->addSemester();
}
