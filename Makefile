##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	src/main.c	\
		src/csv_parser.c	\
		src/linked_list.c	\
		src/my_str_to_word_array.c	\
		src/name_sort_movies.c	\
		src/create_movie_db.c	\
		src/free_everything.c	\
		src/command_source_args.c	\
		src/command_source_utils.c	\
		src/get_function.c	\
		src/show_function_args.c	\
		src/sort_function_args.c


OBJ	=	$(SRC:.c=.o)

NAME	=	mydb

INC	=	-I include/

LMY	=	-L lib/my/ -lmy

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3 -Wall -Wextra -W

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all