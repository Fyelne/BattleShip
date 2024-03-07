#include "CArmada.h"
#include <cassert>

void testConstructeurDefaut() {
    // Test Cas Normal 1
    CArmada a;
    assert(a.getEffectifTotal() == 0);
    assert(a.getNbreTotCases() == 0);
    assert(a.getEffectif() == 0);
}

void testConstructeurCopie() {
    // Test Cas Normal 1
    CArmada a1;
    CArmada a2(a1);
    assert(a2.getEffectifTotal() == 0);
    assert(a2.getNbreTotCases() == 0);
    assert(a2.getEffectif() == 0);
    assert(a2.getEffectifTotal() == 0);

    // Test Cas Normal 2
    CBateau b1("bateau", make_pair(1, 1), 2);
    a1.ajouterBateau(b1);
    CArmada a3(a1);
    assert(a3.getEffectifTotal() == 1);
    assert(a3.getNbreTotCases() == 2);
    assert(a3.getEffectif() == 1);
    assert(a3.getEffectifTotal() == 1);
    
    // Test Cas Limite 1
    CBateau b2("bateau", make_pair(2, 2), 2);
    a1.ajouterBateau(b2);
    a1.getBateau(0)->tirAdverse(make_pair(1, 1));
    CArmada a4(a1);
    assert(a4.getEffectifTotal() == 2);
    assert(a4.getNbreTotCases() == 4);
    assert(a4.getEffectif() == 2);
    assert(a4.getEffectifTotal() == 2);

    // Test Cas Limite 2
    CBateau b3("bateau", make_pair(3, 3), 2);
    a1.ajouterBateau(b3);
    CArmada a5(a1);
    a5.getBateau(0)->tirAdverse(make_pair(1, 2));
    assert(a5.getEffectifTotal() == 3);
    assert(a5.getNbreTotCases() == 6);
    assert(a5.getEffectif() == 2);
    assert(a5.getEffectifTotal() == 3);
}

void testAjouterBateau() {
    // Test Cas Normal 1
    CArmada a;
    CBateau b("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b);
    assert(a.getEffectifTotal() == 1);
    assert(a.getNbreTotCases() == 2);
    assert(a.getEffectif() == 1);

    // Test Cas Limite 1
    CBateau b2("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b2);
    a.getBateau(0)->tirAdverse(make_pair(1, 1));
    assert(a.getEffectifTotal() == 2);
    assert(a.getNbreTotCases() == 4);
    assert(a.getEffectif() == 2);

    // Test Cas Limite 2
    CBateau b3("bateau", make_pair(2, 2), 2);
    a.ajouterBateau(b3);
    a.getBateau(0)->tirAdverse(make_pair(1, 2));
    assert(a.getEffectifTotal() == 3);
    assert(a.getNbreTotCases() == 6);
    assert(a.getEffectif() == 2);
}

void testGetBateau() {
    // Test Cas Normal 1
    CArmada a;
    CBateau b("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b);
    assert(a.getBateau(0)->getNom() == "bateau");
    assert(a.getBateau(0)->getTaille() == 2);
    assert(a.getBateau(0)->getPosition() == make_pair(1, 1));
    assert(a.getBateau(0)->getDegats(0) == false);
    assert(a.getBateau(0)->getDegats(1) == false);

    // Test Cas Normal 2
    CBateau b2("porte-avion", make_pair(1, 2), 3);
    a.ajouterBateau(b2);
    assert(a.getBateau(1)->getNom() == "porte-avion");
    assert(a.getBateau(1)->getTaille() == 3);
    assert(a.getBateau(1)->getPosition() == make_pair(1, 2));
    assert(a.getBateau(1)->getDegats(0) == false);
    assert(a.getBateau(1)->getDegats(1) == false);
    assert(a.getBateau(1)->getDegats(2) == false);
}

void testGetEffectifTotal() {
    // Test Cas Limite 1
    CArmada a;
    assert(a.getEffectifTotal() == 0);

    // Test Cas Normal 1
    CBateau b("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b);
    assert(a.getEffectifTotal() == 1);

    // Test Cas Normal 2
    CBateau b2("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b2);
    assert(a.getEffectifTotal() == 2);

    // Test Cas Normal 3
    CBateau b3("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b3);
    assert(a.getEffectifTotal() == 3);
}

void testGetNbreTotCases() {
    // Test Cas Limite 1
    CArmada a;
    assert(a.getNbreTotCases() == 0);

    // Test Cas Normal 1
    CBateau b("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b);
    assert(a.getNbreTotCases() == 2);

    // Test Cas Normal 2
    CBateau b2("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b2);
    assert(a.getNbreTotCases() == 4);

    // Test Cas Normal 3
    CBateau b3("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b3);
    assert(a.getNbreTotCases() == 6);
}

void testGetEffectif() {
    // Test Cas Limite 1
    CArmada a;
    assert(a.getEffectif() == 0);

    // Test Cas Normal 1
    CBateau b("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b);
    assert(a.getEffectif() == 1);

    // Test Cas Normal 2
    CBateau b2("bateau", make_pair(1, 1), 2);
    a.ajouterBateau(b2);
    assert(a.getEffectif() == 2);

    // Test Cas Normal 3
    a.getBateau(0)->tirAdverse(make_pair(1, 1));
    assert(a.getEffectif() == 2);

    // Test Cas Normal 4
    a.getBateau(0)->tirAdverse(make_pair(1, 2));
    assert(a.getEffectif() == 1);
}

void testGetArmadaFromFile() {
    // Test Cas Limite 1 (Test avec 1 porte-avion (Taille 4), 2 croiseurs (Taille 3), 2 torpilleur (Taille 2))
    CArmada a;
    a.getArmadaFromFile();
    assert(a.getEffectifTotal() == 5);
    assert(a.getNbreTotCases() == 14);
    assert(a.getEffectif() == 5);
}

void testPlacerAleatoirement() {
    // Test Cas Limite 1
    CArmada a;
    a.getArmadaFromFile();
    assert(a.placerAleatoirement() == true);
}

int main() {
    testConstructeurDefaut();
    testConstructeurCopie();
    testAjouterBateau();
    testGetBateau();
    testGetEffectifTotal();
    testGetNbreTotCases();
    testGetEffectif();
    testGetArmadaFromFile();
    testPlacerAleatoirement();

    cout << "Tous les tests de CArmada ont réussi." << endl;
    return 0;
}





