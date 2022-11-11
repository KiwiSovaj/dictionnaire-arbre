/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier reader.c : contient les fonctions permettant de lire et de séparer les informations
contenues dans le fichier du dictionnaire

*/

#include "reader.h"

void createSubString(char *String, char *SubString, int from, int to)
{
    /// Cette fonction permet de placer dans une sous-chaîne de caractères une partie d'une autre chaîne de caractères.

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
    /// Cette fonction permet de lire une ligne du fichier donné en entrée et de la retourner.
    /// La structure retournée contient les informations séparées qui étaient contenues dans la ligne qui a été lue.

    LINE ligne;
    if (dictionnary != NULL) {
        char spelling_form[TAILLE];
        char base_form[TAILLE];
        char type[TAILLE];
        char gender[TAILLE];

        fscanf(dictionnary, "%s %s %s", spelling_form, base_form, gender);
        createSubString(gender, type, 0, 2);
        createSubString(gender, gender, 3, 0);
        ligne.spelling_form = spelling_form;
        ligne.base_form = base_form;
        ligne.type = type;
        ligne.gender = gender;

        return ligne;
    }
    else
        printf("ERROR : Cannot read the file !");
}
