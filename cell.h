/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier cell.h : fichier en-tête de cell.c

*/

#ifndef DICTIONNAIRE_ARBRE_CELL_H
#define DICTIONNAIRE_ARBRE_CELL_H

struct s_cell
{
    char* word;
    char* gender;
    struct s_cell *next;
};
typedef struct s_cell t_cell, *p_cell;

p_cell createCell(char* word, char* gender);
void displayCell(p_cell c);

#endif //DICTIONNAIRE_ARBRE_CELL_H
