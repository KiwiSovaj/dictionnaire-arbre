/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier main.c : permet de lancer la boucle principale du programme

*/

#include "reader.h"
#include "node.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// version CMAKE alexis et cédric : 3.21.1
// version CMAKE johan : 3.23
// Pensez à changer la version dans la première ligne de CMakeLists.txt sinon cela ne marchera pas

/// Attention !! Pour que le programme fonctionne, le fichier txt du dictionnaire doit respecter ces 2 conditions :
/// 1: Il doit y avoir une ligne vide au début du fichier
/// 2: Il ne doit pas y avoir de retour à la ligne à la fin du fichier
/// Si ces conditions ne sont pas respectées, le programme ne fonctionnera pas.

int main()
{
    // Initialisation de l'aléatoire
    srand((unsigned)time(NULL));

    char chaine;
    FILE* dictionnary = NULL;
    LINE line;
    // attention le fichier à ouvrir doit se trouver dans le dossier cmake-build-debug
    dictionnary = fopen("dictionnaire_non_accentue.txt","r");

    // création des différents arbres
    t_tree t_name = createTree();
    t_tree t_verbs = createTree();
    t_tree t_adj = createTree();
    t_tree t_adv = createTree();
    t_tree t_abr = createTree();
    t_tree t_pro = createTree();
    t_tree t_con = createTree();
    t_tree t_int = createTree();
    t_tree t_pre = createTree();
    t_tree t_det = createTree();

    t_tree tree_list[10] = {t_name, t_verbs, t_adj, t_adv, t_abr, t_pro, t_con, t_int, t_pre, t_det};

    printf("Construction des arbres a partir du dictionnaire...\n");

    // boucle de lecture du fichier et de remplissage des arbres
    while((chaine=fgetc(dictionnary))!=EOF)
    {
        line = extractFromString(dictionnary);
        findAndAddTree_SpellingForm(line, &t_name, &t_adj, &t_verbs, &t_adv, &t_abr, &t_pro, &t_con, &t_int, &t_pre, &t_det);
    }

    printf("Construction des arbres terminee !\n");

    int choice, index;
    char word[40];

    do{
        printf("\n\nQue voulez-vous faire ?\n"
               "0- Quitter\n"
               "1- Chercher un mot parmi les formes de base\n"
               "2- Extraire une forme de base au hasard\n"
               "3- Generer une phrase avec des formes de base\n"
               "4- Chercher un mot parmi les formes flechies, ainsi que ses informations\n"
               "5- Generer une phrase avec des formes flechies\n");
        do {
            printf(">>> ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 5);

        switch(choice)
        {
            case 1:{  // recherche d'une forme de base
                printf("Saisissez la forme de base a chercher : ");
                scanf("%s", word);
                printf("Dans quel dictionnaire voulez-vous chercher le mot ?\n"
                       "1- Noms              6- Pronoms\n"
                       "2- Verbes            7- Conjonctions\n"
                       "3- Adjectifs         8- Interjections\n"
                       "4- Adverbes          9- Prepositions\n"
                       "5- Abreviations      10- Determinants\n");
                do {
                    printf(">>> ");
                    scanf("%d", &index);
                } while (index < 0 || index > 10);

                if(isWordInTree_BaseForm(tree_list[index-1], word))
                    printf("Le mot a ete trouve dans l'arbre");
                else
                    printf("Le mot n'a pas ete trouve dans l'arbre");
                break;
            }
            case 2:{  // choix d'une forme de base au hasard
                index = rand()%10;
                printf("%s", readRandomWord_BaseForm(tree_list[index]));
                break;
            }
            case 3:{  // generation d'une phrase avec les formes de base
                randomSentences_BaseForm(t_name, t_adj, t_verbs, t_adv);
                break;
            }
            case 4:{  // recherche d'une forme flechie
                printf("saisissez la forme flechie a chercher : ");
                scanf("%s", word);
                searchSpellingInTrees(word,t_name, t_adj, t_verbs, t_adv, t_abr, t_pro, t_con, t_int, t_pre, t_det);
                break;
            }
            case 5:{  // generation d'une phrase avec des formes flechies
                randomSentences_SpellingForm(t_name, t_adj, t_verbs, t_adv);
                break;
            }
            default:
                break;
        }

    }while(choice !=0);

    return 0;
}

