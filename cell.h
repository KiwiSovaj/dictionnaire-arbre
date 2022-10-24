//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_CELL_H
#define DICTIONNAIRE_ARBRE_CELL_H

#include "node.h"
struct s_cell
{
    p_node_letter value;
    struct s_cell *next;
};

typedef struct s_cell t_cell, *p_cell;

#endif //DICTIONNAIRE_ARBRE_CELL_H
