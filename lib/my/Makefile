##
## EPITECH PROJECT, 2023
## B-CPE-110-LIL-1-1-settingup-augustin.simar
## File description:
## Makefile
##

SRC 	= 	hash.c	\
			my_strlen.c	\
			create_ht.c\
			my_put_nbr.c\
			my_putstr.c\
			dump.c\
			my_putchar.c\
			delete_hashtable.c\
			insert_ht.c	\
			my_strcpy.c	\
			search_ht.c	\
			ht_delete.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libhashtable.a

CFLAGS += -g -Wall -Wextra

all:	libhashtable.a clean

libhashtable.a:	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	mv $(NAME) ../..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean libmy.a
