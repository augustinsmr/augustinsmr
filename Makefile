##
## EPITECH PROJECT, 2023
## B-CPE-110-LIL-1-1-settingup-augustin.simar
## File description:
## Makefile
##

SRC 	= 	lib/my/hash.c	\
			lib/my/my_strlen.c	\
			lib/my/create_ht.c\
			lib/my/my_put_nbr.c\
			lib/my/my_putstr.c\
			lib/my/dump.c\
			lib/my/my_putchar.c\
			lib/my/delete_hashtable.c\
			lib/my/insert_ht.c	\
			lib/my/my_strcpy.c	\
			lib/my/search_ht.c	\
			lib/my/ht_delete.c

OBJ	=	$(SRC:.c=.o)

all:	secured

secured:	$(OBJ)
	make -C lib/my/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	gcc -o unit_tests $(SRC) tests/tests_secured.c --coverage -lcriterion
	./unit_tests

re:	fclean all
