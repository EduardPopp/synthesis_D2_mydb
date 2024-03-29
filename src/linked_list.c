/*
** EPITECH PROJECT, 2021
** linked_list.c
** File description:
** linked_list
*/

#include "../include/helper.h"
#include "../include/my.h"

llist_t *create_obj(llist_t *next_node, csv *csv, int i)
{
    next_node->id_movie = atoi(csv->data[i][0]);
    next_node->title = csv->data[i][1];
    next_node->synopsis = csv->data[i][2];
    next_node->id_director = atoi(csv->data[i][3]);
    next_node->director = csv->data[i][4];
    next_node->id_type = atoi(csv->data[i][5]);
    next_node->type = csv->data[i][6];
    return (next_node);
}

int size_manager(llist_t *list, llist_t *next_node)
{
    if (list == NULL || next_node == NULL)
        return (-1);
    if (list->size == 0) {
        list->prev = next_node;
        list->next = next_node;
    } else {
        list->next->next = next_node;
        next_node->prev = list->next;
        list->next = next_node;
    }
    list->size += 1;
    return (0);
}

int new_node(llist_t *list, csv *csv, int i)
{
    llist_t *next_node = calloc(1, sizeof(llist_t));

    if (list == NULL || next_node == NULL)
        return (-1);
    next_node->prev = NULL;
    next_node->next = NULL;
    next_node = create_obj(next_node, csv, i);
    if (next_node == NULL)
        return (-1);
    if (size_manager(list, next_node) == -1)
        return (-1);
    return (0);
}

llist_t *create_list(void)
{
    llist_t *list = malloc(sizeof(llist_t));

    if (list == NULL)
        return (NULL);
    list->prev = NULL;
    list->next = NULL;
    list->id_movie = 0;
    list->title = NULL;
    list->synopsis = NULL;
    list->id_director = 0;
    list->director = NULL;
    list->id_type = 0;
    list->type = NULL;
    list->size = 0;
    return (list);
}