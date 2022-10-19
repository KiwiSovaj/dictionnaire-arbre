//
// Created by johan on 17/10/2022.
//
#include "tree.h"
#include "reader.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* dictionnary = NULL;
    dictionnary = fopen("dictionnaire.txt","r");
    extractFromFile(dictionnary);
    fclose(dictionnary);
    return 0;
}