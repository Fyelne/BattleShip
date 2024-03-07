#ifndef DEF_CARMADA_H
#define DEF_CARMADA_H

#include "CBateau.h"
#include "BiblioStd.h"


/**
 * @brief Classe représentant une armada de bateaux.
 * 
 * Cette classe permet de gérer une collection de bateaux.
 */
class CArmada {
private:
    vector<CBateau> m_listeBateaux; /**< Liste des bateaux de l'armada */

public:
    /**
     * @brief Constructeur par défaut de CArmada.
     */
    CArmada() = default;

    /**
     * @brief Constructeur de copie de CArmada.
     * @param original L'armada à copier.
     */
    CArmada(const CArmada& original);

    /**
     * @brief Ajoute un bateau à l'armada.
     * @param unBat Le bateau à ajouter.
     */
    void ajouterBateau(CBateau& unBat);

    /**
     * @brief Récupère le bateau à l'indice spécifié.
     * @param i L'indice du bateau.
     * @return Un pointeur vers le bateau.
     */
    CBateau* getBateau(int i);

    /**
     * @brief Récupère l'effectif total de l'armada.
     * @return L'effectif total de l'armada.
     */
    int getEffectifTotal();

    /**
     * @brief Récupère le nombre total de cases occupées par les bateaux de l'armada.
     * @return Le nombre total de cases occupées.
     */
    int getNbreTotCases();

    /**
     * @brief Récupère l'effectif actuel de l'armada (bateaux coulés retirés).
     * @return L'effectif actuel de l'armada.
     */
    int getEffectif();

    /**
     * @brief Charge les données de l'armada à partir d'un fichier.
     */
    void getArmadaFromFile();

    /**
     * @brief Place les bateaux de l'armada de manière aléatoire sur la grille.
     * @return Vrai si les bateaux ont été placés avec succès, sinon faux.
     */
    bool placerAleatoirement();
};

#endif /* CARMADA_H */