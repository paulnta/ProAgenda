#include "sidebarsummary.h"
#include "ui_sidebarsummary.h"

SideBarSummary::SideBarSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideBarSummary)
{
    ui->setupUi(this);
}

SideBarSummary::~SideBarSummary()
{
    delete ui;
}

QVBoxLayout *SideBarSummary::getLayout()
{
    return ui->layoutSideBar;
}
