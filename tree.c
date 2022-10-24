//
// Created by johan on 17/10/2022.
//
#include "tree.h"

t_tree createTree()
{
    t_tree tree;
    tree.root = createNodeLetter('/');
    return tree;
}

void addWordTree(FILE* dictionnary)
{
    char chaine[TAILLE];
    t_tree tree = createTree();
    while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        LINE ligne = extractFromString(dictionnary);
        if(findCharacter(tree.root->next_letters->,ligne.base_form[0])
    }
}