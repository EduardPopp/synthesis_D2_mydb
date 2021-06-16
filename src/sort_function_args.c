/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** sort_function_args
*/

#include "../include/my.h"
#include "../include/helper.h"

void sort_function_params(char **av, llist_t *movies, int i)
{
    int id_number = 0;
    char *str = NULL;

    if (strcmp(av[i - 1], "sort") == 0) {
        check_field_validity(av[i], movies);
    }
    if (av[i + 1] == NULL && strcmp(av[i - 1], "id_movie") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "id_director") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "id_type") == 0) {
        id_number = my_getnbr(av[i]);
        print_movies_by_id_number(av[i - 1], id_number, movies);
    } else  if (av[i + 1] == NULL && strcmp(av[i - 1], "title") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "director") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "type") == 0) {
        str = strdup(av[i]);
        print_entry(av[i - 1], str, movies);
        free(str);
        return;
    }
}

sort_function_arg(char **av, llist_t *movies)
{
    for (int i = 2; av[i] != NULL; i++) {
        sort_function_params(av, movies, i);
    }
}