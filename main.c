//
// Created by johan on 17/10/2022.
//
#include "reader.h"
#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// version CMAKE alexis et cédric : 3.21.1
// version CMAKE johan : 3.23
// Pensez à changer la version dans la première ligne de CMakeLists.txt sinon ça marchera pas


int main()
{
    srand((unsigned)time(NULL));

    char chaine[TAILLE];

    FILE* dictionnary = NULL;
    LINE line;
    dictionnary = fopen("dictionnaire_non_accentue.txt","r");
    t_tree t_name = createTree();
    t_tree t_verbs = createTree();
    t_tree t_adj = createTree();
    t_tree t_adv = createTree();
    t_tree t_abr = createTree();
    t_tree t_pro = createTree();
    t_tree t_con = createTree();
    t_tree t_int = createTree();

    while(fgets(chaine, TAILLE, dictionnary) != NULL) // boucle de création des arbres
    {
        line = extractFromString(dictionnary);

        switch(line.type[2])   // on utilise dans les case la dernière lettre des types de mots, car elles sont toutes différentes
        {
            case 'm':  // noms
            {
                addWordTree_BaseForm(&t_name, line.base_form);
                break;
            }
            case 'j': // adjectifs
            {
                addWordTree_BaseForm(&t_adj, line.base_form);
                break;
            }
            case 'r': // verbes
            {
                addWordTree_BaseForm(&t_verbs, line.base_form);
                break;
            }
            case 'v': // adverbes
            {
                addWordTree_BaseForm(&t_adv, line.base_form);
                break;
            }
            case 'o': // pronoms
            {
                addWordTree_BaseForm(&t_pro, line.base_form);
                break;
            }
            case 'n': // conjonctions
            {
                addWordTree_BaseForm(&t_con, line.base_form);
                break;
            }
            case 't': // interjections
            {
                addWordTree_BaseForm(&t_int, line.base_form);
                break;
            }
            default:
                printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
        }

    }
    fclose(dictionnary);

    // phrase nom – adjectif – verbe – nom (base forms)
    printf("%s ", readRandomWord_BaseForm(&t_name));
    printf("%s ", readRandomWord_BaseForm(&t_adj));
    printf("%s ", readRandomWord_BaseForm(&t_verbs));
    printf("%s\n", readRandomWord_BaseForm(&t_name));
    // phrase nom – ‘qui’ – verbe – verbe – nom – adjectif (base forms)
    printf("%s qui ", readRandomWord_BaseForm(&t_name));
    printf("%s ", readRandomWord_BaseForm(&t_verbs));
    printf("%s ", readRandomWord_BaseForm(&t_verbs));
    printf("%s ", readRandomWord_BaseForm(&t_name));
    printf("%s\n", readRandomWord_BaseForm(&t_adj));

    return 0;
}

///////// Prévoir une manière de voir les fins de mots qui ont pas de spelling forms (prblm avec voir et voire par ex)
///////// (mettre une spelling form à chaque mot avec sa forme de base au pire)
///////// adapter ensuite la création du dico et la lecture de mots random à ce changement

///////// Dans la boucle qui lit, la première ligne du fichier se fait skip, et la dernière passe 2 fois --> pour alexis

// loop de parcours du fichier

/*
while(fgets(chaine, TAILLE, dictionnary) != NULL) {
        LINE ligne = extractFromString(dictionnary);
        if(findCharacter(tree.root->next_letters, ligne.base_form[0]))
    }
 */