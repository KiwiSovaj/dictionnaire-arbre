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
    for(int i=0 ; i<lenght ; i++)
    {
        for(int k=0 ; k<tmp_node->nb_next_letters ; k++)
        {
            if(tmp_node->next_letters[k]->letter == word[i])
            {
                displayNode(tmp_node);   //////////////////
                tmp_node = tmp_node->next_letters[k];
                continue;
            }
            else
            {
                displayNode(tmp_node); ///////////////
                tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(word[i]);
                tmp_node->nb_next_letters ++;
                tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
            }
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