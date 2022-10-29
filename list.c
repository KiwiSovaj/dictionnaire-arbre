//
// Created by johan on 17/10/2022.
//

#include "list.h"
#include <stdlib.h>

int findCharacter(t_ht_list list, char c)
{
    p_cell tmp = list.head;
    while(tmp != NULL)
    {
        if(tmp->value->letter == c)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

t_ht_list createHTlist()
{
    t_ht_list list;
    list.head = list.tail = NULL;
    return list;
}

void addHeadHT(t_ht_list* list, char letter)
{
    p_cell newcell = createCell(createNodeLetter(letter));
    newcell->next = list->head;
    list->head = newcell;
}

void addTailHT(t_ht_list* list, char letter)
{
    p_cell newcell = createCell(createNodeLetter(letter));
    list->tail = newcell;
}