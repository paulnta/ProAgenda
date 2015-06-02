#ifndef PRIORITY
#define PRIORITY

#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>

/*! @class Priority
 *  Classe gérant la priorité d'une tâche
 */
class Priority : public QWidget{

    Q_OBJECT

    Q_PROPERTY(int priority READ getPriority WRITE setPriority USER true)
    QLabel* label;
//    QHBoxLayout* layout;
    int priority;

public:
    /*!
     * Constructeur de la classe Priority
     * @param parent : widget parent
     */
    explicit Priority(QWidget* parent = 0) : QWidget(parent){
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setContentsMargins(0,0,0,0);
        label = new QLabel;
        layout->addWidget(label);
        setLayout(layout);
    }
    /*!
     * @brief retourne la priorité de la tâche
     * @return la priorité
     */
    int getPriority() const
    {
        return priority;
    }
    /*!
     * @brief modifie la priorité
     */
    void setPriority(int value)
    {
        priority = value;
        label->setText(QString("!").repeated(value));
    }

};

#endif // PRIORITY

