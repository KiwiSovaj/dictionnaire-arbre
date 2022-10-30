//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_NODE_H
#define DICTIONNAIRE_ARBRE_NODE_H

#define NB_LETTER_MAX 37
// 26 letttre + â + à + é + è + ê + ë + ï + î + ô + ù + û + '-' (mots composés) = 38

struct s_node_letter
{
    char letter;
    int nb_next_letters;
    struct s_node_letter *next_letters[NB_LETTER_MAX];
    int nb_spelling_forms;
    char** spelling_forms;
};
typedef struct s_node_letter* p_node_letter;
typedef struct  s_node_letter t_node_letter;

p_node_letter createNodeLetter(char);
void displayNode(p_node_letter);

#endif //DICTIONNAIRE_ARBRE_NODE_H
