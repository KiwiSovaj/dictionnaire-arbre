//
// Created by johan on 17/10/2022.
//

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

p_node_letter createNodeLetter(char letter)
{
    /// Cette fonction crée et initialise une p_node_letter et la retourne ensuite.

    p_node_letter node = (p_node_letter) malloc(sizeof(t_node_letter));
    node->letter = letter;
    node->nb_next_letters = 0;
    node->nb_spelling_forms = 0;
    node->spelling_forms = createEmptyList();

    return node;
}

void displayNode(p_node_letter pn)
{
    /// Cette fonction affiche le contenu d'une p_node_letter.

    printf("letter : %c\n", pn->letter);
    printf("%d next letters :\n", pn->nb_next_letters);
    for(int i=0 ; i<pn->nb_next_letters ; i++)
        printf("%c ", pn->next_letters[i]->letter);
    printf("\nil y a %d spelling forms :\n", pn->nb_spelling_forms);
}