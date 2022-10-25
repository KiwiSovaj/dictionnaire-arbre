//
// Created by johan on 17/10/2022.
//

#include "cell.h"
#include <stdlib.h>

p_cell createCell(p_node_letter)
{
    p_cell newcell = (p_cell) malloc(sizeof(p_cell));
    newcell->value = p_node_letter;
    newcell->next = NULL;
}
