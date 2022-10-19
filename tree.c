//
// Created by johan on 17/10/2022.
//
#include "tree.h"
#include "node.h"

t_tree createTree()
{
    t_tree tree;
    tree.root = createNodeLetter('/');
    return tree;
}
