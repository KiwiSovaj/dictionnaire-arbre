//
// Created by johan on 17/10/2022.
//
#include "tree.h"

FILE* dictionnary = NULL;
dictionnary = fopen("dictionnaire.txt","r");
extractFromFile(dictionnary);
fclose(dictionnary);

