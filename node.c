//
// Created by johan on 17/10/2022.
//

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

p_node_letter createNodeLetter(char letter)
{
    p_node_letter next_l[NB_LETTER_MAX];   // par sûr que yai besoin de définir ça vu que la structure crée une liste

    p_node_letter node = (p_node_letter) malloc(sizeof(p_node_letter));
    node->letter = letter;
    node->nb_next_letters = 0;

    node->spelling_forms = NULL;
    node->nb_spelling_forms = 0;
    return node;
}

void displayNode(p_node_letter pn)
{
    printf("letter : %c\n", pn->letter);
    printf("%d next letters :\n", pn->nb_next_letters);
    for(int i=0 ; i<pn->nb_next_letters ; i++)
        printf("%c ", pn->next_letters[i]->letter);
    printf("\n%d spelling forms :\n", pn->nb_spelling_forms);
    for(int i=0 ; i<pn->nb_spelling_forms ; i++)
        printf("%s ", pn->spelling_forms[i]);
    printf("\n");
}