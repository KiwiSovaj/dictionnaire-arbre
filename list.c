//
// Created by johan on 09/11/2022.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_std_word_list createEmptyList()
{
    t_std_word_list list;
    list.head = NULL;
    return list;
}

void addHeadStd(t_std_word_list* list, char* word, char* gender)
{
    p_cell newcell = createCell(word, gender);
    newcell->next = list->head;
    list->head = newcell;
}

void displayStdWordList(t_std_word_list list)
{
    p_cell tmp = list.head;
    if(tmp == NULL)
    {
        printf("list [head @-]-->NULL\n");
    }
    else if(tmp->next == NULL)
    {
        printf("list [head @-]-->[ %s %s | @-]-->NULL\n", tmp->word, tmp->gender);
    }
    else
    {
        printf("list [head @-]-->");
        while(tmp->next != NULL)
        {
            printf("[ %s %s | @-]-->", tmp->word, tmp->gender);
            tmp = tmp->next;
        }
        printf("[ %s %s | @-]-->NULL\n", tmp->word, tmp->gender);
    }
}