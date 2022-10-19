//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_TREE_H
#define DICTIONNAIRE_ARBRE_TREE_H

#include "list.h"
#include "node.h"

struct s_tree
{
    p_node_letter root;
};
typedef struct s_tree t_tree;

t_tree createTree();
void addWordTree(char*);

#endif //DICTIONNAIRE_ARBRE_TREE_H
