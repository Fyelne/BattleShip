# Avancement

Le projet est complet et peut être compilé avec le fichier makefile fourni. 
Le profil 'lanceurFinal' est le profil par défaut et permet de compiler tous les fichiers sources.

# Classes pouvant être compilées et testées

- `CArmada` avec `compilCArmada` : Classe représentant une armada de bateaux
    - `CArmadaTest` avec `compilCArmadaTest` : Classe de test pour `CArmada`
- `CBateau` avec `compilCBateau` : Classe représentant un bateau
    - `CBateauTest` avec `compilCBateauTest` : Classe de test pour `CBateau`
- `CGui` avec `compilCGui` : Classe représentant l'interface graphique
    - `CGuiTest` avec `compilCGuiTest` : Classe de test pour `CGui`

Les tests utilisent la bibliothèque `<cassert>` pour vérifier le bon fonctionnement des classes.
Ils contienent des tests unitaires pour chaque méthode des classes testées avec des cas normaux, limites et d'erreurs.

Toutes les autres classes peuvent être compilées en utilisant le makefile et les profils correspondants : `compil<Classe>`.
