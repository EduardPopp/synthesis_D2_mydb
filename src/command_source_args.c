/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** command_source
*/

#include "../include/my.h"
#include "../include/helper.h"

void decide_command_source(llist_t *movies, char **av)
{
    int source = 0;
    int i = 2;

    parse_args(av, movies, i);
    //inputloop(movies);
    exit(0);
}