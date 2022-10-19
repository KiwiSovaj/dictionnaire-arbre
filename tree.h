//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_TREE_H
#define DICTIONNAIRE_ARBRE_TREE_H

#include "list.h"
#include <stdio.h>

struct s_node_letter
{
    char letter;
    t_ht_list* next_letter;
    t_ht_list* spelling;
};
typedef struct s_node_letter* p_node_letter;


#endif //DICTIONNAIRE_ARBRE_TREE_H
