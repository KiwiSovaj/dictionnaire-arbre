//
// Created by johan on 17/10/2022.
//
#include "reader.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* dictionnary = NULL;
    dictionnary = fopen("dictionnaire.txt","r");
    addWordTree(dictionnary);
    fclose(dictionnary);
    return 0;
}