#include "CBateau.h"
#include <cassert>

void testConstructeurDefaut() {
    // Test Cas Normal 1
    CBateau b;
    assert(b.getNom() == "neant");
    assert(b.getTaille() == 0);
    assert(b.getPosition() == make_pair(0, 0));
    assert(b.getDegats(0) == false);
}

void testConstructeurCopie() {
    // Test Cas Normal 1
    CBateau b1;
    CBateau b2(b1);
    assert(b2.getNom() == "neant");
    assert(b2.getTaille() == 0);
    assert(b2.getPosition() == make_pair(0, 0));
    assert(b2.getDegats(0) == false);

    // Test Cas Normal 2
    CBateau b3("bateau", make_pair(1, 1), 2);
    CBateau b4(b3);
    assert(b4.getNom() == "bateau");
    assert(b4.getTaille() == 2);
    assert(b4.getPosition() == make_pair(1, 1));
    assert(b4.getDegats(0) == false);
    assert(b4.getDegats(1) == false);

    // Test Cas Limite 1
    CBateau b5("bateau", make_pair(1, 1), 2);
    b5.tirAdverse(make_pair(1, 1));
    CBateau b6(b5);
    assert(b6.getNom() == "bateau");
    assert(b6.getTaille() == 2);
    assert(b6.getPosition() == make_pair(1, 1));
    assert(b6.getDegats(0) == true);
    assert(b6.getDegats(1) == false);

    // Test Cas Limite 2
    CBateau b7("bateau", make_pair(1, 1), 2);
    b7.tirAdverse(make_pair(1, 1));
    b7.tirAdverse(make_pair(1, 2));
    CBateau b8(b7);
    assert(b8.getNom() == "bateau");
    assert(b8.getTaille() == 2);
    assert(b8.getPosition() == make_pair(1, 1));
    assert(b8.getDegats(0) == true);
    assert(b8.getDegats(1) == true);
}

void testConstructeurParam() {
    // Test Cas Normal 1
    CBateau b1("bateau", make_pair(1, 1), 2);
    assert(b1.getNom() == "bateau");
    assert(b1.getTaille() == 2);
    assert(b1.getPosition() == make_pair(1, 1));
    assert(b1.getDegats(0) == false);
    assert(b1.getDegats(1) == false);

    // Test Cas Limite 1
    CBateau b2("bateau", make_pair(1, 1), 2);
    b2.tirAdverse(make_pair(1, 1));
    assert(b2.getNom() == "bateau");
    assert(b2.getTaille() == 2);
    assert(b2.getPosition() == make_pair(1, 1));
    assert(b2.getDegats(0) == true);
    assert(b2.getDegats(1) == false);

    // Test Cas Limite 2
    CBateau b3("bateau", make_pair(1, 1), 2);
    b3.tirAdverse(make_pair(1, 1));
    b3.tirAdverse(make_pair(1, 2));
    assert(b3.getNom() == "bateau");
    assert(b3.getTaille() == 2);
    assert(b3.getPosition() == make_pair(1, 1));
    assert(b3.getDegats(0) == true);
    assert(b3.getDegats(1) == true);

    // Test Cas Erreur 1 (Taille <= 0)
    try {
        CBateau b4("bateau", make_pair(1, 1), 0);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }

    // Test Cas Erreur 2 (Taille > TAILLE_GRILLE)
    try {
        CBateau b5("bateau", make_pair(1, 1), 15);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }

    // Test Cas Erreur 3 (Position invalide)
    try {
        CBateau b6("bateau", make_pair(100, 100), 4);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }

    // Test Cas Erreur 4 (Le bateau ne peut pas être placé à cette position)
    try {
        CBateau b7("bateau", make_pair(8, 8), 8);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }
}

void testGetDegats() {
    // Test Cas Normal 1
    CBateau b1("bateau", make_pair(1, 1), 2);
    assert(b1.getDegats(0) == false);
    assert(b1.getDegats(1) == false);

    // Test Cas Limite 1
    CBateau b2("bateau", make_pair(1, 1), 2);
    b2.tirAdverse(make_pair(1, 1));
    assert(b2.getDegats(0) == true);
    assert(b2.getDegats(1) == false);

    // Test Cas Limite 2
    CBateau b3("bateau", make_pair(1, 1), 2);
    b3.tirAdverse(make_pair(1, 1));
    b3.tirAdverse(make_pair(1, 2));
    assert(b3.getDegats(0) == true);
    assert(b3.getDegats(1) == true);

    // Test Cas Limite 3
    CBateau b4("bateau", make_pair(1, 1), 2);
    assert(b4.getDegats(2) == false);

    // Test Cas Limite 4
    CBateau b5("bateau", make_pair(1, 1), 2);
    b5.tirAdverse(make_pair(1, 1));
    b5.tirAdverse(make_pair(1, 1));
    assert(b5.getDegats(0) == true);
}

void testGetNom() {
    // Test Cas Normal 1
    CBateau b1("bateau", make_pair(1, 1), 2);
    assert(b1.getNom() == "bateau");
}

void testGetTaille() {
    // Test Cas Normal 1
    CBateau b1("bateau", make_pair(1, 1), 2);
    assert(b1.getTaille() == 2);
}

void testGetPosition() {
    // Test Cas Normal 1
    CBateau b1("bateau", make_pair(1, 1), 2);
    assert(b1.getPosition() == make_pair(1, 1));
}

int main() {
    cout << "Test de CBateau" << endl;

    testConstructeurDefaut();
    testConstructeurCopie();
    testConstructeurParam();
    testGetDegats();
    testGetNom();
    testGetTaille();
    testGetPosition();

    cout << "Tous les tests de CBateau ont réussi" << endl;
    return 0;
}
