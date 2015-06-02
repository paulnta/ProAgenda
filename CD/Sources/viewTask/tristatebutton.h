#ifndef TRISTATEBUTTON
#define TRISTATEBUTTON

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


/*! @class TriStateButton
 *  Classe représentant un widget avec trois bouttons
 *  dont seul un choix entre les trois bouttons est permis
 */
class TriStateButton: public QWidget{

    Q_OBJECT

    Q_PROPERTY(int choice READ getChoice WRITE setChoice USER true)

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QHBoxLayout* layout;

    int choice;

public:

    /*!
     * @brief Constructeur
     *  Constructeur de la classe TriStateButton
     *  @param label : nom du widget
     *  @param text1 : texte du premier boutton
     *  @param text2 : texte du deuxième boutton
     *  @param text3 : texte du troisième boutton
     */
    explicit TriStateButton(QString label, QString text1, QString text2, QString text3);

    /*!
     * @brief Récupère le boutton choisi
     *  @return la valeur du boutton choisi
     */
    int getChoice();

    /*!
     * @brief Séléction d'un boutton
     *  @param value : valeur du boutton chois
     */
    void setChoice(int value);


    /*!
     * @brief Destructeur
     *  Destructeur de la classe TriStateButton
     */
    ~TriStateButton(){
        delete button1;
        delete button2;
        delete button3;
        delete layout;
    }

private slots:

    /*!
     * @brief Choix boutton 1
     * Lorsque l'utilisateur choisi le premier boutton
     * cette fonction est appellée. Le design du boutton choisi
     * est modifié. Le boutton précédement chois est déséléctionnée
     */
    void checkButton1();

    /*!
     * @brief Choix boutton 2
     * Lorsque l'utilisateur choisi le deuxième boutton
     * cette fonction est appellée. Le design du boutton choisi
     * est modifié. Le boutton précédement chois est déséléctionnée
     */
    void checkButton2();
    /*!
     * @brief Choix boutton 3
     * Lorsque l'utilisateur choisi le troisième boutton
     * cette fonction est appellée. Le design du boutton choisi
     * est modifié. Le boutton précédement chois est déséléctionnée
     */
    void checkButton3();


};
#endif // TRISTATEBUTTON

