#include "CGui.h"

/**
* @brief Constructeur par défaut de la classe CGui.
*/
CGui::CGui() {
    m_pArmada = NULL;
    m_pCoups = NULL;
}

/**
* @brief Constructeur de copie de la classe CGui.
* @param original L'objet CGui à copier.
*/
CGui::CGui(const CGui& original) {
    if (original.m_pArmada == NULL) {
        m_pArmada = NULL;
    } else {
        m_pArmada = new CArmada(*original.m_pArmada);
    }

    if (original.m_pCoups == NULL) {
        m_pCoups = NULL;
    } else {
        m_pCoups = new CCoups(*original.m_pCoups);
    }
}

/**
* @brief Constructeur de la classe CGui.
* @param pArmada Pointeur vers l'armada du joueur.
* @param pCoups Pointeur vers les coups joués.
*/
CGui::CGui(CArmada* pArmada, CCoups* pCoups) {
    setArmadaCoups(pArmada, pCoups);
}

/**
* @brief Destructeur de la classe CGui.
*/
CGui::~CGui() {
    delete m_pArmada;
    delete m_pCoups;
}

/**
* @brief Définit l'armada et les coups joués.
* @param pArmada Pointeur vers l'armada du joueur.
* @param pCoups Pointeur vers les coups joués.
*/
void CGui::setArmadaCoups(CArmada* pArmada, CCoups* pCoups) {
    if (pArmada == NULL || pCoups == NULL) {
        throw invalid_argument("Erreur: pArmada et pCoups ne peuvent pas être nuls.");
    }
    
    m_pArmada = pArmada;
    m_pCoups = pCoups;
}

/**
* @brief Positionne les bateaux sur la grille de jeu.
* @return Vrai si les bateaux ont été positionnés avec succès, sinon faux.
*/
bool CGui::positionnerBateaux() {
    if (m_pArmada == NULL) {
        cout << "Erreur: m_pArmada ne peut pas être nul." << endl;
        throw invalid_argument("Erreur: m_pArmada ne peut pas être nul.");
    }
    
    return m_pArmada->placerAleatoirement();
}

/**
* @brief Permet au joueur de choisir une attaque.
* @return Une paire d'entiers représentant les coordonnées de l'attaque.
*/
pair<int, int> CGui::choisirAttaque() {
    int ligne, colonne;
    
    // Demande de la ligne
    cout << "Entrez la ligne de votre attaque : ";
    cin >> ligne;

    // Vérification de la validité de la ligne
    while (cin.fail() || ligne < 0 || ligne > TAILLE_GRILLE - 1) {
        cout << "Entrée invalide. Veuillez réessayer : ";
        cin.clear();
        cin.ignore(10000, '\n'); 
        cin >> ligne;
    }

    // Demande de la colonne
    cout << "Entrez la colonne de votre attaque : ";
    cin >> colonne;

    // Vérification de la validité de la colonne
    while (cin.fail() || colonne < 0 || colonne > TAILLE_GRILLE - 1) {
        cout << "Entrée invalide. Veuillez réessayer : ";
        cin.clear();
        cin.ignore(10000, '\n'); 
        cin >> colonne;
    }

    return make_pair(ligne, colonne);
}

/**
* @brief Affiche un message de victoire.
*/
void CGui::afficheGagne() {
    cout << "╔════════════════════╗" << endl;
    cout << "║                    ║" << endl;
    cout << "║   Vous avez gagné  ║" << endl;
    cout << "║                    ║" << endl;
    cout << "╚════════════════════╝" << endl;
    
}

/**
* @brief Affiche un message de défaite.
*/
void CGui::affichePerdu() {
    cout << "╔════════════════════╗" << endl;
    cout << "║                    ║" << endl;
    cout << "║   Vous avez perdu  ║" << endl;
    cout << "║                    ║" << endl;
    cout << "╚════════════════════╝" << endl;
}

/**
* @brief Surcharge de l'opérateur de flux de sortie pour afficher l'objet CGui.
* @param os Le flux de sortie.
* @param theG L'objet CGui à afficher.
* @return Le flux de sortie mis à jour.
*/
ostream& operator<<(ostream& os, CGui& theG) {
    theG.remplirDeuxGrilles(os);
    return os;
}

/**
* @brief Remplit les deux grilles de jeu avec les bateaux et les coups joués.
* @param os Le flux de sortie.
*/
void CGui::remplirDeuxGrilles(ostream& os) {
    if(m_pArmada == NULL || m_pCoups == NULL) {
        throw invalid_argument("Erreur: m_pArmada et m_pCoups ne peuvent pas être nuls.");
    }
    if (os.fail()) {
        throw invalid_argument("Erreur: Le flux de sortie est invalide.");
    }
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            bool isO = false, isB = false, isX = false;

            // Remplissage des ploufs adverses
            for (int k = 0; k < m_pCoups->getTaille("ploufAdverse"); k++) {
                if (m_pCoups->getPair("ploufAdverse", k) == make_pair(i, j)) {
                    isO = true;
                    break;
                }
            }

            if (!isO) {
                for (int k = 0; k < m_pArmada->getEffectifTotal(); k++) {
                    // Remplissage des bateaux
                    for (int l = 0; l < m_pArmada->getBateau(k)->getTaille(); l++) {
                        if (m_pArmada->getBateau(k)->getPosition() == make_pair(i, j - l)) {
                            isB = true;

                            // Si le bateau est touché à cette position
                            if (m_pArmada->getBateau(k)->getDegats(l)) {
                                isX = true;
                            }
                            break;
                        }
                    }
                    if (isB) break;
                }
            }

            // Assignment des valeurs dans la grille joueur
            m_grilleJou[i][j] = isO ? 'O' : (isX ? 'X' : (isB ? 'B' : '-'));

            isO = false, isX = false;
            // Remplissage des ploufs du joueur
            for (int k = 0; k < m_pCoups->getTaille("dansLEau"); k++) {
                if (m_pCoups->getPair("dansLEau", k) == make_pair(i, j)) {
                    isO = true;
                    break;
                }
            }

            if (!isO) {
                // Remplissage des touches du joueur
                for (int k = 0; k < m_pCoups->getTaille("touche"); k++) {
                    if (m_pCoups->getPair("touche", k) == make_pair(i, j)) {
                        isX = true;
                        break;
                    }
                }
            }

            // Assignment des valeurs dans la grille adversaire
            m_grilleAdv[i][j] = isO ? 'o' : (isX ? 'X' : '-');
        }
    }

afficherLaGrille(os, "joueur");
afficherLaGrille(os, "adversaire");
}

/**
* @brief Affiche la grille de jeu spécifiée.
* @param os Le flux de sortie.
* @param jouOuAdv Indique si la grille à afficher est celle du joueur ou de l'adversaire.
*/
void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {
    if (jouOuAdv == "joueur") {
        cout << "Grille du joueur:" << endl;
    } else if (jouOuAdv == "adversaire") {
        cout << "Grille de l'adversaire:" << endl;
    } else {
        cout << "Erreur: jouOuAdv doit être 'joueur' ou 'adversaire'." << endl;
        throw invalid_argument("Erreur: jouOuAdv doit être 'joueur' ou 'adversaire'.");
    }

    if(m_pArmada == NULL || m_pCoups == NULL) {
        throw invalid_argument("Erreur: m_pArmada et m_pCoups ne peuvent pas être nuls.");
    }

    // Affichage de la légende horizontale
    cout << "  ";
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        // Affichage de la légende verticale
        cout << i << " ";

        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            // Affichage de la grille en fonction de jouOuAdv
            if (jouOuAdv == "joueur") {
                cout << m_grilleJou[i][j] << " ";
            } else {
                cout << m_grilleAdv[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
