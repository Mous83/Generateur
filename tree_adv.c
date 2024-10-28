//
// Created by dquel on 13/11/2022.
//

#include "tree_adv.h"

//
// Created by dquel on 13/11/2022.
//

#include "tree_nom.h"
#include "txt_fonctions.h"

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_adv createLetterNodeAdv(char letter)
{
    p_letter_node_adv nouv = (p_letter_node_adv) malloc(sizeof(t_letter_node_adv)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    nouv->nb_flechie = 0; //On initialise notre compteur de formes fléchies à 0
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre de noms vide
t_tree_adv createEmptyTreeAdv()
{
    t_tree_adv tree; //On initialise notre arbre
    tree.root = createLetterNodeAdv('/'); //On créée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de générer un arbre de noms de base à l'aide d'un dictionnaire
void generateTreeAdv(FILE* filename,p_tree_adv tree) {
    p_letter_node_adv temp_node_adv = tree->root; //On initialise une variable temporaire afin de parcourir notre arbre

    int cpt = 0; //On initialise un compteur permettant de parcourir la forme de base de nom

    FILE *file = fopen((const char *) filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire

    while (fgets(texte, 255, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t \n"; //On définit les délimiteurs de notre ligne
        char *nom = strtok(texte, d); //On récupère le nom
        char *forme_base = strtok(NULL, d); //On récupère la forme de base
        char *type_mot = strtok(NULL, d);//On récupère le type de mot de notre nom

        if (strcmp(type_mot, "Adv") == 0) //On vérifie si le type de mot est un Nom
        {
            while (forme_base[cpt] != '\0') //On initialise une boucle afin de parcourir notre forme de base
            {
                if (temp_node_adv->sons[convertCharInInt(forme_base[cpt])] ==
                    NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_adv->sons[convertCharInInt(forme_base[cpt])] = createLetterNodeAdv(
                            forme_base[cpt]); //alors on va créer un nouveau noeud
                    temp_node_adv = temp_node_adv->sons[convertCharInInt(
                            forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                } else {
                    temp_node_adv = temp_node_adv->sons[convertCharInInt(
                            forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }
                //temp_head_noms = temp_node_nom->nb_formes; //On ajoute dans notre variable temporaire la tete de la liste de formes flechies

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_adv->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            //On stock le flechie dans la list
            cpt = 0;
            if (nom != NULL) {
                while (nom[cpt] != '\0') {
                    temp_node_adv->list[temp_node_adv->nb_flechie].nom[cpt] = (int) nom[cpt]; //Tableau d'entier pour le nom car sinon on a des pertes de données
                    cpt++;
                }
            }

            temp_node_adv->nb_flechie++; //On incrémente de 1 notre compteur de formes fléchies

            temp_node_adv = tree->root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }

    }

    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
}

//Cette fonction permet de générer un nom de base à partir d'un arbre de noms
void generateAdv()
{
    t_tree_adv tree = createEmptyTreeAdv();
    generateTreeAdv((FILE *) NotreFichier, &tree);
    p_letter_node_adv temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
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

void printAdv (){
    t_tree_adv tree = createEmptyTreeAdv();
    generateTreeAdv((FILE *) NotreFichier, &tree);
    p_letter_node_adv temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
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
    printf("\n");
    //On affiche les fléchies stocké dans la list
    int cpt, i = 0;
    while (temp->nb_flechie != i) {
        printf("--> ");
        cpt = 0;
        while(temp->list[i].nom[cpt] != '\0'){
            printf("%c", temp->list[i].nom[cpt]); // On reconvertie le tableau d'entier en tableau de caractère pour le nom
            cpt++;
        }
        i++;
    }
}
void generateFlechieAdv() {
    t_tree_adv tree = createEmptyTreeAdv();
    generateTreeAdv((FILE *) NotreFichier, &tree);
    p_letter_node_adv temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n, deux_tour = 0, limite = 0, end = 2; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

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
    int i = rand() %temp->nb_flechie, cpt;
    cpt = 0;
    while(temp->list[i].nom[cpt] != '\0'){
        printf("%c", temp->list[i].nom[cpt]); // On reconvertie le tableau d'entier en tableau de caractère pour le nom
        cpt++;
    }
}
