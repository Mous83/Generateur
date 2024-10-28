//
// Created by dquel on 13/11/2022.
//

#ifndef PROJET_GENERATEUR_TREE_VERBE_H
#define PROJET_GENERATEUR_TREE_VERBE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des verbes
struct s_cell_vrb
{
    int forme_conj[30]; //Forme conjuguée

    int pers1[10]; // je/tu/il/...
    int sing_plur1[10]; // singulier/ pluriel
    int temps1[10]; // Passé present
    int pers2[10]; // je/tu/il/...
    int sing_plur2[10]; // singulier/ pluriel
    int temps2[10]; // Passé present
    int pers3[10]; // je/tu/il/...
    int sing_plur3[10]; // singulier/ pluriel
    int temps3[10]; // Passé present
    int pers4[10]; // je/tu/il/...
    int sing_plur4[10]; // singulier/ pluriel
    int temps4[10]; // Passé present
    int pers5[10]; // je/tu/il/...
    int sing_plur5[10]; // singulier/ pluriel
    int temps5[10]; // Passé present
    int pers6[10]; // je/tu/il/...
    int sing_plur6[10]; // singulier/ pluriel
    int temps6[10]; // Passé present

};
typedef struct s_cell_vrb t_cell_vrb, *p_cell_vrb;//On définit un pointeur sur une cellule (p_cell_vrb)

//On définit les noeud de notre arbre des verbes
typedef struct s_letter_node_vrb
{
    char lettre; //On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_flechie; //On initialise une variable qui va stocker le nombre de formes fléchies du nom de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_cell_vrb list[200]; //On initialise la liste chaînée de nos formes fléchies
    struct s_letter_node_vrb* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_vrb, *p_letter_node_vrb;

//On définit une structure qui va correspondre à notre arbre de verbes
typedef struct s_tree_vrb
{
    p_letter_node_vrb root;
}t_tree_vrb,*p_tree_vrb;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_vrb createLetterNodeVerb(char letter);
//Cette fonction permet de créer un arbre de verbes vide
t_tree_vrb createEmptyTreeVerb();

//Cette fonction permet de générer un arbre de verbes de base à l'aide d'un dictionnaire
void generateTreeVerb(FILE* filename ,p_tree_vrb);

//Cette fonction permet de générer un verbe de base à partir d'un arbre de verbes
void generateVerb();
void generateFlechieVerb();
void flechieSpecialVerb(char* , char* , char* );
void printVerb();
#endif //PROJET_GENERATEUR_TREE_VERBE_H