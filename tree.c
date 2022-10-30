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


void addWordTree_BaseForm(t_tree* t, char* word)  // marche seulement avec les base forms
{
    // printf("%s\n", word);
    int lenght = strlen(word);
    int index;
    p_node_letter tmp_node = t->root;
    for(int i=0 ; i<lenght ; i++)
    {
        if(tmp_node->nb_next_letters == 0)
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[0] = createNodeLetter(word[i]);
            tmp_node->nb_next_letters = 1;
            tmp_node = tmp_node->next_letters[0];
            continue;
        }
        index = 0;
        while(index < tmp_node->nb_next_letters && tmp_node->next_letters[index]->letter != word[i])
            index++;

        if(index < tmp_node->nb_next_letters) // si cette condition est vraie, alors on a trouvé la lettre dans la liste
        {
            // displayNode(tmp_node);
            tmp_node = tmp_node->next_letters[index];
            continue;
        }
        else  // sinon, ça veut dire qu'on n'a pas trouvé la lettre et qu'on doit lui créer une node
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(word[i]);
            tmp_node->nb_next_letters ++;
            tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
        }
    }
    // displayNode(tmp_node);
}

char* readRandomWord_BaseForm(t_tree* t)   // marche seulement avec les base forms
{
    char word[40] = "";
    int index = 0;
    p_node_letter tmp_node = t->root;

    while(tmp_node->nb_next_letters != 0)
    {
        index = rand()%tmp_node->nb_next_letters;
        tmp_node = tmp_node->next_letters[index];
        strncat(word, &(tmp_node->letter), 1);
    }

    return strdup(word);
}
