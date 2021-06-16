/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** create_movie_db
*/

#include "../include/helper.h"
#include "../include/my.h"

llist_t *generate_movie_db(llist_t *list, csv *csv)
{
    for (int i = 0; i < csv->n_rows; i++) {
        new_node(list, csv, i);
    }
    return (list);
}