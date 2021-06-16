/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** main
*/

#include "../include/my.h"
#include "../include/helper.h"

int main(int ac, char **av)
{
    llist_t *movies = create_list();
    llist_t *cur = malloc(sizeof(llist_t));
    csv *parsed_csv = malloc(sizeof(csv));

    parsed_csv = parse_csv(av[1]);
    generate_movie_db(movies, parsed_csv);
    decide_command_source(movies, av);
    //put in free function later
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
        free(cur->title);
        free(cur->synopsis);
        free(cur->director);
        free(cur->type);
    }
    free(cur);
    // end of put in free function later
    return 0;
}