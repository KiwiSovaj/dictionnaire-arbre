/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier node.c : contient les fonctions permettant de créer des p_node_letter

*/
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

p_node_letter createNodeLetter(char letter)
{
    /// Cette fonction crée et initialise une p_node_letter et la retourne ensuite.

    p_node_letter node = (p_node_letter) malloc(sizeof(t_node_letter));
    node->letter = letter;
    node->nb_next_letters = 0;
    node->nb_spelling_forms = 0;
    node->spelling_forms = createEmptyList();

    return node;
}
