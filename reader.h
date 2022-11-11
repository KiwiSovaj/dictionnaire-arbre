/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier reader.h : fichier en-tête de reader.c

*/

#ifndef DICTIONNAIRE_ARBRE_READER_H
#define DICTIONNAIRE_ARBRE_READER_H

#include "string.h"
#include <stdio.h>
#define TAILLE 10000

typedef struct{
    char* spelling_form;
    char* base_form;
    char* type;
    char* gender;
} LINE;

void createSubString(char* string, char* substring, int from, int to);
LINE extractFromString(FILE*);

#endif //DICTIONNAIRE_ARBRE_READER_H

