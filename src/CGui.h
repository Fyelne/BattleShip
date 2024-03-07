#ifndef CGUI_H
#define CGUI_H

#include "BiblioStd.h"
#include "CArmada.h"
#include "CCoups.h"
#include "CBaseJeu.h"

/**
 * @brief La classe CGui représente l'interface graphique du jeu.
 * Elle hérite de la classe CBaseJeu.
 */
class CGui : public CBaseJeu {
private:
    char m_grilleJou[TAILLE_GRILLE-1][TAILLE_GRILLE-1]; /**< Grille de jeu du joueur */
    char m_grilleAdv[TAILLE_GRILLE-1][TAILLE_GRILLE-1]; /**< Grille de jeu de l'adversaire */
    CArmada* m_pArmada; /**< Pointeur vers l'armada du joueur */
    CCoups* m_pCoups; /**< Pointeur vers les coups joués */

public:
    /**
     * @brief Constructeur par défaut de la classe CGui.
     */
    CGui();

    /**
     * @brief Constructeur de copie de la classe CGui.
     * @param original L'objet CGui à copier.
     */
    CGui(const CGui& original);

    /**
     * @brief Constructeur de la classe CGui.
     * @param pArmada Pointeur vers l'armada du joueur.
     * @param pCoups Pointeur vers les coups joués.
     */
    CGui(CArmada* pArmada, CCoups* pCoups);

    /**
     * @brief Destructeur de la classe CGui.
     */
    virtual ~CGui();

    /**
     * @brief Définit l'armada et les coups joués.
     * @param pArmada Pointeur vers l'armada du joueur.
     * @param pCoups Pointeur vers les coups joués.
     */
    void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);

    /**
     * @brief Positionne les bateaux sur la grille de jeu.
     * @return Vrai si les bateaux ont été positionnés avec succès, sinon faux.
     */
    bool positionnerBateaux();

    /**
     * @brief Permet au joueur de choisir une attaque.
     * @return Une paire d'entiers représentant les coordonnées de l'attaque.
     */
    pair<int, int> choisirAttaque();

    /**
     * @brief Affiche un message de victoire.
     */
    void afficheGagne();

    /**
     * @brief Affiche un message de défaite.
     */
    void affichePerdu();

    /**
     * @brief Surcharge de l'opérateur de flux de sortie pour afficher l'objet CGui.
     * @param os Le flux de sortie.
     * @param theG L'objet CGui à afficher.
     * @return Le flux de sortie mis à jour.
     */
    friend ostream& operator<<(ostream& os, CGui& theG);

    /**
     * @brief Remplit les deux grilles de jeu avec les bateaux et les coups joués.
     * @param os Le flux de sortie.
     */
    void remplirDeuxGrilles(ostream& os);

    /**
     * @brief Affiche la grille de jeu spécifiée.
     * @param os Le flux de sortie.
     * @param jouOuAdv Indique si la grille à afficher est celle du joueur ou de l'adversaire.
     */
    void afficherLaGrille(ostream& os, string jouOuAdv);
};

#endif /* CGUI_H */
