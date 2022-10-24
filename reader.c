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

LINE extractFromString(FILE* dictionnary)
{
    LINE ligne;
    char spelling_form[TAILLE];
    char base_form[TAILLE];
    char type[TAILLE];
    char gender[TAILLE];
    char chaine[TAILLE];
    //while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        fscanf(dictionnary, "%s %s %s", spelling_form, base_form, gender);
        createSubString(gender, type, 0, 2);
        createSubString(gender, gender, 3, 0);
        ligne.spelling_form = spelling_form;
        ligne.base_form = base_form;
        ligne.type = type;
        ligne.gender = gender;
        //printf("%s\n",ligne.type);
    //}
    return ligne;
}
