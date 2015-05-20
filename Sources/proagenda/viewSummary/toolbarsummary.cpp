#include "toolbarsummary.h"

ToolBarSummary::ToolBarSummary(Ui::MainWindow *ui): ui(ui)
{
    setIconSize(QSize(20,20));
    setLayoutDirection(Qt::RightToLeft);

    this->addWidget(new ToolButton("Example", ":/icons/img/icons/ic_assignment_48px.svg"));
}

ToolBarSummary::~ToolBarSummary()
{

}

