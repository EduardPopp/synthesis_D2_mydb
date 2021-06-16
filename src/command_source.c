/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** command_source
*/

#include "../include/my.h"
#include "../include/helper.h"

void print_entry(char *field, char *str, llist_t *movies)
{
    llist_t *cur = malloc(sizeof(llist_t));

    if (cur == NULL)
        return;
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        if (strstr(str, cur->director) == NULL || strstr(str, cur->type) == NULL || strstr(str, cur->title) == NULL || strstr(str, cur->synopsis) == NULL) {
            printf("this entry does not exist in the database.\n");
            return;
        }
        if (strstr(cur->title, str) != NULL)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
        if (strstr(cur->synopsis, str) != NULL)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
        if (strstr(cur->director, str) != NULL)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
        if (strstr(cur->type, str) != NULL)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
    }
    free(cur); 
}

void print_movies_by_id_number(char *field, int id_number, llist_t *movies)
{
    llist_t *cur = malloc(sizeof(llist_t));

    if (cur == NULL)
        return;
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        if (id_number != cur->id_director || id_number != cur->id_type || id_number != cur->id_movie) {
            printf("this entry does not exist in the database.\n");
            exit(84); // later loop
        }
        if (strcmp(field, "id_movie") == 0 && cur->id_movie == id_number)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
        if (strcmp(field, "id_director") == 0 && cur->id_director == id_number)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
        if (strcmp(field, "id_type") == 0 && cur->id_type == id_number)
            printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
    }
    free(cur);
}

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
    } else {
        str = strdup(av[i]);
        print_entry(av[i - 1], str, movies);
        free(str);
        return;
    }
}

void get_function_args(char **av, llist_t *movies)
{
    for (int i = 2; av[i] != NULL; i++) {
        // if (strcmp(av[i], "AND") == 0 && i >= 5)
        // if (strcmp(av[i], "OR") == 0 && i >= 5)
        // if (strcmp(av[i], "WHERE") == 0 && i >= 5)
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
       // show_function_args(av, movies);
        return 1;
    }
    if (strcmp(av[i], sort_command) == 0) {
        //sort_function_args(av, movies);
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

void decide_command_source(llist_t *movies, char **av)
{
    int source = 0;
    int i = 2;

    if (source == 0) {
            source = parse_args(av, movies, i);
    }
        //inputloop(movies);
    exit(0);
}