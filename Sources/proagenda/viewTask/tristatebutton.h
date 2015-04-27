#ifndef TRISTATEBUTTON
#define TRISTATEBUTTON

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class TriStateButton: public QWidget{

    Q_OBJECT

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QHBoxLayout* layout;

    int choice;

public:
    explicit TriStateButton(QString label, QString text1, QString text2, QString text3){

        layout = new QHBoxLayout(this);
        button1 = new QPushButton(text1);
        button2 = new QPushButton(text2);
        button3 = new QPushButton(text3);


        button1->setCheckable(true);
        button2->setCheckable(true);
        button3->setCheckable(true);

        button1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
        button2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
        button3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);

        layout->addWidget(new QLabel(label));
        layout->addWidget(button1);
        layout->addWidget(button2);
        layout->addWidget(button3);
        layout->setSpacing(1);
        layout->setContentsMargins(0,0,0,0);

        checkButton2();

        connect(button1,SIGNAL(clicked()), this,SLOT(checkButton1()));
        connect(button2,SIGNAL(clicked()), this,SLOT(checkButton2()));
        connect(button3,SIGNAL(clicked()), this,SLOT(checkButton3()));
    }

    int getChoice(){
        return choice;
    }

    void setChoice(int value){

        switch(value){
        case 1:
            checkButton1();
            break;
        case 2:
            checkButton2();
            break;
        case 3:
            checkButton3();
            break;
        }
    }

    ~TriStateButton(){
        delete button1;
        delete button2;
        delete button3;
        delete layout;
    }

private slots:

    void checkButton1(){
        button1->setChecked(true);
        button2->setChecked(false);
        button3->setChecked(false);
        choice = 1;
    }

    void checkButton2(){
        button2->setChecked(true);
        button1->setChecked(false);
        button3->setChecked(false);
        choice = 2;
    }

    void checkButton3(){
        button3->setChecked(true);
        button1->setChecked(false);
        button2->setChecked(false);
        choice = 3;
    }


};
#endif // TRISTATEBUTTON

