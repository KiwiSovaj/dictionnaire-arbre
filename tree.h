//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_TREE_H
#define DICTIONNAIRE_ARBRE_TREE_H

#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s_tree
{
    p_node_letter root;
};
typedef struct s_tree t_tree;

t_tree createTree();
void addWordTree_BaseForm(t_tree*, char* word);
char* readRandomWord_BaseForm(t_tree*);

#endif //DICTIONNAIRE_ARBRE_TREE_H
