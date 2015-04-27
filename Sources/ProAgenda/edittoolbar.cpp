#include "edittoolbar.h"

EditToolBar::EditToolBar()
{
    // Paramètres généraux de la ToolBar
    setIconSize(QSize(20,20));
    setLayoutDirection(Qt::RightToLeft);

    // Menu du bouton add
    QMenu* addMenu = new QMenu();
    addUnit = new QAction("Ajouter un cours", addMenu);
    addTask = new QAction("Ajouter une tâche", addMenu);
    addMenu->addAction(addUnit);
    addMenu->addAction(addTask);

    // Application de fonctions aux Actions du menu
    connect(addUnit, SIGNAL(triggered()), this, SLOT(onAddunitTriggered()));
    connect(addTask, SIGNAL(triggered()), this, SLOT(onAddtaskTriggered()));

    // Création du bouton avec Icone
    addButton = new ToolButton("Ajouter", ":/icons/img/icons/ic_add_to_photos_48px.svg");
    this->addWidget(addButton);

    // Connexion du menu au bouton
    addButton->setMenu(addMenu);
    addButton->setPopupMode(QToolButton::InstantPopup);

}

EditToolBar::~EditToolBar()
{
    delete addButton;
    delete addTask;
    delete addUnit;
}

void EditToolBar::onAddtaskTriggered()
{
    qDebug() << "onAddtaskTriggered";
}

void EditToolBar::onAddunitTriggered()
{
    qDebug() << "onAddunitTriggered";
}

