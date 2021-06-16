/*
** EPITECH PROJECT, 2021
** synthesis_D2_mydb
** File description:
** command_source_utils
*/

#include "../include/my.h"
#include "../include/helper.h"

void check_for_no_csv(char *content)
{
    for (int i = 0; content[i] != NULL; i++) {
        if (content[i] == " " || content[i] == '\n' && content[i + 1] == ';') {
            break;
        }
    }
    printf("empty columns in the database need to be declared with -1.\n");
    exit(84);
}

void print_entry(char *field, char *str, llist_t *movies)
{
    llist_t *cur = malloc(sizeof(llist_t));

    if (cur == NULL)
        return;
    for (cur = movies->prev; cur != NULL; cur = cur->next) {
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