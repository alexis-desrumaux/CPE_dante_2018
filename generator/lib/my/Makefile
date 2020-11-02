##
## EPITECH PROJECT, 2019
## ALEXIS DESRUMAUX
## File description:
## Makefile
##

NAME	= libmy.a

RM	= rm -f

SRCS	= ./compteurdizaine.c \
	  ./cpy_replace_strarg.c \
	  ./debug.c \
	  ./find_arg_strarg.c \
	  ./float2char.c \
	  ./get_next_line.c \
	  ./get_strarg_float.c \
	  ./get_strarg_int.c \
	  ./get_strarg_str.c \
	  ./int2char.c \
	  ./match_str.c \
	  ./my_f_puiss.c \
	  ./my_f_puiss_float.c \
	  ./my_printf_carriage.c \
	  ./my_printf_check1.c \
	  ./my_printf_check2.c \
	  ./my_printf_check3.c \
	  ./my_printf_check4.c \
	  ./my_printf_check5.c \
	  ./my_printf_check6.c \
	  ./my_printf_check7.c \
	  ./my_printf_conditions.c \
	  ./my_printf_dispflag.c \
	  ./my_putchar.c \
	  ./my_putint.c \
	  ./my_putnbr.c \
	  ./my_putnbr_long.c \
	  ./my_putnbr_short.c \
	  ./my_putstr.c \
	  ./my_strcpy.c \
	  ./my_strlen.c \
	  ./replace_strarg_float.c \
	  ./replace_strarg_int.c \
	  ./replace_strarg_str.c \
	  ./strtab_tools.c \
	  ./to_strarg_char.c \
	  ./to_strarg_float.c \
	  ./to_strarg_int.c \
	  ./to_strtab_char.c \
	  ./to_strtab_int.c \
	  ./tools_1.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
