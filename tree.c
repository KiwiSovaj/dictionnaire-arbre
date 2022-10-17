//
// Created by johan on 17/10/2022.
//

#include "tree.h"
#include "node.h"

t_dict_tree createDictTree()
{
    t_dict_tree dict_tree;
    dict_tree.root = createNodeLetter('/');
    return dict_tree;
}