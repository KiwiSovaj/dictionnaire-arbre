/*
-----------------------------------------------------------------------------------
Projet d'algorithmique et structures de données 2 : générateur automatique de mots
-----------------------------------------------------------------------------------

Par Johan Leroy, Cédric Hombourger & Alexis Georges
EFREI L2 groupe A

Fichier tree.c : contient toutes les fonctions permettant de modifier, de créer ou de lire les arbres

*/

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
            tmp_node = tmp_node->next_letters[index];
            continue;
        }
        else  // sinon, cela signifie qu'on n'a pas trouvé la lettre et qu'on doit lui créer une node
        {
            tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(word[i]);
            tmp_node->nb_next_letters ++;
            tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
        }
    }
}

void findAndAddTree_BaseForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                       t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre, t_tree *t_det)
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
                // printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
                break;
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
        case 't': // interjections et determinants
        {
            if (line.type[0]=='I')
                addWordTree_BaseForm(t_int, line.base_form);
            else
                addWordTree_BaseForm(t_det, line.base_form);
            break;
        }
        case 'e':  // prepositions
        {
            addWordTree_BaseForm(t_pre, line.base_form);
            break;
        }
        default: // type inconnu
            // printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
            break;
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
    return 1;
}

void isWordInTrees_BaseForm(char* word, t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv, t_tree t_abr,
        t_tree t_pro, t_tree t_con, t_tree t_int, t_tree t_pre, t_tree t_det)
{
    printf("\n");
    if(isWordInTree_BaseForm(t_name, word))
        printf("Ce mot est un nom\n");
    if(isWordInTree_BaseForm(t_adj, word))
        printf("Ce mot est un adjectif\n");
    if(isWordInTree_BaseForm(t_verbs, word))
        printf("Ce mot est un verbe\n");
    if(isWordInTree_BaseForm(t_adv, word))
        printf("Ce mot est un adverbe\n");
    if(isWordInTree_BaseForm(t_abr, word))
        printf("Ce mot est une abreviation\n");
    if(isWordInTree_BaseForm(t_pro, word))
        printf("Ce mot est un pronom\n");
    if(isWordInTree_BaseForm(t_int, word))
        printf("Ce mot est une interjection \n");
    if(isWordInTree_BaseForm(t_pre, word))
        printf("Ce mot est une preposition\n");
    if(isWordInTree_BaseForm(t_det, word))
        printf("Ce mot est un determinant\n");
}

void randomSentences_BaseForm(t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv)
{
    /// Cette fonction génère des phrases aléatoires selon des modèles prédéfinis.
    /// La fonction ne prend en charge que les formes de base

    printf("\n");
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
    // phrase verbe - 'vous' - nom - adjectif - ?
    printf("%s-vous ", readRandomWord_BaseForm(t_verbs));
    printf("%s ", readRandomWord_BaseForm(t_name));
    printf("%s ?\n", readRandomWord_BaseForm(t_adj));
}

void addWordTree_SpellingForm(t_tree* t, char*base_form, char* word, char* gender)
{
    /// Cette fonction ajoute un mot dans un arbre n-aire donné.
    /// Cette fonction prend en charge les spelling forms

    // printf("%s\n", word);
    // printf("%s\n", gender);
    int lenght = strlen(base_form);
    int index;
    p_node_letter tmp_node = t->root;
    for(int i=0 ; i<lenght ; i++)   // On va placer les lettres du mot une par une
    {
        if(tmp_node->nb_next_letters == 0)  // si la node courante n'a pas de lettre suivante, on en ajoute une
        {
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
            tmp_node = tmp_node->next_letters[index];
            continue;
        }
        else  // sinon, cela signifie qu'on n'a pas trouvé la lettre et qu'on doit lui créer une node
        {
            tmp_node->next_letters[tmp_node->nb_next_letters] = createNodeLetter(base_form[i]);
            tmp_node->nb_next_letters ++;
            tmp_node = tmp_node->next_letters[tmp_node->nb_next_letters-1];
        }
    }
    addHeadStd(&(tmp_node->spelling_forms), word, gender);
    tmp_node->nb_spelling_forms++;
}

void findAndAddTree_SpellingForm(LINE line, t_tree *t_name, t_tree *t_adj, t_tree *t_verbs, t_tree *t_adv, t_tree *t_abr,
                             t_tree *t_pro, t_tree *t_con, t_tree *t_int, t_tree *t_pre, t_tree *t_det)
{
    /// Cette fonction envoie les informations contenues dans la ligne qu'elle reçoit en entrée dans la fonction
    /// permettant d'ajouter des mots dans un arbre. Elle associe le bon arbre à ces informations afin qu'elles
    /// soient placées dans le bon arbre.
    /// Cette fonction prend en charge les formes fléchies

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
                // printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
                break;
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
        case 't': // interjections et determinants
        {
            if (line.type[0]=='I')
                addWordTree_SpellingForm(t_int, line.base_form, line.spelling_form, line.gender);
            else
                addWordTree_SpellingForm(t_det, line.base_form, line.spelling_form, line.gender);
            break;
        }
        case 'e':  // prepositions
        {
            addWordTree_SpellingForm(t_pre, line.base_form, line.spelling_form, line.gender);
            break;
        }
        default: // type inconnu
            // printf("Type inconnu : %s    Mot associe : %s\n", line.type, line.base_form);
            break;
    }
}

char* readRandomWord_SpellingForms(t_tree t, char* gender)
{
    /// Cette fonction cherche une forme fléchie correspondant au genre qu'on lui donne en entrée dans l'arbre
    /// qu'elle a également reçu en entrée.
    /// Le genre contient aussi le nombre (singulier / pluriel) et le temps dans le cas d'un verbe(présent, futur...)

    p_node_letter word_nodes[40];
    p_node_letter chosen_word;
    int nb_word_found;
    int index;
    p_node_letter tmp_node;
    p_cell tmp_cell;
    do {
        index = 0;
        nb_word_found = 0;
        tmp_node = t.root;
        while (tmp_node->nb_next_letters != 0)   // On prend un chemin aléatoire dans l'arbre jusqu'à une feuille
        {
            if (tmp_node->nb_spelling_forms != 0) {  // quand on trouve une node contenant des spelling forms, on la stocke
                word_nodes[nb_word_found] = tmp_node;
                nb_word_found++;
            }
            index = rand() % tmp_node->nb_next_letters;
            tmp_node = tmp_node->next_letters[index];
        }
        word_nodes[nb_word_found] = tmp_node;
        nb_word_found++;

        chosen_word = word_nodes[rand() % nb_word_found];   // on choisit une des nodes qu'on a stockées au hasard
        tmp_cell = chosen_word->spelling_forms.head;

        while (tmp_cell != NULL && strstr(tmp_cell->gender, gender)==NULL)  // on cherche si la node choisie possède une forme du genre cherché
            tmp_cell = tmp_cell->next;
    } while (tmp_cell==NULL);  // on relance la boucle si on n'a pas trouvé le genre cherché

    return strdup(tmp_cell->word);  // on retourne une copie du mot
}


void randomSentences_SpellingForm(t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv) {
    /// Cette fonction crée une phrase aléatoire contenant des accords et des conjuguaisons corrects.
    /// Il y a 4 modèles de phrases prédéfinis, la fonction demande à l'utilisateur d'en choisir un.

    char* tenses[3] = {"IPre", "IImp", "SPre"};
    char* numbers[2] = {"SG", "PL"};
    char* genders[2] = {"Mas", "Fem"};
    char* articles[6] = {"un", "une", "des", "le", "la", "les"};
    char* pronouns[8] = {"Je", "Tu", "Il", "Elle", "Nous", "Vous", "Ils", "Elles"};
    char* persons[3] = {"P1", "P2", "P3"};
    char meta[40];

    printf("\n\nChoisissez le modele :\n"
           "  1. nom - adjectif - verbe - nom\n"
           "  2. nom - 'qui' - verbe - verbe - nom - adjectif\n"
           "  3. verbe - 'vous' - nom - adjectif - ?\n"
           "  4. pronom - verbe - nom - adjectif\n");
    int choice, r;
    do {
        printf(">>>");
        r = scanf("%d", &choice);
    } while(!r || choice<1 || choice>4);

    int number, tense, gender, pers;

    switch (choice) {

        case 1: {   //  nom – adjectif – verbe – nom
            number = rand() % 2;
            gender = rand() % 2;
            printf("\n%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s ", readRandomWord_SpellingForms(t_name, meta));
            printf("%s ", readRandomWord_SpellingForms(t_adj, meta));
            memset(meta, 0, 40);

            tense = rand() % 3;
            strncat(meta, ":", 1);
            strncat(meta, tenses[tense], 4);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            strncat(meta, "+", 1);
            strncat(meta, "P3", 2);
            printf("%s ", readRandomWord_SpellingForms(t_verbs, meta));
            memset(meta, 0, 40);

            number = rand() % 2;
            gender = rand() % 2;
            printf("%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s.", readRandomWord_SpellingForms(t_name, meta));

            break;
        }

        case 2: {  // nom – "qui" – verbe – verbe – nom – adjectif
            number = rand() % 2;
            gender = rand() % 2;
            printf("\n%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s qui ", readRandomWord_SpellingForms(t_name, meta));
            memset(meta, 0, 40);

            tense = rand() % 3;
            strncat(meta, ":", 1);
            strncat(meta, tenses[tense], 4);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            strncat(meta, "+", 1);
            strncat(meta, "P3", 2);
            printf("%s ", readRandomWord_SpellingForms(t_verbs, meta));
            memset(meta, 0, 40);

            tense = rand() % 3;
            strncat(meta, ":", 1);
            strncat(meta, tenses[tense], 4);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            strncat(meta, "+", 1);
            strncat(meta, "P3", 2);
            printf("%s ", readRandomWord_SpellingForms(t_verbs, meta));
            memset(meta, 0, 40);

            number = rand() % 2;
            gender = rand() % 2;
            printf("%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s ", readRandomWord_SpellingForms(t_name, meta));
            printf("%s.", readRandomWord_SpellingForms(t_adj, meta));
            memset(meta, 0, 40);

            break;
        }

        case 3: {  // verbe - "vous" - nom - adjectif - ?
            tense = rand() % 3;
            strncat(meta, ":", 1);
            strncat(meta, tenses[tense], 4);
            strncat(meta, "+", 1);
            strncat(meta, "PL", 2);
            strncat(meta, "+", 1);
            strncat(meta, "P2", 2);
            printf("%s-vous ", readRandomWord_SpellingForms(t_verbs, meta));
            memset(meta, 0, 40);

            number = rand() % 2;
            gender = rand() % 2;
            printf("%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s ", readRandomWord_SpellingForms(t_name, meta));
            printf("%s ?", readRandomWord_SpellingForms(t_adj, meta));
            memset(meta, 0, 40);

            break;
        }

        case 4: {  // pronom - verbe - nom - adjectif
            number = rand()%2;
            pers = rand()%3;
            printf("\n%s ", pronouns[number*4+pers+(pers==2)*rand()%2]);

            tense = rand() % 3;
            strncat(meta, ":", 1);
            strncat(meta, tenses[tense], 4);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            strncat(meta, "+", 1);
            strncat(meta, persons[pers], 2);
            printf("%s ", readRandomWord_SpellingForms(t_verbs, meta));
            memset(meta, 0, 40);

            number = rand() % 2;
            gender = rand() % 2;
            printf("%s ", articles[gender * (1 - number) + number * 2 + rand() % 2 * 3]);
            strncat(meta, ":", 1);
            strncat(meta, genders[gender], 3);
            strncat(meta, "+", 1);
            strncat(meta, numbers[number], 2);
            printf("%s ", readRandomWord_SpellingForms(t_name, meta));
            printf("%s.", readRandomWord_SpellingForms(t_adj, meta));
            memset(meta, 0, 40);

            break;
        }

        default: {  // Impossible d'entrer ici normalement (grâce à la saisie sécurisée)
            printf("Erreur");
            break;
        }
    }
}


void searchSpellingInTrees(char* spelling_form, t_tree t_name, t_tree t_adj, t_tree t_verbs, t_tree t_adv,
                           t_tree t_abr, t_tree t_pro, t_tree t_con, t_tree t_int, t_tree t_pre, t_tree t_det){
    /// Cette fonction permet de chercher une forme fléchie dans tous les arbres.
    /// Si le mot cherché est trouvé, elle affiche sa forme de base.
    /// Dans le cas contraire, elle affiche que le mot n'a pas été trouvé.

    char* buffer = (char*) malloc(sizeof(char)*40);
    if (searchSpellingInTree(spelling_form, t_name.root, buffer, "nom")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_adj.root, buffer, "adj")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_verbs.root, buffer, "ver")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_adv.root, buffer, "adv")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_abr.root, buffer, "abr")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_pro.root, buffer, "pro")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_con.root, buffer, "con")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_int.root, buffer, "int")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_pre.root, buffer, "pre")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else if (searchSpellingInTree(spelling_form, t_det.root, buffer, "det")) {
        for (int i = strlen(buffer)-2; i >= 0; --i)
            printf("%c", buffer[i]);
    }
    else
        printf("Mot non trouve");
}


int searchSpellingInTree(char* spelling_form, p_node_letter node, char* buffer, char* type)
{
    /// Cette fonction permet de chercher par récurrence une forme fléchie dans un arbre et de récupérer sa
    /// forme de base, ainsi que ses informations (genre, nombre, temps...).
    /// La forme de base est stockée dans le buffer, tandis que les informations de la forme
    ///  fléchie sont affichées directement via la fonction "printGender".

    if (node->nb_next_letters==0 && node->nb_spelling_forms==0) {
        return 0;
    }
    if (node->nb_spelling_forms!=0) {
        p_cell tmp = node->spelling_forms.head;
        while (tmp!=NULL && (strcmp(tmp->word, spelling_form)!=0)) {
            tmp = tmp->next;
        }
        if (tmp!=NULL) {
            printGender(tmp->gender, type);
            strncat(buffer, &(node->letter), 1);
            return 1;
        }
    }
    for (int i = 0; i < node->nb_next_letters; ++i) {
        if (searchSpellingInTree(spelling_form, node->next_letters[i], buffer, type)) {
            strncat(buffer, &(node->letter), 1);
            return 1;
        }
    }
    return 0;
}


void printGender(char* gender, char* type) {
    /// Cette fonction permet de convertir les informations du fichier (de la forme "Ver:IPre+SG+P1" par exemple)
    /// en phrases. Cela permet à l'utilisateur de voir rapidement les informations d'un mot.

    char new_gender[40];

    for (int i = 0; i < strlen(gender); ++i) {   // Si le mot contient plusieurs formes, on garde la 1ere
        if (gender[i]==':' && i>0) {
            new_gender[i] = '\0';
            break;
        }
        else
            new_gender[i] = gender[i];
    }

    if (!strcmp(type, "ver")) {   // conversion des verbes
        if (gender[1]=='P' && gender[3]=='r')
            printf("Participe present");
        else if (gender[1]=='P' && gender[3]=='a')
            printf("Participe passe");
        else if (gender[1]=='I' && gender[3]=='r')
            printf("Present de l'indicatif");
        else if (gender[1]=='I' && gender[3]=='S')
            printf("Passe simple de l'indicatif");
        else if (gender[1]=='I' && gender[2]=='I')
            printf("Imparfait de l'indicatif");
        else if (gender[1]=='I' && gender[2]=='F')
            printf("Futur de l'indicatif");
        else if (gender[1]=='I' && gender[2]=='n')
            printf("Infinitif");
        else if (gender[1]=='S' && gender[2]=='I')
            printf("Imparfait du subjonctif");
        else if (gender[1]=='S' && gender[2]=='P')
            printf("Present du subjonctif");
        else if (gender[1]=='C' && gender[2]=='P')
            printf("Present du conditionnel");

        if (strstr(new_gender, "P1"))
            printf(", premiere personne du");
        else if (strstr(new_gender, "P2"))
            printf(", deuxieme personne du");
        else if (strstr(new_gender, "P3"))
            printf(", troisieme personne du");
        if (strstr(new_gender, "Mas"))
            printf(", masculin");
        else if (strstr(new_gender, "Fem"))
            printf(", feminin");
        if (strstr(new_gender, "PL"))
            printf(" pluriel");
        else if (strstr(new_gender, "SG"))
            printf(" singulier");

        printf(" du verbe ");
    }

    else if (!strcmp(type, "nom") || !strcmp(type, "adj")) {   // conversion des noms et des adjectifs
        if (strstr(new_gender, "Mas"))
            printf("Masculin");
        else if (strstr(new_gender, "Fem"))
            printf("Feminin");
        else if (strstr(new_gender, "InvGen"))
            printf("Invariable");
        if (strstr(new_gender, "PL"))
            printf(" pluriel");
        else if (strstr(new_gender, "SG"))
            printf(" singulier");
        if (!strcmp(type, "nom"))
            printf(" du nom ");
        else
            printf(" de l'adjectif ");
    }

    else if (!strcmp(type, "adv")) {   // conversion des adverbes
        printf("Adverbe ");
    }

    else if (!strcmp(type, "abr")) {   // conversion des abréviations
        printf("Abreviation ");
    }

    else if (!strcmp(type, "pro")) {   // conversion des pronoms
        if (!strcmp(gender, "")) printf("Pronom ");
        else {
            if (strstr(new_gender, "Mas"))
                printf("Masculin");
            else if (strstr(new_gender, "Fem"))
                printf("Feminin");
            else if (strstr(new_gender, "InvGen"))
                printf("Invariable");
            if (strstr(new_gender, "PL"))
                printf(" pluriel");
            else if (strstr(new_gender, "SG"))
                printf(" singulier");
            printf("du pronom ");
        }
    }

    else if (!strcmp(type, "con")) {   // conversion des conjonctions
        printf("Conjonction ");
    }

    else if (!strcmp(type, "int")) {   // conversion des interjections
        printf("Interjection ");
    }

    else if (!strcmp(type, "det")) {   // conversion des déterminants
        if (!strcmp(gender, "")) printf("Determinant ");
        else {
            if (strstr(new_gender, "Mas"))
                printf("Masculin");
            else if (strstr(new_gender, "Fem"))
                printf("Feminin");
            else if (strstr(new_gender, "InvGen"))
                printf("Invariable");
            if (strstr(new_gender, "PL"))
                printf(" pluriel");
            else if (strstr(new_gender, "SG"))
                printf(" singulier");
            printf("du determinant ");
        }
    }

    else if (!strcmp(type, "pre")) {   // conversion des prepositions
        printf("Preposition ");
    }
}