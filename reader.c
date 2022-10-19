//
// Created by Alexis on 19/10/2022.
//

#include "reader.h"

void createSubString(char *String, char *SubString, int from, int to)
{
    int lenght = strlen(String);
    if (to==0)
    {
        for (int i=from , j=0 ; i<=lenght ; i++ , j++)
            SubString[j]=String[i];
    }
    else
    {
        for (int i=from , j=0 ; i<=to ; i++ , j++)
            SubString[j]=String[i];
    }
}

LINE extractFromFile(FILE* dictionnary)
{
    LINE line;
    if (dictionnary != NULL)
    {
        char spelling_form[TAILLE];
        char base_form[TAILLE];
        char type[TAILLE];
        char gender[TAILLE];
        fscanf(dictionnary, "%s %s %s", spelling_form, base_form, gender);
        createSubString(gender, type, 0, 2);
        createSubString(gender, gender, 3, 0);
        line.spelling_form = spelling_form;
        line.base_form = base_form;
        line.type = type;
        line.gender = gender;
        return line;
    }
    else
        printf("ERROR : On ne peut pas lire le fichier");
}