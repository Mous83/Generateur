cmake_minimum_required(VERSION 3.21)
project(Projet_Generateur C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_Generateurn main.c tree_verbe.c tree_verbe.h tree_nom.c tree_nom.h tree_adject.c tree_adject.h tree_adv.c tree_adv.h txt_fonctions.c txt_fonctions.h)
