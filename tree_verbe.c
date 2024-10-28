//
// Created by dquel on 13/11/2022.
//

#include "tree_verbe.h"
#include "txt_fonctions.h"

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_vrb createLetterNodeVerb(char letter)
{
    p_letter_node_vrb nouv = (p_letter_node_vrb) malloc(sizeof(t_letter_node_vrb)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    nouv->nb_flechie = 0; //On initialise notre compteur de formes fléchies à 0
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre de verbes vide
t_tree_vrb createEmptyTreeVerb()
{
    t_tree_vrb tree; //On initialise notre arbre
    tree.root = createLetterNodeVerb('/'); //On créée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de générer un arbre de verbes de base à l'aide d'un dictionnaire
void generateTreeVerb(FILE* filename , p_tree_vrb tree)
{

    p_letter_node_vrb temp_node_verb = tree->root; //On initialise une variable temporaire afin de parcourir notre arbre
    p_cell_vrb temp_head_verbes; //On initialise une variable temporaire afin de parcourir nos listes de formes flechies

    int cpt= 0; //On initialise un compteur permettant de parcourir la forme de base de notre verbe

    FILE *file = fopen(filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire
    while (fgets(texte, 256, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t : +"; //On définit les délimiteurs de notre ligne
        char *verbe_conjuge = strtok(texte, d); //On récupère le verbe conjugé
        char *infinitif = strtok(NULL, d); //On récupère l'infinitif de notre verbe
        char *type_mot = strtok(NULL, d); //On récupère le type de mot de notre verbe

        //On récupère les temps, nombres grammaticaux et personnes de notre verbe (/!\ Il peut y en avoir plusieurs par formes fléchies)
        char *temps_verb1 = strtok(NULL, d);
        char *sing_plur1 = strtok(NULL,d);
        char *personne1 = strtok(NULL,d);

        char *temps_verb2 = strtok(NULL,d);
        char *sing_plur2 = strtok(NULL,d);
        char *personne2 = strtok(NULL,d);

        char *temps_verb3 = strtok(NULL,d);
        char *sing_plur3 = strtok(NULL,d);
        char *personne3 = strtok(NULL,d);

        char *temps_verb4 = strtok(NULL,d);
        char *sing_plur4 = strtok(NULL,d);
        char *personne4 = strtok(NULL,d);

        char *temps_verb5 = strtok(NULL,d);
        char *sing_plur5 = strtok(NULL,d);
        char *personne5 = strtok(NULL,d);

        char *temps_verb6 = strtok(NULL,d);
        char *sing_plur6 = strtok(NULL,d);
        char *personne6 = strtok(NULL,d);

        if (strcmp(type_mot, "Ver") == 0) //On vérifie si le type de mot est un Verbe
        {
            while (infinitif[cpt] != '\0') //On initialise une boucle afin de parcourir notre infinitif
            {

                if (temp_node_verb->sons[convertCharInInt(infinitif[cpt])] == NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_verb->sons[convertCharInInt(infinitif[cpt])] = createLetterNodeVerb(infinitif[cpt]); //alors on va créer un nouveau noeud
                    temp_node_verb = temp_node_verb->sons[convertCharInInt(infinitif[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }
                else
                {
                    temp_node_verb = temp_node_verb->sons[convertCharInInt(infinitif[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_verb->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            //On stock le flechie dans la list
            cpt = 0;
            if (verbe_conjuge != NULL) {
                while (verbe_conjuge[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].forme_conj[cpt] = (int) verbe_conjuge[cpt]; //Tableau d'entier pour le nom car sinon on a des pertes de données
                    cpt++;
                }
            }
            // On stock charques temp, sing_plur, personne dans le meme
            cpt = 0;
            if (temps_verb1 != NULL) {
                while (temps_verb1[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps1[cpt] = (int) temps_verb1[cpt]; //Pareil pour le temps1
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur1 != NULL) {
                while (sing_plur1[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur1[cpt] = (int) sing_plur1[cpt]; //Pareil pour le sing_plur1
                    cpt++;
                }
            }
            cpt = 0;
            if (personne1 != NULL) {
                while (personne1[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers1[cpt] = (int) personne1[cpt]; //Pareil pour le personne1
                    cpt++;
                }
            }

            cpt = 0;
            if (temps_verb2 != NULL) {
                while (temps_verb2[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps2[cpt] = (int) temps_verb2[cpt]; //Pareil pour le temps2
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur2 != NULL) {
                while (sing_plur2[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur2[cpt] = (int) sing_plur2[cpt]; //Pareil pour le sing_plur2
                    cpt++;
                }
            }
            cpt = 0;
            if (personne2 != NULL) {
                while (personne2[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers2[cpt] = (int) personne2[cpt]; //Pareil pour le personne2
                    cpt++;
                }
            }

            cpt = 0;
            if (temps_verb3 != NULL) {
                while (temps_verb3[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps3[cpt] = (int) temps_verb3[cpt]; //Pareil pour le temps3
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur3 != NULL) {
                while (sing_plur3[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur3[cpt] = (int) sing_plur3[cpt]; //Pareil pour le sing_plur3
                    cpt++;
                }
            }
            cpt = 0;
            if (personne3 != NULL) {
                while (personne3[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers3[cpt] = (int) personne3[cpt]; //Pareil pour le personne3
                    cpt++;
                }
            }

            cpt = 0;
            if (temps_verb4 != NULL) {
                while (temps_verb4[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps4[cpt] = (int) temps_verb4[cpt]; //Pareil pour le temps4
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur4 != NULL) {
                while (sing_plur4[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur4[cpt] = (int) sing_plur4[cpt]; //Pareil pour le sing_plur4
                    cpt++;
                }
            }
            cpt = 0;
            if (personne4 != NULL) {
                while (personne4[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers4[cpt] = (int) personne4[cpt]; //Pareil pour le personne4
                    cpt++;
                }
            }

            cpt = 0;
            if (temps_verb5 != NULL) {
                while (temps_verb5[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps5[cpt] = (int) temps_verb5[cpt]; //Pareil pour le temps5
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur5 != NULL) {
                while (sing_plur5[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur5[cpt] = (int) sing_plur5[cpt]; //Pareil pour le sing_plur5
                    cpt++;
                }
            }
            cpt = 0;
            if (personne5 != NULL) {
                while (personne5[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers5[cpt] = (int) personne5[cpt]; //Pareil pour le personne5
                    cpt++;
                }
            }

            cpt = 0;
            if (temps_verb6 != NULL) {
                while (temps_verb6[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].temps6[cpt] = (int) temps_verb6[cpt]; //Pareil pour le temps6
                    cpt++;
                }
            }
            cpt = 0;
            if (sing_plur6 != NULL) {
                while (sing_plur6[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].sing_plur6[cpt] = (int) sing_plur6[cpt]; //Pareil pour le sing_plur6
                    cpt++;
                }
            }
            cpt = 0;
            if (personne6 != NULL) {
                while (personne6[cpt] != '\0') {
                    temp_node_verb->list[temp_node_verb->nb_flechie].pers6[cpt] = (int) personne6[cpt]; //Pareil pour le personne6
                    cpt++;
                }
            }

            temp_node_verb->nb_flechie++; //On incrémente de 1 notre compteur de formes fléchies
            temp_node_verb = tree->root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }

    }
    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
}

void printVerb(){
    t_tree_vrb tree = createEmptyTreeVerb();
    generateTreeVerb((FILE *) NotreFichier, &tree);
    p_letter_node_vrb temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n,deux_tour=0,limite = 0,end = 2; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

    while((deux_tour<2)||(end > 1)) //Tant que nous sommes à la fin d'un nom
    {
        n = rand()%28; //On génère un nombre aléatoire entre 0 et 27
        limite++;
        if(limite > 1000) break; //Si jamais on est bloqué trop longtemps : on recommence
        if(temp->sons[n] != NULL) //Si le noeud que nous avons choisi aléatoirement n'est pas NULL
        {
            temp=temp->sons[n]; //Alors on entre dans ce noeud
            printf("%c",temp->lettre); //On affiche la lettre de notre noeud
            deux_tour++;
            limite = 0;
        }
        if(temp->end_word == 1) end = rand()%10; // Si on arrive à la fin d'un mot : il y a une chance qu'on s'arrete là

    }
    printf(" \n");
    // On affiche tous les fléchies et leurs caractéristiques
    int cpt, i = 0;
    while (temp->nb_flechie != i) {
        printf("--> ");
        cpt = 0;
        while(temp->list[i].forme_conj[cpt] != '\0'){
            printf("%c", temp->list[i].forme_conj[cpt]); // On reconvertie le tableau d'entier en tableau de caractère pour le nom
            cpt++;
        }
        printf(" : ");
        if(temp->list[i].temps1[0] != '\0') {
            cpt = 0;
            while (temp->list[i].temps1[cpt] != '\0') {
                printf("%c", temp->list[i].temps1[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur1[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur1[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur1[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers1[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers1[cpt] != '\0') {
                printf("%c", temp->list[i].pers1[cpt]);
                cpt++;
            }
        }

        if(temp->list[i].temps2[0] != '\0') {
            printf(" : ");
            cpt = 0;
            while (temp->list[i].temps2[cpt] != '\0') {
                printf("%c", temp->list[i].temps2[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur2[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur2[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur2[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers2[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers2[cpt] != '\0') {
                printf("%c", temp->list[i].pers2[cpt]);
                cpt++;
            }
        }

        if(temp->list[i].temps3[0] != '\0') {
            printf(" : ");
            cpt = 0;
            while (temp->list[i].temps3[cpt] != '\0') {
                printf("%c", temp->list[i].temps3[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur3[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur3[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur3[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers3[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers3[cpt] != '\0') {
                printf("%c", temp->list[i].pers3[cpt]);
                cpt++;
            }
        }

        if(temp->list[i].temps4[0] != '\0') {
            printf(" : ");
            cpt = 0;
            while (temp->list[i].temps4[cpt] != '\0') {
                printf("%c", temp->list[i].temps4[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur4[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur4[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur4[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers4[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers4[cpt] != '\0') {
                printf("%c", temp->list[i].pers4[cpt]);
                cpt++;
            }
        }

        if(temp->list[i].temps5[0] != '\0') {
            printf(" : ");
            cpt = 0;
            while (temp->list[i].temps5[cpt] != '\0') {
                printf("%c", temp->list[i].temps5[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur5[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur5[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur5[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers5[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers5[cpt] != '\0') {
                printf("%c", temp->list[i].pers5[cpt]);
                cpt++;
            }
        }

        if(temp->list[i].temps6[0] != '\0') {
            printf(" : ");
            cpt = 0;
            while (temp->list[i].temps6[cpt] != '\0') {
                printf("%c", temp->list[i].temps6[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].sing_plur6[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].sing_plur6[cpt] != '\0') {
                printf("%c", temp->list[i].sing_plur6[cpt]);
                cpt++;
            }
        }
        if(temp->list[i].pers6[0] != '\0') {
            printf(" + ");
            cpt = 0;
            while (temp->list[i].pers6[cpt] != '\0') {
                printf("%c", temp->list[i].pers6[cpt]);
                cpt++;
            }
        }
        i++;
    }
}

//Cette fonction permet de générer un verbe de base à partir d'un arbre de verbes
void generateVerb()
{
    t_tree_vrb tree = createEmptyTreeVerb();
    generateTreeVerb((FILE *) NotreFichier, &tree);
    p_letter_node_vrb temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n,deux_tour=0,limite = 0,end = 2; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

    while((deux_tour<2)||(end > 1)) //Tant que nous sommes à la fin d'un nom
    {
        n = rand()%28; //On génère un nombre aléatoire entre 0 et 27
        limite++;
        if(limite > 1000) break; //Si jamais on est bloqué trop longtemps : on recommence
        if(temp->sons[n] != NULL) //Si le noeud que nous avons choisi aléatoirement n'est pas NULL
        {
            temp=temp->sons[n]; //Alors on entre dans ce noeud
            printf("%c",temp->lettre); //On affiche la lettre de notre noeud
            deux_tour++;
            limite = 0;
        }
        if(temp->end_word == 1) end = rand()%10; // Si on arrive à la fin d'un mot : il y a une chance qu'on s'arrete là

    }
    printf(" ");
}

void generateFlechieVerb() {
    t_tree_vrb tree = createEmptyTreeVerb();
    generateTreeVerb((FILE *) NotreFichier, &tree);
    p_letter_node_vrb temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n,deux_tour=0,limite = 0,end = 2; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

    while((deux_tour<2)||(end > 1)) //Tant que nous sommes à la fin d'un nom
    {
        n = rand()%28; //On génère un nombre aléatoire entre 0 et 27
        limite++;
        if(limite > 1000) break; //Si jamais on est bloqué trop longtemps : on recommence
        if(temp->sons[n] != NULL) //Si le noeud que nous avons choisi aléatoirement n'est pas NULL
        {
            temp=temp->sons[n]; //Alors on entre dans ce noeud
            deux_tour++;
            limite = 0;
        }
        if(temp->end_word == 1) end = rand()%10; // Si on arrive à la fin d'un mot : il y a une chance qu'on s'arrete là
    }

    int cpt, i = rand()%temp->nb_flechie;
    cpt = 0;
    while(temp->list[i].forme_conj[cpt] != '\0'){
        printf("%c", temp->list[i].forme_conj[cpt]); // On reconvertie le tableau d'entier en tableau de caractère pour le nom
        cpt++;
    }
    printf(" : ");
    if(temp->list[i].temps1[0] != '\0') {
        cpt = 0;
        while (temp->list[i].temps1[cpt] != '\0') {
            printf("%c", temp->list[i].temps1[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur1[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur1[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur1[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers1[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers1[cpt] != '\0') {
            printf("%c", temp->list[i].pers1[cpt]);
            cpt++;
        }
    }

    if(temp->list[i].temps2[0] != '\0') {
        printf(" : ");
        cpt = 0;
        while (temp->list[i].temps2[cpt] != '\0') {
            printf("%c", temp->list[i].temps2[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur2[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur2[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur2[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers2[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers2[cpt] != '\0') {
            printf("%c", temp->list[i].pers2[cpt]);
            cpt++;
        }
    }

    if(temp->list[i].temps3[0] != '\0') {
        printf(" : ");
        cpt = 0;
        while (temp->list[i].temps3[cpt] != '\0') {
            printf("%c", temp->list[i].temps3[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur3[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur3[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur3[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers3[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers3[cpt] != '\0') {
            printf("%c", temp->list[i].pers3[cpt]);
            cpt++;
        }
    }

    if(temp->list[i].temps4[0] != '\0') {
        printf(" : ");
        cpt = 0;
        while (temp->list[i].temps4[cpt] != '\0') {
            printf("%c", temp->list[i].temps4[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur4[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur4[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur4[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers4[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers4[cpt] != '\0') {
            printf("%c", temp->list[i].pers4[cpt]);
            cpt++;
        }
    }

    if(temp->list[i].temps5[0] != '\0') {
        printf(" : ");
        cpt = 0;
        while (temp->list[i].temps5[cpt] != '\0') {
            printf("%c", temp->list[i].temps5[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur5[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur5[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur5[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers5[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers5[cpt] != '\0') {
            printf("%c", temp->list[i].pers5[cpt]);
            cpt++;
        }
    }

    if(temp->list[i].temps6[0] != '\0') {
        printf(" : ");
        cpt = 0;
        while (temp->list[i].temps6[cpt] != '\0') {
            printf("%c", temp->list[i].temps6[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].sing_plur6[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].sing_plur6[cpt] != '\0') {
            printf("%c", temp->list[i].sing_plur6[cpt]);
            cpt++;
        }
    }
    if(temp->list[i].pers6[0] != '\0') {
        printf(" + ");
        cpt = 0;
        while (temp->list[i].pers6[cpt] != '\0') {
            printf("%c", temp->list[i].pers6[cpt]);
            cpt++;
        }
    }
}

void flechieSpecialVerb(char* temps, char* sing_plur, char* personne){
    t_tree_vrb tree = createEmptyTreeVerb();
    generateTreeVerb((FILE *) NotreFichier, &tree);
    p_letter_node_vrb temp;
    int STOP = 1;
    int n, deux_tour = 0, limite = 0, end = 2;
    while(STOP) {
        temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
        deux_tour = 0, limite = 0, end = 2; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

        while ((deux_tour < 2) || (end > 1)) //Tant que nous sommes à la fin d'un nom
        {
            n = rand() % 28; //On génère un nombre aléatoire entre 0 et 27
            limite++;
            if (limite > 1000) break; //Si jamais on est bloqué trop longtemps : on recommence
            if (temp->sons[n] != NULL) //Si le noeud que nous avons choisi aléatoirement n'est pas NULL
            {
                temp = temp->sons[n]; //Alors on entre dans ce noeud
                deux_tour++;
                limite = 0;
            }
            if (temp->end_word == 1)
                end = rand() % 10; // Si on arrive à la fin d'un mot : il y a une chance qu'on s'arrete là
        }
        int i = 0,cpt = 0,trouver = 1;
        while(1) {
            i = rand() % temp->nb_flechie;
            if((((temp->list[i].temps1[0] != '\0' && temp->list[i].temps1[0] == temps[0])&&(temp->list[i].temps1[1] != '\0' && temp->list[i].temps1[1] == temps[1])&&(temp->list[i].temps1[2] != '\0' && temp->list[i].temps1[2] == temps[2]))&&(temp->list[i].sing_plur1[0] != '\0' && temp->list[i].sing_plur1[0] == sing_plur[0])&&(temp->list[i].pers1[0] != '\0' && temp->list[i].pers1[1] == personne[1]))
               ||(((temp->list[i].temps2[0] != '\0' && temp->list[i].temps2[0] == temps[0])&&(temp->list[i].temps2[1] != '\0' && temp->list[i].temps2[1] == temps[1])&&(temp->list[i].temps2[2] != '\0' && temp->list[i].temps2[2] == temps[2]))&&(temp->list[i].sing_plur2[0] != '\0' && temp->list[i].sing_plur2[0] == sing_plur[0])&&(temp->list[i].pers2[0] != '\0' && temp->list[i].pers2[1] == personne[1]))
               ||(((temp->list[i].temps3[0] != '\0' && temp->list[i].temps3[0] == temps[0])&&(temp->list[i].temps3[1] != '\0' && temp->list[i].temps3[1] == temps[1])&&(temp->list[i].temps3[2] != '\0' && temp->list[i].temps3[2] == temps[2]))&&(temp->list[i].sing_plur3[0] != '\0' && temp->list[i].sing_plur3[0] == sing_plur[0])&&(temp->list[i].pers3[0] != '\0' && temp->list[i].pers3[1] == personne[1]))
               ||(((temp->list[i].temps4[0] != '\0' && temp->list[i].temps4[0] == temps[0])&&(temp->list[i].temps4[1] != '\0' && temp->list[i].temps4[1] == temps[1])&&(temp->list[i].temps4[2] != '\0' && temp->list[i].temps4[2] == temps[2]))&&(temp->list[i].sing_plur4[0] != '\0' && temp->list[i].sing_plur4[0] == sing_plur[0])&&(temp->list[i].pers4[0] != '\0' && temp->list[i].pers4[1] == personne[1]))
               ||(((temp->list[i].temps5[0] != '\0' && temp->list[i].temps5[0] == temps[0])&&(temp->list[i].temps5[1] != '\0' && temp->list[i].temps5[1] == temps[1])&&(temp->list[i].temps5[2] != '\0' && temp->list[i].temps5[2] == temps[2]))&&(temp->list[i].sing_plur5[0] != '\0' && temp->list[i].sing_plur5[0] == sing_plur[0])&&(temp->list[i].pers5[0] != '\0' && temp->list[i].pers5[1] == personne[1]))
               ||(((temp->list[i].temps6[0] != '\0' && temp->list[i].temps6[0] == temps[0])&&(temp->list[i].temps6[1] != '\0' && temp->list[i].temps6[1] == temps[1])&&(temp->list[i].temps6[2] != '\0' && temp->list[i].temps6[2] == temps[2]))&&(temp->list[i].sing_plur6[0] != '\0' && temp->list[i].sing_plur6[0] == sing_plur[0])&&(temp->list[i].pers6[0] != '\0' && temp->list[i].pers6[1] == personne[1]))){
                trouver = 1;
                break;
            }
            cpt ++;
            if(cpt > 100){
                trouver = 0;
                break;
            }
        }
        if(trouver && temp->list[i].forme_conj[0] != '\0') {
            cpt = 0;
            while (temp->list[i].forme_conj[cpt] != '\0') {
                printf("%c",
                       temp->list[i].forme_conj[cpt]); // On reconvertie le tableau d'entier en tableau de caractère pour le nom
                cpt++;
            }
            /**
            printf(" : ");
            if(temp->list[i].temps1[0] != '\0') {
                cpt = 0;
                while (temp->list[i].temps1[cpt] != '\0') {
                    printf("%c", temp->list[i].temps1[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur1[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur1[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur1[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers1[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers1[cpt] != '\0') {
                    printf("%c", temp->list[i].pers1[cpt]);
                    cpt++;
                }
            }

            if(temp->list[i].temps2[0] != '\0') {
                printf(" : ");
                cpt = 0;
                while (temp->list[i].temps2[cpt] != '\0') {
                    printf("%c", temp->list[i].temps2[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur2[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur2[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur2[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers2[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers2[cpt] != '\0') {
                    printf("%c", temp->list[i].pers2[cpt]);
                    cpt++;
                }
            }

            if(temp->list[i].temps3[0] != '\0') {
                printf(" : ");
                cpt = 0;
                while (temp->list[i].temps3[cpt] != '\0') {
                    printf("%c", temp->list[i].temps3[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur3[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur3[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur3[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers3[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers3[cpt] != '\0') {
                    printf("%c", temp->list[i].pers3[cpt]);
                    cpt++;
                }
            }

            if(temp->list[i].temps4[0] != '\0') {
                printf(" : ");
                cpt = 0;
                while (temp->list[i].temps4[cpt] != '\0') {
                    printf("%c", temp->list[i].temps4[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur4[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur4[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur4[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers4[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers4[cpt] != '\0') {
                    printf("%c", temp->list[i].pers4[cpt]);
                    cpt++;
                }
            }

            if(temp->list[i].temps5[0] != '\0') {
                printf(" : ");
                cpt = 0;
                while (temp->list[i].temps5[cpt] != '\0') {
                    printf("%c", temp->list[i].temps5[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur5[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur5[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur5[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers5[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers5[cpt] != '\0') {
                    printf("%c", temp->list[i].pers5[cpt]);
                    cpt++;
                }
            }

            if(temp->list[i].temps6[0] != '\0') {
                printf(" : ");
                cpt = 0;
                while (temp->list[i].temps6[cpt] != '\0') {
                    printf("%c", temp->list[i].temps6[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].sing_plur6[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].sing_plur6[cpt] != '\0') {
                    printf("%c", temp->list[i].sing_plur6[cpt]);
                    cpt++;
                }
            }
            if(temp->list[i].pers6[0] != '\0') {
                printf(" + ");
                cpt = 0;
                while (temp->list[i].pers6[cpt] != '\0') {
                    printf("%c", temp->list[i].pers6[cpt]);
                    cpt++;
                }
            }
             **/
            STOP = 0;
        }
    }
}