##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compilation
##

all:
	make -C generator/
	make -C solver/

clean:
	make fclean -C generator/
	make fclean -C solver/

fclean: clean

re: clean all
