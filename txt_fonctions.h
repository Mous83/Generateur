//
// Created by dquel on 13/11/2022.
//

#ifndef PROJET_GENERATEUR_TXT_FONCTIONS_H
#define PROJET_GENERATEUR_TXT_FONCTIONS_H

#define ALPHABET 28
#define NotreFichier "C:\\Users\\dquel\\OneDrive\\Bureau\\Fuchsia\\L2\\C\\dictionnaire_non_accentue.txt"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree_verbe.h"
#include "tree_nom.h"
#include "tree_adject.h"
#include "tree_adv.h"

//Cette variable permet de convertir un caractère en son numéro de l'alphabet à la même manière d'un chiffrement de Cesar
int convertCharInInt(char letter);

//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - adjectif - verbe - nom
void generateBaseSentenceModel1();
//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - 'qui' - verbe - verbe - nom - adjectif
void generateBaseSentenceModel2();

void generateFlechieSentenceModel1();
void generateFlechieSentenceModel2();
//Cette fonction permet de démarrer le menu
void fonction_menu();

#endif //PROJET_GENERATEUR_TXT_FONCTIONS_H
