cmake_minimum_required(VERSION 3.23)
project(dictionnaire_arbre C)

set(CMAKE_C_STANDARD 11)

add_executable(dictionnaire_arbre
        main.c cell.c cell.h list.c list.h tree.c tree.h)
