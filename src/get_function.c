/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** get_function
*/

#include "../include/helper.h"
#include "../include/my.h"

void check_field_validity(char *arg, llist_t *movies)
{
    if (strcmp(arg, "id_movie") != 0 && strcmp(arg, "title") != 0 \
    && strcmp(arg, "synopsis") != 0 && strcmp(arg, "id_director") != 0 \
    && strcmp(arg, "director") != 0 && strcmp(arg, "id_type") != 0 \
    && strcmp(arg, "type") != 0) {
        printf("this field does not exist in this database.\n");
        exit(84);
    }
}

void get_function_params(char **av, llist_t *movies, int i)
{
    int id_number = 0;
    char *str = NULL;

    if (strcmp(av[i - 1], "get") == 0) {
        check_field_validity(av[i], movies);
    }
    if (av[i + 1] == NULL && strcmp(av[i - 1], "id_movie") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "id_director") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "id_type") == 0) {
        id_number = my_getnbr(av[i]);
        print_movies_by_id_number(av[i - 1], id_number, movies);
    } else  if (av[i + 1] == NULL && strcmp(av[i - 1], "title") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "director") == 0 || \
    av[i + 1] == NULL && strcmp(av[i - 1], "type") == 0 || av[i + 1] == NULL && strcmp(av[i - 1], "synopsis") == 0) {
        str = strdup(av[i]);
        print_entry(av[i - 1], str, movies);
        free(str);
        return;
    }
}

void get_function_args(char **av, llist_t *movies)
{
    for (int i = 2; av[i] != NULL; i++) {
        get_function_params(av, movies, i);
    }
}

int parse_args(char **av, llist_t *movies, int i)
{
    char *get_command = strdup("get");
    char *show_command = strdup("show");
    char *sort_command = strdup("sort");

    if (strcmp(av[i], get_command) == 0) {
        get_function_args(av, movies);
        return 1;
    }
    if (strcmp(av[i], show_command) == 0) {
        show_function_arg(av, movies);
        return 1;
    }
    if (strcmp(av[i], sort_command) == 0) {
        sort_function_arg(av, movies);
        return 1;
    }
    // later to extra fkt
    if (av[i] != NULL && strcmp(av[i], get_command) != 0 \
    || av[i] != NULL && strcmp(av[i], show_command) != 0 \
    || av[i] != NULL && strcmp(av[i], sort_command) != 0) {
        printf("please use a valid command!\n");
        exit(84);
    }

    return 0;
}
