//
// Created by johan on 17/10/2022.
//

#include "list.h"

int findCharacter(t_ht_list* list, char c)
{
    p_cell tmp = list->head;
    while(tmp != NULL)
    {
        if(tmp->value == c)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}