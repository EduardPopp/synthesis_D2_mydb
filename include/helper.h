/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

typedef struct linked_list {
    struct linked_list *next;
    struct linked_list *prev;
    int id_movie;
    char *title;
    char *synopsis;
    int id_director;
    char *director;
    int id_type;
    char *type;
    int size;
} llist_t;

typedef struct csv {
    char ***data;
    char **labels;
    int n_columns;
    int n_rows;
} csv;

char **my_str_to_word_array(char *str, char sep, int in_word);

csv *parse_data(char *content, csv *output);

csv *parse_csv(char *filepath);

csv *parse_info(char *content);

void free_char_table(char **table);

void free_parsed_csv(csv *parsed_csv);

llist_t *create_list(void);

char *read_file(char *filepath);

llist_t *generate_movie_db(llist_t *list, csv *csv);

int new_node(llist_t *list, csv *csv, int i);

void print_movie_list(llist_t *movies);

void sort_by_string(llist_t *movies);

int check_arguments(int ac, char **av, llist_t *pokemons);

char *uppercase_args(char *argument);

void print_entry(char *field, char *str, llist_t *movies);

void print_movies_by_id_number(char *field, int id_number, llist_t *movies);

int parse_args(char **av, llist_t *movies, int i);

void decide_command_source(llist_t *movies, char **av);

void show_function_arg(char **av, llist_t *movies);

void check_for_no_csv(csv *output);

void check_commas(char *filepath);

void check_field_validity(char *arg, llist_t *movies);
#endif /* !HELPER_H_ */
