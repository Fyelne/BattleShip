#include "CBateau.h"

/**
* @brief Constructeur par défaut de CBateau.
*/
CBateau::CBateau() {
    m_taille = 0;
    m_nom = "neant";
    m_position = make_pair(0, 0);
    m_pDegats = NULL;
}

/**
* @brief Constructeur de copie de CBateau.
* @param original Le bateau à copier.
*/
CBateau::CBateau(const CBateau& original) {
    m_taille = original.m_taille;
    m_nom = original.m_nom;
    m_position = original.m_position;

    // deep copy
    m_pDegats = new bool[m_taille];
    for (int i = 0; i < m_taille; i++) {
        m_pDegats[i] = original.m_pDegats[i];
    }
}

/**
* @brief Constructeur de CBateau.
* @param n Le nom du bateau.
* @param p La position du bateau.
* @param t La taille du bateau.
*/
CBateau::CBateau(string n, pair<int,int> p, int t) {
    if (t <= 0 || t > TAILLE_GRILLE) {
        throw invalid_argument("Taille doit être dans l'intervalle [1, TAILLE_GRILLE]");
    }
    if (p.first < 0 || p.first >= TAILLE_GRILLE || p.second < 0 || p.second >= TAILLE_GRILLE) {
        throw invalid_argument("Position invalide, p doit être dans l'intervalle [0, TAILLE_GRILLE-1]");
    }

    if (p.first + t > TAILLE_GRILLE) {
        throw invalid_argument("Le bateau ne peut pas être placé à cette position");
    }
    
    m_taille = t;
    m_nom = n;
    m_position = p;
    m_pDegats = new bool[m_taille];
    for (int i = 0; i < m_taille; i++) {
        m_pDegats[i] = false;
    }
}

/**
* @brief Obtient l'état des dégâts d'une case spécifique du bateau.
* @param i L'indice de la case.
* @return true si la case a subi des dégâts, false sinon.
*/
bool CBateau::getDegats(int i) {
    if (i >= 0 && i < m_taille) {
        return m_pDegats[i];
    }
    return false;
}

/**
* @brief Obtient le nom du bateau.
* @return Le nom du bateau.
*/
string CBateau::getNom() {
    return m_nom;
}

/**
* @brief Obtient la taille du bateau.
* @return La taille du bateau.
*/
int CBateau::getTaille() {
    return m_taille;
}

/**
* @brief Obtient la position du bateau.
* @return La position du bateau.
*/
pair<int,int> CBateau::getPosition() {
    return m_position;
}

/**
* @brief Définit la position du bateau.
* @param i Le numéro de la ligne horizontale.
* @param j Le numéro de la colonne verticale.
*/
void CBateau::setPosition(int i, int j) {
    if (i < 0 || i >= TAILLE_GRILLE || j < 0 || j >= TAILLE_GRILLE) {
        throw invalid_argument("Position invalide, p doit être dans l'intervalle [0, TAILLE_GRILLE-1]");
    }
    if (i + m_taille > TAILLE_GRILLE) {
        throw invalid_argument("Le bateau ne peut pas être placé à cette position");
    }
    m_position = make_pair(i, j);
}

/**
* @brief Vérifie si le bateau est coulé.
* @return true si le bateau est coulé, false sinon.
*/
bool CBateau::estCoule() {
    for (int i = 0; i < m_taille; i++) {
        if (!m_pDegats[i]) {
            return false;
        }
    }
    return true;
}

/**
* @brief Effectue un tir adverse sur le bateau.
* @param p Les coordonnées du tir adverse.
* @return true si le tir a touché le bateau, false sinon.
*/
bool CBateau::tirAdverse(pair<int,int> p) {
    // Si le tir est sur la même ligne que le bateau
    if (p.first == m_position.first) {
        int start = m_position.second;
        int end = m_position.second + m_taille;
        
        // Si le tir est sur une case du bateau
        if (p.second >= start && p.second < end) {
            int index = p.second - start;
            m_pDegats[index] = true;
            return true;
        }
    }
    return false;
}

/**
* @brief Surcharge de l'opérateur de flux de sortie pour afficher le bateau.
* @param os Le flux de sortie.
* @param theB Le bateau à afficher.
* @return Le flux de sortie mis à jour.
*/
ostream& operator<<(ostream& os, CBateau& theB) {
    os << "Nom: " << theB.m_nom << endl;
    os << "Taille: " << theB.m_taille << endl;
    os << "Position: (" << theB.m_position.first << ", " << theB.m_position.second << ")" << endl;
    os << "Degats: ";
    for (int i = 0; i < theB.m_taille; i++) {
        os << (theB.m_pDegats[i] ? "X" : "-") << " ";
    }
    os << endl;
    return os;
}

/**
* @brief Surcharge de l'opérateur d'affectation pour copier un bateau.
* @param theB Le bateau à copier.
* @return Une référence vers le bateau copié.
*/
CBateau& CBateau::operator=(CBateau& theB) {
    if (this != &theB) {
        m_taille = theB.m_taille;
        m_nom = theB.m_nom;
        m_position = theB.m_position;
        m_pDegats = new bool[m_taille];
        for (int i = 0; i < m_taille; i++) {
            m_pDegats[i] = theB.m_pDegats[i];
        }
    }
    return *this;
}