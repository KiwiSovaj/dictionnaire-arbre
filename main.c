//
// Created by johan on 17/10/2022.
//
#include "reader.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


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