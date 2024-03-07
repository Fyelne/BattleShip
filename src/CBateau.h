#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

/**
 * @class CBateau
 * @brief Représente un bateau dans le jeu.
 * 
 * Cette classe contient les informations relatives à un bateau, telles que sa taille, son nom, sa position,
 * les dégâts subis, etc.
 */
class CBateau {
private:
    int m_taille; // nombre de cases occupées (horizontalement) sur la grille
    string m_nom; // nom du bateau
    pair<int,int> m_position; // coord. (int ligneHoriz, int colonneVert) du point d'ancrage
                              // m_position.first = le numéro de la ligne horizontale
                              // m_position.second = le numéro de la colonne verticale
    bool* m_pDegats; // tableau des dégâts de taille m_taille (case à faux si pas de dégât)

public:
    /**
     * @brief Constructeur par défaut de CBateau.
     */
    CBateau();

    /**
     * @brief Constructeur de copie de CBateau.
     * @param original Le bateau à copier.
     */
    CBateau(const CBateau& original);

    /**
     * @brief Constructeur de CBateau.
     * @param n Le nom du bateau.
     * @param p La position du bateau.
     * @param t La taille du bateau.
     */
    CBateau(string n, pair<int,int> p, int t);

    /**
     * @brief Obtient l'état des dégâts d'une case spécifique du bateau.
     * @param i L'indice de la case.
     * @return true si la case a subi des dégâts, false sinon.
     */
    bool getDegats(int i);

    /**
     * @brief Obtient le nom du bateau.
     * @return Le nom du bateau.
     */
    string getNom();

    /**
     * @brief Obtient la taille du bateau.
     * @return La taille du bateau.
     */
    int getTaille();

    /**
     * @brief Obtient la position du bateau.
     * @return La position du bateau.
     */
    pair<int,int> getPosition();

    /**
     * @brief Définit la position du bateau.
     * @param i Le numéro de la ligne horizontale.
     * @param j Le numéro de la colonne verticale.
     */
    void setPosition(int i, int j);

    /**
     * @brief Vérifie si le bateau est coulé.
     * @return true si le bateau est coulé, false sinon.
     */
    bool estCoule();

    /**
     * @brief Effectue un tir adverse sur le bateau.
     * @param p Les coordonnées du tir adverse.
     * @return true si le tir a touché le bateau, false sinon.
     */
    bool tirAdverse(pair<int,int> p);

    /**
     * @brief Surcharge de l'opérateur de flux de sortie pour afficher le bateau.
     * @param os Le flux de sortie.
     * @param theB Le bateau à afficher.
     * @return Le flux de sortie mis à jour.
     */
    friend ostream& operator<<(ostream& os, CBateau& theB);

    /**
     * @brief Surcharge de l'opérateur d'affectation pour copier un bateau.
     * @param theB Le bateau à copier.
     * @return Une référence vers le bateau copié.
     */
    CBateau& operator=(CBateau& theB);
};

#endif /* CBATEAU_H */