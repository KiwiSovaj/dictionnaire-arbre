//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_LIST_H
#define DICTIONNAIRE_ARBRE_LIST_H

#include "cell.h"
#include <stdio.h>

struct s_ht_list
{
    p_cell head;
    p_cell tail;
};
typedef struct s_ht_list t_ht_list;

int findCharacter(t_ht_list, char);
t_ht_list createHTlist();
void addHeadHT(t_ht_list* list, char letter);
void addTailHT(t_ht_list* list, char letter);

#endif //DICTIONNAIRE_ARBRE_LIST_H
