##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= solver

CC	= gcc

RM	= rm -f

SRCS	= src/solver.c \
		  src/file_to_tab.c \
		  src/is_a_real_maze.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/my/
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L lib/my/ -lmy

clean:
	make fclean -C lib/my/
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
