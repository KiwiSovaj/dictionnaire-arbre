//
// Created by Alexis on 19/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_READER_H
#define DICTIONNAIRE_ARBRE_READER_H
#include "string.h"
#include <stdio.h>
#define TAILLE 1000
#endif //DICTIONNAIRE_ARBRE_READER_H

typedef struct line{
    char* spelling_form;
    char* base_form;
    char* type;
    char* gender;
}LINE;

void createSubString(char*, char*, int, int);
LINE extractFromFile(FILE*);