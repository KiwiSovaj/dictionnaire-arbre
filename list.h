//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_LIST_H
#define DICTIONNAIRE_ARBRE_LIST_H

#include "cell.h"
#include <stdio.h>

typedef struct s_ht_list
{
    p_cell head;
    p_cell tail;
} t_ht_list;

int findCharacter(t_ht_list, char);
t_ht_list createHTlist();
void addHeadHT(t_HT_list* list, char letter)
void addTailHT(t_HT_list* list, char letter);

#endif //DICTIONNAIRE_ARBRE_LIST_H
