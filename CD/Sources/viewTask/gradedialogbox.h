#ifndef GRADEDIALOGBOX_H
#define GRADEDIALOGBOX_H
#include <QDialog>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QDebug>

/*! @class gradedialogbox
 *
 * Classe créant une pop up pour ajouter une note et un coefficient à une tâche
 */

class gradedialogbox : public QDialog
{
    Q_OBJECT
public:
    /*!
     * Constructeur de la classe gradedialogbox
     * @param parent :widget parent
     */
    gradedialogbox(QWidget * parent);
    /*!
     * Destructeur de la classe gradedialogbox
     */
    ~gradedialogbox();

    /*!
     * @brief retourne la valeur de la note
     * @return la valeur de la note
     */
    double getGrade(){
        return grade;
    }
    /*!
     * @brief retourne la valeur du coefficient
     * @return la valeur du coefficient
     */
    double getCoeff(){
        return coeff;
    }

private:
    double grade;
    double coeff;
    QPushButton* ok;
    QPushButton* cancel;
    QDoubleSpinBox *noteBox;
    QDoubleSpinBox *coeffBox;
    QFormLayout *layout;

signals:
    /*!
     * @brief signal emis lorsque les note ou coefficient sont modifiés
     */
    void updateValue();
    /*!
     * @brief signal emis lorsque les note ou coefficient ne sont pas modifiés
     */
    void canceledValue();

public slots:
    /*!
     * @brief slot récupérant la valeur de la note de la boîte de dialogue
     * @param grade : valeur de la note
     */
    void setGrade(double grade ){
        this->grade = grade;
    }
    /*!
     * @brief slot récupérant la valeur du coefficient de la boîte de dialogue
     * @param coeff : valeur de la coefficient
     */
    void setCoeff(double coeff){
        this->coeff = coeff;
    }
    /*!
     * @brief slot emettant un signal avertissant du changement des valeurs
     */
    void changedValue(){
        emit updateValue();
    }
    /*!
     * @brief slot emettant un signal avertissant qu'aucune valeur n'a été changée
     */
    void canceled(){
        emit canceledValue();
    }
};

#endif // GRADEDIALOGBOX_H
