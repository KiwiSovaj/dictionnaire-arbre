/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier list.c : contient toutes les fonctions permettant de créer, modifier ou afficher des t_std_word_list

*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_std_word_list createEmptyList()
{
    /// Cette fonction permet de créer et d'initialiser une t_std_word_list vide. Elle la retourne ensuite.

    t_std_word_list list;
    list.head = NULL;
    return list;
}

void addHeadStd(t_std_word_list* list, char* word, char* gender)
{
    /// Cette fonction permet d'ajouter une cellule contenant les informations données en argument
    /// en tête d'une t_std_word_list.

    p_cell newcell = createCell(word, gender);
    newcell->next = list->head;
    list->head = newcell;
}

void displayStdWordList(t_std_word_list list)
{
    /// Cette fonction permet d'afficher une t_std_word_list.

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