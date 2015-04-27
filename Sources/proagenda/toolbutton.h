#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>
#include <QMenu>

class ToolButton : public QToolButton
{
public:
    ToolButton(QString text, QString iconPath);
    ~ToolButton();
};

#endif // TOOLBUTTON_H
