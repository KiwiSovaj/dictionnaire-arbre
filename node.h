//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_NODE_H
#define DICTIONNAIRE_ARBRE_NODE_H

#include "list.h"

struct s_node_letter
{
    char letter;
    t_ht_list* next_letters;
    t_ht_list* spelling_forms;
    int nb_spelling_forms;
};
typedef struct s_node_letter* p_node_letter;

p_node_letter createNodeLetter(char);

#endif //DICTIONNAIRE_ARBRE_NODE_H
