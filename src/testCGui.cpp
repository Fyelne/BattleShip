#include <cassert>
#include "CGui.h"

void testConstructeurDefaut() {
    // Test Cas Normal 1
    try {
        CGui g;
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testConstructeur() {
    // Test Cas Normal 1
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testConstructeurCopie() {
    // Test Cas Normal 1
    CGui g1 = CGui(new CArmada(), new CCoups());
    try {
        CGui g2(g1);
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testRemplirDeuxGrilles() {
    // Test Cas Normal 1
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.remplirDeuxGrilles(cout);
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testAfficherLaGrille() {
    // Test Cas Normal 1
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.afficherLaGrille(cout, "joueur");
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Normal 2
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.afficherLaGrille(cout, "adversaire");
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Erreur 1 (Joueur invalide)
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.afficherLaGrille(cout, "toto");
        assert(false);
    } catch (...) {
        assert(true);
    }

    // Test Cas Erreur 2 (CCoups nul)
    try {
        CGui g = CGui(new CArmada(), NULL);
        g.afficherLaGrille(cout, "joueur");
        assert(false);
    } catch (...) {
        assert(true);
    }

    // Test Cas Erreur 3 (CArmada nul)
    try {
        CGui g = CGui(NULL, new CCoups());
        g.afficherLaGrille(cout, "joueur");
        assert(false);
    } catch (...) {
        assert(true);
    }
}

void testSetArmadaCoups() {
    // Test Cas Normal 1
    try {
        CGui g;
        g.setArmadaCoups(new CArmada(), new CCoups());
        assert(true);
    } catch (...) {
        assert(false);
    }
    // Test Cas Limite 1
    try {
        CGui g1 = CGui(new CArmada(), new CCoups());
        g1.setArmadaCoups(new CArmada(), new CCoups());
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Erreur 1 (CArmada nul)
    try {
        CGui g;
        g.setArmadaCoups(NULL, new CCoups());
        assert(false);
    } catch (...) {
        assert(true);
    }

    // Test Cas Erreur 2 (CCoups nul)
    try {
        CGui g;
        g.setArmadaCoups(new CArmada(), NULL);
        assert(false);
    } catch (...) {
        assert(true);
    }

    // Test Cas Erreur 3 (CArmada & CCoups nuls)
    try {
        CGui g;
        g.setArmadaCoups(NULL, NULL);
        assert(false);
    } catch (...) {
        assert(true);
    }
}

void testPositionnerBateaux() {
    // Test Cas Normal 1
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.positionnerBateaux();
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Erreur 1 (CArmada nul)
    try {
        CGui g;
        g.positionnerBateaux();
        assert(false);
    } catch (...) {
        assert(true);
    }
}

void testChoisirAttaque() {
    cout << "Test de choisirAttaque" << endl;
    cout << "Tests possibles : " << endl;
    cout << "1. Nombre invalide (charactères, vide) -> Erreur" << endl;
    cout << "2. Nombre invalide (négatif) -> Erreur" << endl;
    cout << "3. Nombre invalide (trop grand > TAILLE_GRILLE - 2) -> Erreur" << endl;
    cout << "4. Nombre invalide (trop petit < 0) -> Erreur" << endl;
    cout << "5. Nombre valide -> Succès" << endl;

    CGui g = CGui(new CArmada(), new CCoups());
    cout << "Coordonnées attaquées : " << g.choisirAttaque().first << ", " << g.choisirAttaque().second << endl;
}

void testAfficheGagne() {
    // Test Cas Normal 1
    try {
        CGui g;
        g.afficheGagne();
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testAffichePerdu() {
    // Test Cas Normal 1
    try {
        CGui g;
        g.affichePerdu();
        assert(true);
    } catch (...) {
        assert(false);
    }
}

void testOperateurAffich() {
    // Test Cas Normal 1
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        cout << g;
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Normal 2
    try {
        CGui g = CGui(new CArmada(), new CCoups());
        g.positionnerBateaux();
        cout << g;
        assert(true);
    } catch (...) {
        assert(false);
    }

    // Test Cas Erreur 1 (CArmada & CCoups nuls)
    try {
        CGui g;
        cout << g;
        assert(false);
    } catch (...) {
        assert(true);
    }
}

int main() {
    testConstructeurDefaut();
    testConstructeur();
    testConstructeurCopie();
    testRemplirDeuxGrilles();
    testSetArmadaCoups();
    testPositionnerBateaux();
    testChoisirAttaque();
    testAfficheGagne();
    testAffichePerdu();
    testOperateurAffich();

    cout << "Tous les tests de CGui ont réussi." << endl;
    return 0;
}