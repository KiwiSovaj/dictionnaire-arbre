//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_TREE_H
#define DICTIONNAIRE_ARBRE_TREE_H

#include "list.h"
#include "node.h"

struct s_dict_tree
{
    p_node_letter root;
};
typedef struct s_dict_tree t_dict_tree;

t_dict_tree createDictTree();
void addWordTree(char*);

#endif //DICTIONNAIRE_ARBRE_TREE_H
