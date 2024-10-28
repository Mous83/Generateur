//
// Created by dquel on 13/11/2022.
//

#ifndef PROJET_GENERATEUR_TREE_NOM_H
#define PROJET_GENERATEUR_TREE_NOM_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des noms
typedef struct s_cell_nom
{
    int nom[30]; //Forme fléchie du nom
    int genre[10]; //Genre du nom
    int sing_plur[10]; //Nombre grammatical de l'adjectif

}t_cell_nom, *p_cell_nom;//On définit un pointeur sur une cellule (p_cell_nom)


//On définit les noeud de notre arbre des adjectifs
typedef struct s_letter_node_nom
{
    char lettre;//On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_flechie; //On initialise une variable qui va stocker le nombre de formes fléchies du nom de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_cell_nom list[10]; //On initialise le tableau de nos formes fléchies
    struct s_letter_node_nom* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_nom, *p_letter_node_nom;


//On définit une structure qui va correspondre à notre arbre de noms
typedef struct s_tree_nom
{
    p_letter_node_nom root;
}t_tree_nom, *p_tree_nom;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_nom createLetterNodeNom(char letter);
//Cette fonction permet de créer un arbre de noms vide
t_tree_nom createEmptyTreeNom();
//Cette fonction permet de générer un arbre de noms de base à l'aide d'un dictionnaire
void generateTreeNom(FILE* filename, p_tree_nom);

//Cette fonction permet de générer un nom de base à partir d'un arbre de noms
void generateNom();
void generateFlechieNom();
void flechieSpecialNom(char*, char*);
//Elle affiche la forme de base plus tous ses fléchies
void printfNom();

#endif //PROJET_GENERATEUR_TREE_NOM_H
