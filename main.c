
#include "reader.h"
#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// version CMAKE alexis et cédric : 3.21.1
// version CMAKE johan : 3.23
// Pensez à changer la version dans la première ligne de CMakeLists.txt sinon ça marchera pas


int main()
{
    // Initialisation de l'aléatoire
    srand((unsigned)time(NULL));

    char chaine[TAILLE];
    FILE* dictionnary = NULL;
    LINE line;
    // attention le fichier à ouvrir doit se trouver dans le dossier cmake-build-debug
    dictionnary = fopen("dico_10_lignes.txt","r");

    // création des différents arbres
    t_tree t_name = createTree();
    t_tree t_verbs = createTree();
    t_tree t_adj = createTree();
    t_tree t_adv = createTree();
    t_tree t_abr = createTree();
    t_tree t_pro = createTree();
    t_tree t_con = createTree();
    t_tree t_int = createTree();
    t_tree t_pre = createTree();

    // boucle de lecture du fichier et de remplissage des arbres

    /*
    while(fgets(chaine, TAILLE, dictionnary) != NULL) // boucle de création des arbres
    {
        line = extractFromString(dictionnary);
        findAndAddTree_BaseForm(line, &t_name, &t_adj, &t_verbs, &t_adv, &t_abr, &t_pro, &t_con, &t_int, &t_pre);
    }
    fclose(dictionnary);
     */

    while(fgets(chaine, TAILLE, dictionnary) != NULL) // boucle de création des arbres
    {
        line = extractFromString(dictionnary);
        findAndAddTree_SpellingForm(line, &t_name, &t_adj, &t_verbs, &t_adv, &t_abr, &t_pro, &t_con, &t_int, &t_pre);
    }

    // création de phrases aléatoires
    randomSentences_BaseForm(t_name, t_adj, t_verbs, t_adv);

    // Test de la fonction de recherche
    printf("%d\n", isWordInTree_BaseForm(t_name, "stabilimetre"));
    isWordInTree_BaseForm(t_verbs, "stabiliser");

    return 0;
}

///////////////////////////////////////////// A FAIRE //////////////////////////////////////////////////

/// Intégrer les spelling forms
/// adapter ensuite la création du dico et la lecture de mots random à ce changement

/// Faire la recherche de mots avec les spelling forms ensuite

/// Dans la boucle qui lit, la première ligne du fichier se fait skip, et la dernière passe 2 fois --> pour alexis

///////////////////////////////////////////////////////////////////////////////////////////////////////
