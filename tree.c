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

void addWordTree(t_tree* t, char* word)
{
    int lenght = strlen(word);
    p_node_letter tmp_node = t->root;
    p_cell tmp_cell;
    for(int i=0 ; i<lenght ; i++)
    {
        if(tmp_node->next_letters == NULL)
        {
            tmp_node->next_letters = createHTlist();
        }
        tmp_cell = tmp_node->next_letters;
        while(tmp_cell != NULL && tmp_cell->value->letter != word[i])
        {
            tmp_cell = tmp_cell->next;
        }
        if(tmp_cell == NULL)
        {
            addTailHT(tmp_node->next_letters, word[i]);
            tmp_node = tmp_node->next_letters->tail;
        }
        else
        {
            tmp_node = tmp_cell->value;
        }
    }
}

// loop de parcours du fichier

/*
while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        LINE ligne = extractFromString(dictionnary);
        if(findCharacter(tree.root->next_letters, ligne.base_form[0]))
    }
 */