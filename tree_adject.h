//
// Created by dquel on 13/11/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADJECT_H
#define PROJET_GENERATEUR_TREE_ADJECT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des adjectifs
struct s_cell_adj
{
    int adjectif[30]; //Forme fléchie de l'adjectif
    int genre[10]; //Genre de l'adjectif
    int sing_plur[10]; //Nombre grammatical de l'adjectif

};
typedef struct s_cell_adj t_cell_adj, *p_cell_adj; //On définit un pointeur sur une cellule (p_cell_adj)

//On définit les noeud de notre arbre des adjectifs
typedef struct s_letter_node_vrb_adject
{
    char lettre; //On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_flechie; //On initialise une variable qui va stocker le nombre de formes fléchies de l'adjectif de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_cell_adj list[10]; //On initialise la liste chaînée de nos formes fléchies
    struct s_letter_node_vrb_adject* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_adject, * p_letter_node_adject;

//On définit une structure qui va correspondre à notre arbre d'adjectifs
typedef struct s_tree_adject
{
    p_letter_node_adject root;
}t_tree_adject,*p_tree_adject;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_adject createLetterNodeAdject(char letter);
//Cette fonction permet de créer un arbre d'ajectifs vide
t_tree_adject createEmptyTreeAdject();

//Cette fonction permet de générer un arbre d'ajectifs de base à l'aide d'un dictionnaire
void generateTreeAdject(FILE* filename, p_tree_adject);

//Cette fonction permet de générer un adjectif de base à partir d'un arbre d'adjectifs
void generateAdject();
void generateFlechieAdject();
void flechieSpecialAdj(char* , char* );
void printAdject();

#endif //PROJET_GENERATEUR_TREE_ADJECT_H
