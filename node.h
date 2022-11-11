/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier node.h : fichier en-tête de node.c

*/

#ifndef DICTIONNAIRE_ARBRE_NODE_H
#define DICTIONNAIRE_ARBRE_NODE_H

#include "list.h"

#define NB_LETTER_MAX 37
// 26 letttres + â + à + é + è + ê + ë + ï + î + ô + ù + û + '-' (mots composés) = 38

struct s_node_letter
{
    char letter;
    int nb_next_letters;
    struct s_node_letter *next_letters[NB_LETTER_MAX];
    int nb_spelling_forms;
    t_std_word_list spelling_forms;
};
typedef struct s_node_letter* p_node_letter;
typedef struct  s_node_letter t_node_letter;

p_node_letter createNodeLetter(char letter);

#endif //DICTIONNAIRE_ARBRE_NODE_H
