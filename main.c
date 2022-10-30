//
// Created by johan on 17/10/2022.
//
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
    srand((unsigned)time(NULL));

    char chaine[TAILLE];

    FILE* dictionnary = NULL;
    LINE line;
    dictionnary = fopen("dico_10_lignes.txt","r");
    t_tree t = createTree();

    while(fgets(chaine, TAILLE, dictionnary) != NULL) // boucle de création des arbres
    {
        printf("chaine : %s", chaine);
        line = extractFromString(dictionnary);
        printf("add %s / %s\n", line.base_form, line.spelling_form);
        addWordTree_BaseForm(&t, line.base_form);
    }

    fclose(dictionnary);

    for(int i=0 ; i<100 ; i++)
        printf("%d random word : %s\n", i, readRandomWord_BaseForm(&t));

    return 0;
}
//////////////// Différentier les verbes, complément, noms etc en 4 dicos ///////////////////////////////////////////

///////// Prévoir une manière de voir les fins de mots qui ont pas de spelling forms (prblm avec voir et voire par ex)
///////// (mettre une spelling form à chaque mot avec sa forme de base au pire)
///////// adapter ensuite la création du dico et la lecture de mots random à ce changement

//////// Dans la boucle qui lit, la première ligne du fichier se fait skip, et la dernière passe 2 fois

// loop de parcours du fichier

/*
while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        LINE ligne = extractFromString(dictionnary);
        if(findCharacter(tree.root->next_letters, ligne.base_form[0]))
    }
 */