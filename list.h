//
// Created by johan on 09/11/2022.
//

#ifndef DICTIONNAIRE_ARBRE_LIST_H
#define DICTIONNAIRE_ARBRE_LIST_H

#include "cell.h"

struct s_std_word_list
{
    p_cell head;
};
typedef struct s_std_word_list t_std_word_list;

t_std_word_list createEmptyList();
void addHeadStd(t_std_word_list* list, char* word, char* gender);
void displayStdWordList(t_std_word_list list);

#endif //DICTIONNAIRE_ARBRE_LIST_H
