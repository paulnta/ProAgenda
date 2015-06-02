#ifndef TERMDATE_H
#define TERMDATE_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>

/*!
 * Indication de la date d'échance d'une tâche
 * nb jours  = 1 : demain
 * nb jours  = 2 : après-demain
 * nb jours > 2  : lundi, mardi, etc..
 *
 * @class TermDate
 * classe gérant l'affichage de la date d'échéance d'une tâche
 */
class TermDate : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString termDate READ getTermDate WRITE setTermDate USER true)

public:
    /*!
     * @brief Constructeur
     * Constructeur de la classe TermDate
     * @param parent : le widget parent
     */
    explicit TermDate(QWidget *parent = 0);
    /*!
     * @brief Destructeur
     * Destructeur de la classe TermDate
     */
    ~TermDate();

    QString termDate;
    QLabel* label;
    QHBoxLayout* layout;
    QFont font;

     // Style du texte (date d'échéance)
    const QString STYLE_DEFAULT;
    const QString STYLE_WARNING;

    /*!
     * @brief Récupération de la date d'échéance
     * Récupération de la date d'échéance sous la forme demain, dans 3 jours etc...
     * @return la date d'échéance
     */
    QString getTermDate() const;

    /*!
     * Affichage friendly de la date d'échance dans la liste des tâches
     * aujourd'hui, demain, après-demain ou dans x jours
     *
     * @brief TermDate::setTermDate
     * @param value
     */
    void setTermDate(QString value);


};

#endif // TERMDATE_H
