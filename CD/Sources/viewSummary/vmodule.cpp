#include "vmodule.h"
#include "ui_vmodule.h"

VModule::VModule(QWidget *parent, VSummary* vSummary) :
    QWidget(parent),
    ui(new Ui::VModule)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM Module");

    // On crée une zone avec scrolling
    // Les objets alloués ici seront delete lors de la suppression de l'ui.
    // Celle-ci est détruite à chaque delete de la classe VModule (qui est fait ailleurs,
    // avant chaque nouvelle création d'une VModule).
    QWidget *central = new QWidget;
    QScrollArea *scroll = new QScrollArea;
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->setAlignment(Qt::AlignTop);
    scroll->setWidget(central);
    scroll->setWidgetResizable(true);
    scroll->setContentsMargins(0, 0, 0, 0);

    // On parcourt tous les modules et on crée les vues en conséquences.
    // On les ajoute dans le layout avec zone de scrolling.
    int i = 0;
    while(query.next()) {
        VModuleFill *v = new VModuleFill(0, vSummary);
        v->setEditionMode(true);
        v->setFieldsValue(query.value("id").toInt(), query.value("name").toString(), query.value("description").toString(), query.value("threshold").toFloat());
        layout->addWidget(v);
        i++;
    }

    // On ajoute un autre widget pour l'ajout d'une nouvelle leçon
    layout->addWidget(new VModuleFill(0, vSummary));

    // On ajoute le tout dans le layout principal
    ui->layoutMain->addWidget(scroll);
}

VModule::~VModule()
{
    delete ui;
}
