//
// Created by johan on 17/10/2022.
//

#ifndef DICTIONNAIRE_ARBRE_TREE_H
#define DICTIONNAIRE_ARBRE_TREE_H

#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reader.h"
#include "list.h"

struct s_tree
{
    p_node_letter root;
};
typedef struct s_tree t_tree;

t_tree createTree();
void addWordTree_BaseForm(t_tree* p_tree, char* word);
void findAndAddTree_BaseForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                       t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre, t_tree *t_det);
char* readRandomWord_BaseForm(t_tree p_tree);
int isWordInTree_BaseForm(t_tree tree, char* word);
void randomSentences_BaseForm(t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv);

void addWordTree_SpellingForm(t_tree* t, char*base_form, char* word, char* gender);
void findAndAddTree_SpellingForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                                 t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre, t_tree *t_det);
char* readRandomWord_SpellingForms(t_tree t, char* gender);
void randomSentences_SpellingForm(t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv);
int searchSpellingInTree(char* spelling_form, p_node_letter node, char* buffer, char* type);
void printGender(char* gender, char* type);
void searchSpellingInTrees(char* spelling_form, t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv, t_tree t_abr,
                           t_tree t_pro, t_tree t_con, t_tree t_int, t_tree t_pre, t_tree t_det);

#endif //DICTIONNAIRE_ARBRE_TREE_H
