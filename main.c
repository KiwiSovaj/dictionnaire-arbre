//
// Created by johan on 17/10/2022.
//
#include "reader.h"
#include "node.h"
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
    LINE line;
    dictionnary = fopen("dico_10_lignes.txt","r");

    t_tree t = createTree();

    while(fgets(chaine, TAILLE, dictionnary) != NULL)
    {
        line = extractFromString(dictionnary);
        addWordTree(&t, line.base_form);
    }

    fclose(dictionnary);

    return 0;
}


/*
    p_node_letter node1 = createNodeLetter('a');
    p_node_letter node2 = createNodeLetter('b');
    node1->nb_next_letters = 1;
    node1->next_letters[0] = node2;
    displayNode(node1);
 */