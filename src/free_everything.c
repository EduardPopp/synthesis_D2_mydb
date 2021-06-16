/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper4-eduard.popp
** File description:
** free_everything
*/

#include "../include/helper.h"
#include "../include/my.h"

void free_char_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

void free_parsed_csv(csv *parsed_csv)
{
    for (int i = 0; parsed_csv->labels[i]; i++)
        free(parsed_csv->labels[i]);
    for (int i = 0; parsed_csv->data[i]; i++)
        free(parsed_csv->data[i]);
    free(parsed_csv->labels);
    free(parsed_csv->data);
}