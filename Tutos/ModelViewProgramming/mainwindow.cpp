#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QTextStream>
#include <QSqlRecord>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

/**
 * Bases model view programming qt
 * ================================
 *
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Initialisation du model
     */
    setUpModel();


    /*
     * On utilise deux vue pour représenter le model
     *
     *
     * 1) Le model est connecté à la base de donnée
     *    Si l'EditStrategy == onManualSubmit, le model ne pas tout
     *    seul à jout la base de donnée, il faut dans ce cas appeler submitAll()
     *
     *
     * 2) Les vue ne sont pas connectées à la base de donnée mais au Model.
     *    Donc même sans submitAll(), toutes les vues représantant le model sont mise à jour
     *
     *
     * Pour mettre à jour la base de donnée simplement, deux solutions possible:
     * a) créer un slot updateModel() qui fait juste un submitAll ez le connecter un bouton.
     *    Dans ce cas l'utilisateur met à jour la database manuellement avec un bouton save.
     *
     *
     * b) ou connecter le signal dataChanged() du model au slotSumbitAll.
     *    Dans ce cas au moindre changement du model depuis une vue ou depuis le code, la database est mise à jour
     */

    QHBoxLayout* layout = new QHBoxLayout();
    viewTable = new QTableView;
    viewList = new QListView;
    viewTable->setModel(model);  // les deux vues représentent le même model
    viewList->setModel(model);
    viewList->setModelColumn(1); // la liste affiche la deuxième colonne

    layout->addWidget(viewTable);
    layout->addWidget(viewList);

    layout->setContentsMargins(0,0,0,0);
    ui->centralWidget->setLayout(layout);

    // Ici on choisi la solution b) pour mettre à jour la database
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), model, SLOT(submitAll()));

}

/**
 * Set Model
 * Ici on choisi OnManualSubmit comme EditStrategy. Cela à un grand impact
 * sur la suite du code: Chaque modification doit être suivie d'un model->submitAll()
 *
 * OnManualSubmit est le plus simple à gérer et aussi le plus efficace lorsque plusieurs vue
 * doivent pouvoir modifier le model et les afficher.
 */
void MainWindow::setUpModel(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // si le fichier Database n'existe pas, il sera créé mais vide.
    db.setDatabaseName("Database");
    db.open();


    // Pas besoin de dire explicitement quel base de donnée. Il y a en qu'une seul,
    // Elle a été ouverte avec db.open() et elle est partagé partout.
    model = new QSqlRelationalTableModel();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("Task");
    model->select();
}


/**
 * Slot permettant de faire la mise à jour de la base de donnée
 * suite à une modification du model
 *
 * @brief MainWindow::updateModel
 */
void MainWindow::updateModel(){

    qDebug() << "will update model, dirty :" << model->isDirty();
    model->submitAll();
}


/**
 * Ajout d'une ligne dans le model
 * Le model est mise à jour immédiatement ainsi que toute les vues.
 * Cependant, la base de donnée à besoin d'un submitAll()
 *
 * @brief MainWindow::on_actionAddTask_triggered
 */
void MainWindow::on_actionAddTask_triggered()
{
    // le model nous retourne un QSqlrecord vide
    // il est important que ce soit le model qui nous le donne
    // Essayez de le faire sans le récuperer depuis le model et "bonjour les bugs bizzare".
    QSqlRecord record = model->record();

    // Ajout de valeurs par défaut
    record.setValue(1, QVariant("new Task"));

    // Insertion (si postion = -1, l'insertion se fait à la fin)
    model->insertRecord(-1,record);

    // Mise à jour de la base de donnée
    // Sans submitAll, la ligne se trouve ne cache et est supprimée
    // au à la fin du programe
    model->submitAll();
}

/**
 * Suppression de toute les lignes du model
 * Prend effet seulement après submitAll
 *
 * @brief MainWindow::on_actionClear_All_triggered
 */
void MainWindow::on_actionClear_All_triggered()
{
    // On supprime les lignes 0 à rowCount()
    model->removeRows(0,model->rowCount());

    // On met à jour la base de donnée
    model->submitAll();
}

void MainWindow::on_actionUpdateModel_triggered()
{
    updateModel();
}


/**
 * Pas utilisé dans cet exemple, mais ce slot très simple permet
 * de demander une confirmation et de tester la réponse de l'utilisateur
 *
 * @brief MainWindow::confirmationDelete
 */
void MainWindow::confirmation(){

    int ret = QMessageBox::warning(this, tr("My Application"),                                      // parent, Titre
                                   tr("The document has been modified.\n"                           // Informations
                                      "Do you want to save your changes?"),
                                   QMessageBox::Save | QMessageBox::Cancel,                         // Liste des differentz bouton
                                   QMessageBox::Save);                                              // Bouton séléctionné par défaut

    switch (ret) {

        case QMessageBox::Save:
            qDebug() << "Choisi: Save";
            model->submitAll();
            break;

        case QMessageBox::Cancel:
            qDebug() << "Choisi Cancel";
            model->revertAll();
            break;
        }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete viewTable;
}

