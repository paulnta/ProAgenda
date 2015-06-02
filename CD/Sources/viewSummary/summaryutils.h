#ifndef SUMMARYUTILS_H
#define SUMMARYUTILS_H

#include <cmath>
#include <QLayout>
#include <QLayoutItem>
#include <QMap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <QTableWidget>
#include <QWidget>

#include "average.h"

class VSummary;

/*! \class SummaryUtils
 * \brief Classe utilitaire.
 *
 *  Possède des fonctions statiques utilitaires.
 */
class SummaryUtils {
public:

    /*!
     * \brief Exécute la requête SQL passée en paramètre
     *
     * \param query : Requête SQL à exécuter
     */
    static void execQueryOnDatabase(QString query) {
        QSqlQuery sqlQuery;
        sqlQuery.prepare(query);
        sqlQuery.exec();
    }

    /*!
     * \brief Affiche une message box contentant un message avec les boutons "OK" et "Cancel".
     *
     * \param text : Le texte à afficher
     * \return la valeur du bouton sélectionné par l'utilisateur (OK = QMessageBox::Ok, Cancel = QMessageBox::Cancel)
     */
    static int messageBoxOkCancel(QString text) {
        QMessageBox msgBox;
        msgBox.setText(text);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        return msgBox.exec();
    }

    /*!
     * \brief Vide le layout passé en paramètre.
     *
     *  Supprime tous les widgets à l'intérieur du layout passé en paramètre.
     *
     * \param layout : Le layout à vider
     */
    static void clearLayout(QLayout *layout) {
        QLayoutItem* item;
        while ( ( item = layout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    /*!
     * \brief Retourne la liste des moyennes des cours
     *
     * Retourne les moyennes des cours (moyenne des types de tâches (TE, Labo...)) et
     * du cours
     *
     * \param courseId : L'id du cours dans lequel calculer les moyennes
     * \return La liste des moyennes
     */
    static QList<Average> getAllAveragesInCourse(int courseId) {
        QList<Average> averages;

        QSqlQuery taskQuery;
        taskQuery.exec("SELECT * FROM Task WHERE courseId = " + QString::number(courseId));

        QSqlQuery typeQuery;
        typeQuery.exec("SELECT * FROM Type");

        float courseAverage = 0.f;
        int nbTypes = 0;
        float lastWeighting;
        // On parcourt tous les types
        while(typeQuery.next()) {
            taskQuery.exec("SELECT * FROM Task WHERE courseId = " + QString::number(courseId) + " AND typeId = " + typeQuery.value("id").toString());

            float average = 0.f;
            int nbNotes = 0;
            float coef = 0.f;

            // On parcourt toutes les tâches possédant le type en cours
            while(taskQuery.next()) {
                if(taskQuery.value("note").toFloat() > 0.f) {
                    // On calcul la moyenne en tenant compte du coefficient
                    coef += taskQuery.value("coefficient").toFloat();
                    if(coef == 1.f) {
                        nbNotes++;
                        coef = 0.f;
                    }
                    average += taskQuery.value("note").toFloat() * taskQuery.value("coefficient").toFloat();
                }
            }

            if(nbNotes > 0) {
                // On calcule la moyenne finale du type en cours
                average /= nbNotes;
                average = floor((average + 0.05f) * 10.f) / 10.f;

                // On ajoute la moyenne dans la liste
                averages.append(Average(typeQuery.value("name").toString(), average));

                lastWeighting = typeQuery.value("weighting").toFloat() / 100.f;
                average *= lastWeighting;
                nbTypes++;
                courseAverage += average;
            }
        }

        // On calcul la moyenne du cours
        if(nbTypes > 1) {
            courseAverage *= nbTypes;
        }
        else if(lastWeighting > 0.f) {
            courseAverage /= lastWeighting;
        }

        // On arrondi
        courseAverage = floor((courseAverage + 0.05f) * 10.f) / 10.f;

        averages.append(Average("course", courseAverage));

        return averages;
    }
};

#endif // SUMMARYUTILS_H

