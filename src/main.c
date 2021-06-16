/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** main
*/

#include "../include/my.h"
#include "../include/helper.h"

llist_t *generate_mon_db(llist_t *list, csv *csv)
{
    for (int i = 0; i < csv->n_rows; i++) {
        new_node(list, csv, i);
    }
    return (list);
}

int main(int ac, char **av)
{
    llist_t *movies = create_list();
    llist_t *cur = malloc(sizeof(llist_t));
    csv *parsed_csv = malloc(sizeof(csv));

    parsed_csv = parse_csv("movies.db");
    generate_movie_db(movies, parsed_csv);
    decide_command_source(movies, av);
    //get_function_from_args(av);
    // for (cur = movies->prev; cur != NULL; cur = cur->next) {
    //     printf("%d;%s;%s;%d;%s;%d;%s\n", cur->id_movie, cur->title, cur->synopsis, cur->id_director, cur->director, cur->id_type, cur->type);
    // }
    //put in free function later
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        free(cur->title);
        free(cur->synopsis);
        free(cur->director);
        free(cur->type);
    }
    // end of put in free function later
    return 0;
}