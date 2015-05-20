#ifndef PRIORITY
#define PRIORITY

#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>


class Priority : public QWidget{

    Q_OBJECT

    Q_PROPERTY(int priority READ getPriority WRITE setPriority USER true)
    QLabel* label;
//    QHBoxLayout* layout;
    int priority;

public:

    explicit Priority(QWidget* parent = 0) : QWidget(parent){
        QHBoxLayout* layout = new QHBoxLayout(this);
        label = new QLabel;
        layout->addWidget(label);
        setLayout(layout);
    }

    int getPriority() const
    {
        return priority;
    }

    void setPriority(int value)
    {
        priority = value;
        label->setText(QString("!").repeated(value));
    }

};

#endif // PRIORITY

