#include "toolbutton.h"

ToolButton::ToolButton(QString text, QString iconPath = NULL)
{
    setText(text);
    setCursor(Qt::PointingHandCursor);

    if(iconPath != NULL){
        setIcon(QIcon(iconPath));
        setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    }
}

ToolButton::~ToolButton()
{

}

