##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Make the file
##

NAME := my_world

SRC	:=	help.c				\
		my_world.c			\
		init_game.c			\
		init_background.c	\
		change_map_size.c	\
		game_loop.c			\
		mouse_click.c		\
		map.c				\
		draw_map.c			\
		free.c				\
		button.c			\
		init_buttons.c		\
		str_utils.c			\

CC := epiclang

CFLAGS += -Wall -Wextra

LDFLAGS := -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CPPFLAGS := -I./include

SRC := $(addprefix src/, $(SRC))

OBJ := $(SRC:.c=.o)

RM := rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

libmy.a:
	make -Clib/my/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all	clean

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re
