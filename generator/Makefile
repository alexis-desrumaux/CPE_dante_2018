##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= generator

CC	= gcc

RM	= rm -f

SRCS	= ./anti_cheats.c \
	  ./build.c \
	  ./connect_room.c \
	  ./goodway.c \
	  ./init.c \
	  ./free_cursor.c \
	  ./cursor_management.c \
	  ./begin_generator.c \
	  ./init_cursor.c \
	  ./cut_pos_maze.c \
	  ./play_goodway.c \
	  ./main.c \
	  ./main_tools.c \
	  ./managment.c \
	  ./tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall

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
