//
// Created by johan on 09/11/2022.
//

#include "cell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

p_cell createCell(char* word, char* gender)
{
    p_cell new_cell;

    new_cell = (p_cell) malloc(sizeof(t_cell));

    new_cell->word = strdup(word);
    new_cell->gender = strdup(gender);
    new_cell->next = NULL;
    return new_cell;
}

void displayCell(p_cell c)
{
    printf("word : %s    type : %s\n", c->word, c->gender);
}
