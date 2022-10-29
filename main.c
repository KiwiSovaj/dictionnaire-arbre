//
// Created by johan on 17/10/2022.
//
#include "reader.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// version CMAKE alexis et cédric : 3.21.1
// version CMAKE johan : 3.23
// Pensez à changer la version dans la première ligne de CMakeLists.txt sinon ça marchera pas


int main()
{
    char chaine[TAILLE];

    FILE* dictionnary = NULL;
    dictionnary = fopen("dictionnaire.txt","r");

    t_tree t = createTree();

    while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        LINE ligne = extractFromString(dictionnary);
        addWordTree(&t, ligne.base_form);
    }

    fclose(dictionnary);
    return 0;
}