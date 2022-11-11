/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier cell.c : contient les fonctions permettant de créer ou d'afficher des p_cell

*/

#include "cell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

p_cell createCell(char* word, char* gender)
{
    /// Cette fonction permet de créer et d'initialiser une p_cell avec les informations données en entrée.
    /// La fonction retourne ensuite la p_cell créée.

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
