#ifndef AVERAGE
#define AVERAGE

#include <QString>

/*! \struct Average
 * \brief Structure représentant une moyenne (nom et valeur)
 *
 * Utilisé dans le calcul des moyennes pour les cours et modules
 */
struct Average {
    QString name;
    float value;

    Average(QString name, float value) {
        this->name = name;
        this->value = value;
    }
};

#endif // AVERAGE

