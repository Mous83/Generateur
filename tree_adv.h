//
// Created by dquel on 13/11/2022.
//

#ifndef PROJET_GENERATEUR_TREE_NOM_H
#define PROJET_GENERATEUR_TREE_NOM_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des adv
typedef struct s_cell_adv
{
    int nom[30]; //Forme fléchie du adv

}t_cell_adv, *p_cell_adv;//On définit un pointeur sur une cellule (p_cell_adv)


//On définit les noeud de notre arbre des adjectifs
typedef struct s_letter_node_adv
{
    char lettre;//On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_flechie; //On initialise une variable qui va stocker le nombre de formes fléchies du adv de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_cell_adv list[10]; //On initialise le tableau de nos formes fléchies
    struct s_letter_node_adv* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_adv, *p_letter_node_adv;


//On définit une structure qui va correspondre à notre arbre de adv
typedef struct s_tree_adv
{
    p_letter_node_adv root;
}t_tree_adv, *p_tree_adv;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_adv createLetterNodeAdv(char letter);
//Cette fonction permet de créer un arbre de adv vide
t_tree_adv createEmptyTreeAdv();
//Cette fonction permet de générer un arbre de adv de base à l'aide d'un dictionnaire
void generateTreeAdv(FILE* filename, p_tree_adv);

//Cette fonction permet de générer un adv de base à partir d'un arbre de adv
void generateAdv();
void generateFlechieAdv();
//Elle affiche la forme de base plus tous ses fléchies
void printfAdv();

#endif //PROJET_GENERATEUR_TREE_NOM_H
