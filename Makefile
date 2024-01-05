##
## EPITECH PROJECT, 2023
## B-CPE-110-LIL-1-1-settingup-augustin.simar
## File description:
## Makefile
##

all:	secured

secured:	$(OBJ)
	make -C lib/my/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
