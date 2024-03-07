#include "CArmada.h"

/**
* @brief Constructeur de copie de CArmada.
* @param original L'armada à copier.
*/
CArmada::CArmada(const CArmada& original) {
    for (CBateau bateau : original.m_listeBateaux) {
        m_listeBateaux.push_back(CBateau(bateau));
    }
}

/**
* @brief Ajoute un bateau à l'armada.
* @param unBat Le bateau à ajouter.
*/
void CArmada::ajouterBateau(CBateau& unBat) {
    m_listeBateaux.push_back(unBat);
}

/**
* @brief Récupère le bateau à l'indice spécifié.
* @param i L'indice du bateau.
* @return Un pointeur vers le bateau.
*/
CBateau* CArmada::getBateau(int i) {
    int size = m_listeBateaux.size();
    if (i >= 0 && i < size) {
        return &m_listeBateaux[i];
    }
    return NULL;
}

/**
* @brief Récupère l'effectif total de l'armada.
* @return L'effectif total de l'armada.
*/
int CArmada::getEffectifTotal() {
    int size = m_listeBateaux.size();
    return size;
}

/**
* @brief Récupère le nombre total de cases occupées par les bateaux de l'armada.
* @return Le nombre total de cases occupées.
*/
int CArmada::getNbreTotCases() {
    int totalCases = 0;
    for (CBateau& bateau : m_listeBateaux) {
        totalCases += bateau.getTaille();
    }
    return totalCases;
}

/**
* @brief Récupère l'effectif actuel de l'armada (bateaux coulés retirés).
* @return L'effectif actuel de l'armada.
*/
int CArmada::getEffectif() {
    int effectif = 0;
    for (CBateau& bateau : m_listeBateaux) {
        if (!bateau.estCoule()) {
            effectif++;
        }
    }
    return effectif;
}

/**
* @brief Charge les données de l'armada à partir d'un fichier (datas/flotilles.txt).
*/
void CArmada::getArmadaFromFile() {
    ifstream file("datas/flotille.txt"); // Ouvre le fichier en lecture
    if (!file.is_open()) {
        file.open("../datas/flotille.txt");
        if (!file.is_open()) {
            throw invalid_argument("Erreur: Impossible d'ouvrir le fichier flotille.txt.");
        }
    }

    string line;
    while (getline(file, line)) { // Lit le fichier ligne par ligne
        if (line.empty() || line[0] == '#') // Ignore les lignes vides et les commentaires
            continue;

        istringstream iss(line);
        string nom;
        int nombre_sur_grille, nombre_cases_horizontales;

        // Lit les données de la ligne
        if (!(iss >> nom >> nombre_sur_grille >> nombre_cases_horizontales)) {
            cerr << "Erreur: La ligne \"" << line << "\" n'est pas valide." << endl;
            cerr << "Le format attendu est: nom_du_bateau<ESPACE>nombre_sur_grille<ESPACE>nombre_cases_horizontales" << endl;
            continue;
        }

        // Ajoute les bateaux à l'armada
        for (int i = 0; i < nombre_sur_grille; i++) {
            CBateau bateau(nom, make_pair(0, 0), nombre_cases_horizontales);
            ajouterBateau(bateau);
        }
    }

    file.close(); // Ferme le fichier
}

/**
* @brief Place les bateaux de l'armada de manière aléatoire sur la grille.
* @return Vrai si les bateaux ont été placés avec succès, sinon faux.
*/
bool CArmada::placerAleatoirement() {
    vector<pair<int,int>> casesOccupees(TAILLE_GRILLE * TAILLE_GRILLE, make_pair(-1, -1));
    
    // Afin de ne pas avoir les mêmes emplacements de bateaux pour les 2 joueurs l'instruction suivante est commentée
    // srand( time(NULL) );

    // Pour chaque bateau, on essaie de le placer aléatoirement sur la grille
    for (CBateau& bateau : m_listeBateaux) {
        int essais = 0;
        bool bateauPlace = false;

        // On essaie de placer le bateau aléatoirement sur la grille avec un nombre maximum d'essais
        while (essais < MAXESSAIS && !bateauPlace) {
            int i = rand() % (TAILLE_GRILLE - 1);
            int j = rand() % (TAILLE_GRILLE - bateau.getTaille());

            bool caseOccupee = false;
            for (int k = 0; k < bateau.getTaille(); ++k) {
                // Si une des cases est déjà occupée, on arrête de placer le bateau
                if (casesOccupees[i * TAILLE_GRILLE + j + k] != make_pair(-1, -1)) {
                    caseOccupee = true;
                    break;
                }
            }

            // Si aucune des cases n'est occupée, on place le bateau
            if (!caseOccupee) {
                bateau.setPosition(i, j);
                for (int k = 0; k < bateau.getTaille(); ++k) {
                    casesOccupees[i * TAILLE_GRILLE + j + k] = make_pair(i, j + k);
                }
                bateauPlace = true;
            }
            ++essais;
        }

        if (!bateauPlace) {
            return false;
        }
    }
    return true;
}