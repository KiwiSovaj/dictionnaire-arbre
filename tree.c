//
// Created by johan on 17/10/2022.
//
#include "tree.h"

t_tree createTree()
{
    /// Cette fonction crée un arbre n-aire et l'initialise. Elle le retourne ensuite
    t_tree tree;
    tree.root = createNodeLetter('/');
    return tree;
}

void addWordTree_BaseForm(t_tree* t, char* word)
{
    /// Cette fonction ajoute un mot dans un arbre n-aire donné.
    /// Cette fonction ne prend en charge que les formes de base

    // printf("%s\n", word);
    int lenght = strlen(word);
    int index;
    p_node_letter tmp_node = t->root;
    for(int i=0 ; i<lenght ; i++)   // On va placer les lettres du mot une par une
    {
        if(tmp_node->nb_next_letters == 0)  // si la node courante n'a pas de lettre suivante, on en ajoute une
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[0] = createNodeLetter(word[i]);
            tmp_node->nb_next_letters = 1;
            tmp_node = tmp_node->next_letters[0];
            continue;
        }
        index = 0;
        while(index < tmp_node->nb_next_letters && tmp_node->next_letters[index]->letter != word[i]) // on cherche si la lettre est déjà dans la node courante
            index++;

        if(index < tmp_node->nb_next_letters) // si cette condition est vraie, alors on a trouvé la lettre dans la liste
        {
            // displayNode(tmp_node);
            tmp_node = tmp_node->next_letters[index];
            continue;
        }
        else  // sinon, cela signifie qu'on n'a pas trouvé la lettre et qu'on doit lui créer une node
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(word[i]);
            tmp_node->nb_next_letters ++;
            tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
        }
    }
    // displayNode(tmp_node);
}

void findAndAddTree_BaseForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                       t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre)
{
    /// Cette fonction cherche dans quel arbre doit aller le mot qu'on lui donne, et lance ensuite la fonction
    /// permettant d'ajouter le mot dans l'arbre adapté. Ne fonctionne qu'avec les formes de base

    switch(line.type[2])   // on utilise dans les case la dernière lettre des types de mots pour identifier le dictionnaire, car elles sont toutes différentes sauf dans un cas
    {
        case 'm':  // noms
        {
            addWordTree_BaseForm(t_name, line.base_form);
            break;
        }
        case 'j': // adjectifs
        {
            addWordTree_BaseForm(t_adj, line.base_form);
            break;
        }
        case 'r': // verbes et abréviations
        {
            if(line.type[0] == 'V')  // verbes
                addWordTree_BaseForm(t_verbs, line.base_form);
            else if(line.type[0] == 'A')  // abréviations
                addWordTree_BaseForm(t_abr, line.base_form);
            else
                printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
            break;
        }
        case 'v': // adverbes
        {
            addWordTree_BaseForm(t_adv, line.base_form);
            break;
        }
        case 'o': // pronoms
        {
            addWordTree_BaseForm(t_pro, line.base_form);
            break;
        }
        case 'n': // conjonctions
        {
            addWordTree_BaseForm(t_con, line.base_form);
            break;
        }
        case 't': // interjections
        {
            addWordTree_BaseForm(t_int, line.base_form);
            break;
        }
        case 'e':  // prepositions
        {
            addWordTree_BaseForm(t_pre, line.base_form);
            break;
        }
        default: // type inconnu
            printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
    }
}

char* readRandomWord_BaseForm(t_tree t)
{
    /// Cette fonction retourne un mot aléatoire qu'elle prend dans l'arbre qu'on lui donne.
    /// La fonction ne prend en charge que les formes de base

    char word[40] = "";
    int index = 0;
    p_node_letter tmp_node = t.root;

    while(tmp_node->nb_next_letters != 0)  // Tant qu'on n'est pas sur une feuille on continue à prendre des lettres
    {
        index = rand()%tmp_node->nb_next_letters;
        tmp_node = tmp_node->next_letters[index];
        strncat(word, &(tmp_node->letter), 1);
    }

    return strdup(word);  // on retourne une copie du mot
}

int isWordInTree_BaseForm(t_tree t, char* word)
{
    /// Cette fonction cherche dans un arbre donné si le mot qu'on lui passe en argument existe.
    /// La fonction ne prend en charge que les formes de base

    int lenght = strlen(word);
    p_node_letter tmp_node = t.root;
    int index;
    for(int i=0 ; i<lenght ; i++)  // on cherche lettre par lettre le mot dans l'arbre
    {
        index = 0;
        while(index < tmp_node->nb_next_letters && tmp_node->next_letters[index]->letter != word[i])
        {
            index++;
        }
        if(index == tmp_node->nb_next_letters)  // cas où on n'a pas trouvé la lettre, le mot n'est donc pas dans l'arbre
            return 0;
        else
            tmp_node = tmp_node->next_letters[index];
    }
    displayStdWordList(tmp_node->spelling_forms);
    return 1;
}

void randomSentences_BaseForm(t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv)
{
    /// Cette fonction génère des phrases aléatoires selon des modèles prédéfinis.
    /// La fonction ne prend en charge que les formes de base

    // phrase nom – adjectif – verbe – nom (base forms)
    printf("%s ", readRandomWord_BaseForm(t_name));
    printf("%s ", readRandomWord_BaseForm(t_adj));
    printf("%s ", readRandomWord_BaseForm(t_verbs));
    printf("%s\n", readRandomWord_BaseForm(t_name));
    // phrase nom – ‘qui’ – verbe – verbe – nom – adjectif (base forms)
    printf("%s qui ", readRandomWord_BaseForm(t_name));
    printf("%s ", readRandomWord_BaseForm(t_verbs));
    printf("%s ", readRandomWord_BaseForm(t_verbs));
    printf("%s ", readRandomWord_BaseForm(t_name));
    printf("%s\n", readRandomWord_BaseForm(t_adj));
}

void addWordTree_SpellingForm(t_tree* t, char*base_form, char* word, char* gender)
{
    /// Cette fonction ajoute un mot dans un arbre n-aire donné.
    /// Cette fonction prend en charge que les spelling forms

    // printf("%s\n", word);
    int lenght = strlen(base_form);
    int index;
    p_node_letter tmp_node = t->root;
    for(int i=0 ; i<lenght ; i++)   // On va placer les lettres du mot une par une
    {
        if(tmp_node->nb_next_letters == 0)  // si la node courante n'a pas de lettre suivante, on en ajoute une
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[0] = createNodeLetter(base_form[i]);
            tmp_node->nb_next_letters = 1;
            tmp_node = tmp_node->next_letters[0];
            continue;
        }
        index = 0;
        while(index < tmp_node->nb_next_letters && tmp_node->next_letters[index]->letter != base_form[i]) // on cherche si la lettre est déjà dans la node courante
            index++;

        if(index < tmp_node->nb_next_letters) // si cette condition est vraie, alors on a trouvé la lettre dans la liste
        {
            // displayNode(tmp_node);
            tmp_node = tmp_node->next_letters[index];
            continue;
        }
        else  // sinon, cela signifie qu'on n'a pas trouvé la lettre et qu'on doit lui créer une node
        {
            // displayNode(tmp_node);
            tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(base_form[i]);
            tmp_node->nb_next_letters ++;
            tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
        }
    }
    printf("%s %s\n", word, gender);
    addHeadStd(&(tmp_node->spelling_forms), word, gender);
    tmp_node->nb_spelling_forms++;

    // displayNode(tmp_node);
}

void findAndAddTree_SpellingForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                             t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre)
{
    /// Cette fonction cherche dans quel arbre doit aller le mot qu'on lui donne, et lance ensuite la fonction
    /// permettant d'ajouter le mot dans l'arbre adapté. Ne fonctionne qu'avec les formes de base

    switch(line.type[2])   // on utilise dans les case la dernière lettre des types de mots pour identifier le dictionnaire, car elles sont toutes différentes sauf dans un cas
    {
        case 'm':  // noms
        {
            addWordTree_SpellingForm(t_name, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'j': // adjectifs
        {
            addWordTree_SpellingForm(t_adj, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'r': // verbes et abréviations
        {
            if(line.type[0] == 'V')  // verbes
                addWordTree_SpellingForm(t_verbs, line.base_form, line.spelling_form, line.gender);
            else if(line.type[0] == 'A')  // abréviations
                addWordTree_SpellingForm(t_abr, line.base_form, line.spelling_form, line.gender);
            else
                printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
            break;
        }
        case 'v': // adverbes
        {
            addWordTree_SpellingForm(t_adv, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'o': // pronoms
        {
            addWordTree_SpellingForm(t_pro, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'n': // conjonctions
        {
            addWordTree_SpellingForm(t_con, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 't': // interjections
        {
            addWordTree_SpellingForm(t_int, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'e':  // prepositions
        {
            addWordTree_SpellingForm(t_pre, line.base_form, line.spelling_form, line.gender);
            break;
        }
        default: // type inconnu
            printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
    }
}