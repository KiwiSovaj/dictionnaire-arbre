//
// Created by johan on 17/10/2022.
//

#include "node.h"
#include "stdlib.h"

p_node_letter createNodeLetter(char letter)
{
    p_node_letter node = (p_node_letter) malloc(sizeof(p_node_letter));
    node->letter = letter;
    node->next_letters = NULL;
    node->spelling_forms = NULL;
    node->nb_spelling_forms = 0;
    return node;
}