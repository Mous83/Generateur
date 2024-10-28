//
// Created by dquel on 13/11/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "txt_fonctions.h"
#include "tree_adv.h"

//Cette variable permet de convertir un caractère en son numéro de l'alphabet à la même manière d'un chiffrement de Cesar
int convertCharInInt(char letter)
{
    switch(letter)
    {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        case 'i': return 8;
        case 'j': return 9;
        case 'k': return 10;
        case 'l': return 11;
        case 'm': return 12;
        case 'n': return 13;
        case 'o': return 14;
        case 'p': return 15;
        case 'q': return 16;
        case 'r': return 17;
        case 's': return 18;
        case 't': return 19;
        case 'u': return 20;
        case 'v': return 21;
        case 'w': return 22;
        case 'x': return 23;
        case 'y': return 24;
        case 'z': return 25;
        case '-': return 26;
        case 39 : return 27; //La valeur 29 correspond au code ASCII d'un apostrophe
    }
}

//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - adjectif - verbe - nom
void generateBaseSentenceModel1()
{
    generateNom(); //On génère un nom
    generateAdject(); //On génère un adjectif
    generateVerb(); //On génère un verbe
    generateNom(); //On génère un nom
    printf("\n"); //On retourne à la ligne
}

//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - 'qui' - verbe - verbe - nom - adjectif
void generateBaseSentenceModel2()
{
    generateNom(); //On génère un premier nom
    printf("qui "); //On affiche le pronom relatif qui
    generateVerb();//On génère un premier verbe
    generateVerb(); //On génère un second verbe
    generateNom(); //On génère un second nom
    generateAdject(); //On génère un adjectif
    printf("\n"); //On retourne à la ligne
}

void generateFlechieSentenceModel1(){
    char* TousLesTemps[30] = {"IImp","IPSim","PPas","IPre","IFut","CPre","SImp"};
    int pers, GENRE, NOMBRE;
    char* PERSONNE;
    GENRE = rand()%2;
    NOMBRE = rand()%2;
    char* TEMP = TousLesTemps[rand()%7];
    pers = rand()%3;
    if(pers == 0) PERSONNE = "P1";
    if(pers == 1) PERSONNE = "P2";
    if(pers == 2) PERSONNE = "P3";

    if(GENRE == 0 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf("Le ");
        if(version == 1) printf("Un ");
        flechieSpecialNom("Mas", "SG");

        printf(" ");
        flechieSpecialAdj("Mas", "SG");
        printf(" ");


        flechieSpecialVerb(TEMP, "SG", PERSONNE);
    }
    if(GENRE == 1 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf("La ");
        if(version == 1) printf("Une ");
        flechieSpecialNom("Fem", "SG");

        printf(" ");
        flechieSpecialAdj("Fem", "SG");
        printf(" ");


        flechieSpecialVerb(TEMP, "SG", PERSONNE);
    }
    if(GENRE == 0 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf("Des ");
        if(version == 1) printf("Les ");
        flechieSpecialNom("Mas", "PL");

        printf(" ");
        flechieSpecialAdj("Mas", "PL");
        printf(" ");


        flechieSpecialVerb(TEMP, "PL", PERSONNE);
    }
    if(GENRE == 1 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf("Des ");
        if(version == 1) printf("Les ");
        flechieSpecialNom("Fem", "PL");

        printf(" ");
        flechieSpecialAdj("Fem", "PL");
        printf(" ");


        flechieSpecialVerb(TEMP, "PL", PERSONNE);
    }

    GENRE = rand()%2;
    NOMBRE = rand()%2;

    if(GENRE == 0 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf(" un ");
        if(version == 1) printf(" le ");
        flechieSpecialNom("Mas", "SG");
    }
    if(GENRE == 1 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf(" une ");
        if(version == 1) printf(" la ");
        flechieSpecialNom("Fem", "SG");
    }
    if(GENRE == 0 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf(" des ");
        if(version == 1) printf(" les ");
        flechieSpecialNom("Mas", "PL");
    }
    if(GENRE == 1 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf(" des ");
        if(version == 1) printf(" les ");
        flechieSpecialNom("Fem", "PL");
    }
}

void generateFlechieSentenceModel2(){
    char* TousLesTemps[30] = {"IImp","IPSim","PPas","IPre","IFut","CPre","SImp"};
    int pers, GENRE, NOMBRE;
    char* PERSONNE;
    GENRE = rand()%2;
    NOMBRE = rand()%2;
    char* TEMP = TousLesTemps[rand()%7];
    pers = rand()%3;
    if(pers == 0) PERSONNE = "P1";
    if(pers == 1) PERSONNE = "P2";
    if(pers == 2) PERSONNE = "P3";

    if(GENRE == 0 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf("Le ");
        if(version == 1) printf("Un ");
        flechieSpecialNom("Mas", "SG");
        printf(" qui ");

        flechieSpecialVerb(TEMP, "SG", PERSONNE);
        printf(" ");
        flechieSpecialVerb(TEMP, "SG", PERSONNE);
    }
    if(GENRE == 1 && NOMBRE == 0) {
        int version = rand()%2;
        if(version == 0) printf("La ");
        if(version == 1) printf("Une ");
        flechieSpecialNom("Fem", "SG");
        printf(" qui ");

        flechieSpecialVerb(TEMP, "SG", PERSONNE);
        printf(" ");
        flechieSpecialVerb(TEMP, "SG", PERSONNE);
    }
    if(GENRE == 0 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf("Des ");
        if(version == 1) printf("Les ");
        flechieSpecialNom("Mas", "PL");
        printf(" qui ");

        flechieSpecialVerb(TEMP, "PL", PERSONNE);
        printf(" ");
        flechieSpecialVerb(TEMP, "PL", PERSONNE);
    }
    if(GENRE == 1 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf("Des ");
        if(version == 1) printf("Les ");
        flechieSpecialNom("Fem", "PL");
        printf(" qui ");

        flechieSpecialVerb(TEMP, "PL", PERSONNE);
        printf(" ");
        flechieSpecialVerb(TEMP, "PL", PERSONNE);
    }

    GENRE = rand()%2;
    NOMBRE = rand()%2;

    if(GENRE == 0 && NOMBRE == 0) {
        printf(" un ");
        flechieSpecialNom("Mas", "SG");
        printf(" ");
        flechieSpecialAdj("Mas","SG");
    }
    if(GENRE == 1 && NOMBRE == 0) {
        printf(" une ");
        flechieSpecialNom("Fem", "SG");
        printf(" ");
        flechieSpecialAdj("Fem","SG");
    }
    if(GENRE == 0 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf(" des ");
        if(version == 1) printf(" les ");
        flechieSpecialNom("Mas", "PL");
        printf(" ");
        flechieSpecialAdj("Mas","PL");
    }
    if(GENRE == 1 && NOMBRE == 1) {
        int version = rand()%2;
        if(version == 0) printf(" des ");
        if(version == 1) printf(" les ");
        flechieSpecialNom("Fem", "PL");
        printf(" ");
        flechieSpecialAdj("Fem", "PL");
    }
}

//Cette fonction permet de démarer le menu
void fonction_menu()
{
    int menu, sous_menu; //On initialise deux variables afin de stocker le menu et le sous menu choisit
    printf("\n\n###############################################\n");
    printf("#                                             #\n");
    printf("#                    MENU                     #\n");
    printf("#                                             #\n");
    printf("###############################################\n");

    //On demande le menu à exécuter
    printf("\nQuelle fonctionnalite voulez-vous choisir ? \n\n 1. Generer une forme de base \n 2. Generer une phrase de base \n 3. Generer une forme flechie \n 4. Generer une phrase flechie \n 5. Rechercher un mot\n\n ");
    scanf(" %d", &menu); //On récupère la saisie du numéro de menu
    switch (menu)
    {
        case 1:
            printf("\n###############################################\n");
            printf("#                                             #\n");
            printf("#          Generer une forme de Base          #\n");
            printf("#                                             #\n");
            printf("###############################################\n\n");

            //On demande le sous-menu à exécuter
            printf("Quelle fonctionnalite voulez-vous choisir ? \n\n 1. Generer un nom \n 2. Generer un verbe \n 3. Generer un adjectif \n 4. Generer un adverbe \n\n ");
            scanf(" %d", &sous_menu); //On récupère la saisie du numéro de sous-menu
            switch (sous_menu) //On fait un switch case en fonction de nos sous-menus
            {
                case 1:
                    //On génère un nom de base
                    generateNom();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 2 :
                    //On génère un verbe de base
                    generateVerb();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 3 :
                    //On génère un adjectif de base
                    generateAdject();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 4 :
                    //On génère un adverbe de base
                    generateAdv();
                    fonction_menu();

                default : printf("Ce numéro n'existe pas !\n\n");
                    fonction_menu(); //On retourne au menu principal
            }
            break;

        case 2:
            printf("\n################################################\n");
            printf("#                                              #\n");
            printf("#          Generer une phrase de Base          #\n");
            printf("#                                              #\n");
            printf("################################################\n\n");

            //On demande le sous-menu à exécuter
            printf("Quelle fonctionnalite voulez-vous choisir ? \n\n 1. Generer une phrase du type : nom - adjectif - verbe - nom \n 2. Generer une phrase du type : nom - 'qui' - verbe - verbe - nom - adjectif \n\n");
            scanf(" %d", &sous_menu); //On récupère la saisie du numéro de sous-menu
            switch (sous_menu) //On fait un switch case en fonction de nos sous-menus
            {
                case 1 :
                    //On génère une phrase de base qui suit le modèle : nom - adjectif - verbe - nom
                    generateBaseSentenceModel1();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 2 :
                    //On génère une phrase de base qui suit le modèle : nom - 'qui' - verbe - verbe - nom - adjectif
                    generateBaseSentenceModel2();
                    fonction_menu(); //On retourne au menu principal
                    break;
                default:
                    //On affiche un message d'erreur
                    printf("Ce numero n'existe pas !\n\n");
                    fonction_menu(); //On retourne au menu principal
            }
            break;

        case 3 :
            printf("\n##################################################\n");
            printf("#                                                #\n");
            printf("#          Generer une forme de flechie          #\n");
            printf("#                                                #\n");
            printf("##################################################\n\n");
            printf("Quelle fonctionnalite voulez-vous choisir ? \n\n 1. Generer un nom flechi\n 2. Generer un verbe flechi\n 3. Generer un adjectif flechi\n 4. Generer un adverbe flechi\n\n ");
            scanf(" %d", &sous_menu); //On récupère la saisie du numéro de sous-menu
            switch (sous_menu) //On fait un switch case en fonction de nos sous-menus
            {
                case 1:
                    //On génère un nom de base
                    generateFlechieNom();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 2 :
                    //On génère un verbe de base
                    generateFlechieVerb();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 3 :
                    //On génère un adjectif de base
                    generateFlechieAdject();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 4 :
                    //On génère un adverbe de base
                    generateFlechieAdv();
                    fonction_menu();

                default : printf("Ce numéro n'existe pas !\n\n");
                    fonction_menu(); //On retourne au menu principal
            }
            break;

        case 4:
            printf("\n################################################\n");
            printf("#                                              #\n");
            printf("#          Generer une phrase flechie          #\n");
            printf("#                                              #\n");
            printf("################################################\n\n");
            printf("Quelle fonctionnalite voulez-vous choisir ? \n\n 1. Generer une phrase du type : nom - adjectif - verbe - nom \n 2. Generer une phrase du type : nom - 'qui' - verbe - verbe - nom - adjectif \n\n");
            scanf(" %d", &sous_menu); //On récupère la saisie du numéro de sous-menu
            switch (sous_menu) //On fait un switch case en fonction de nos sous-menus
            {
                case 1 :
                    //On génère une phrase qui suit le modèle : nom - adjectif - verbe - nom
                    generateFlechieSentenceModel1();
                    fonction_menu(); //On retourne au menu principal
                    break;
                case 2 :
                    //On génère une phrase qui suit le modèle : nom - 'qui' - verbe - verbe - nom - adjectif
                    generateFlechieSentenceModel2();
                    fonction_menu(); //On retourne au menu principal
                    break;
                default:
                    //On affiche un message d'erreur
                    printf("Ce numero n'existe pas !\n\n");
                    fonction_menu(); //On retourne au menu principal
            }

            fonction_menu(); //On retourne au menu principal
            break;

        case 5:
            printf("\n##################################################\n");
            printf("#                                                #\n");
            printf("#          Rechercher une forme flechie          #\n");
            printf("#                                                #\n");
            printf("##################################################\n\n");
            printf("Cette fonctionnalite n'est pas disponible !\n\n");
            fonction_menu(); //On retourne au menu principal
            break;

        default :
            //On affiche un message d'erreur
            printf("Ce numero n'existe pas !\n\n");
            fonction_menu(); //On retourne au menu principal
    }
}
