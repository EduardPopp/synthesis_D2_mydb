/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** show_function_args
*/

#include "../include/my.h"
#include "../include/helper.h"

void print_movies_by_show(int id_number, int max_entry, llist_t *movies)
{
    llist_t *cur = malloc(sizeof(llist_t));

    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        if (cur->id_movie == id_number) {
            break;
        }
    }
    for (int i = 0; i < max_entry && cur != NULL; cur = cur->next, i++) {
        printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, \
        cur->synopsis, cur->id_director, cur->director, cur->id_type, \
        cur->type);
    }
    free(cur);
}
void show_database(llist_t *movies)
{
    llist_t *cur = malloc(sizeof(llist_t));
    
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, \
        cur->synopsis, cur->id_director, cur->director, cur->id_type, \
        cur->type);
    }
    free(cur);
    exit(0);
}

void show_function_params(char **av, llist_t *movies, int i)
{
    int id_number = 0;
    int max_entry = 0;

    if (strcmp(av[i], "show") == 0 && av[i + 1] == NULL) {
        show_database(movies);
    }
    if (av[i + 1] != NULL && av[i + 2] != NULL) {
        id_number = my_getnbr(av[i + 1]);
        max_entry = my_getnbr(av[i + 2]);
        print_movies_by_show(id_number, max_entry, movies);
    } else {
        return;
    }
}

void show_function_arg(char **av, llist_t *movies)
{
    for (int i = 2; av[i] != NULL; i++) {
        show_function_params(av, movies, i);
    }
}