##
## EPITECH PROJECT, 2021
## B-MUL-200-PAR-2-1-mydefender-brice.boualavong
## File description:
## Makefile
##

SRC		=	main.c						\
			src/button.c				\
			src/functions.c				\
			src/start_screen.c			\
			src/help.c					\
			src/enemy.c					\
			src/linktostart_screen.c	\
			src/pause.c					\
			src/tower.c					\
			src/cursor.c				\
			src/linked_togame_screen.c	\
			src/gameplay.c				\
			src/lost_screen.c			\
			src/deathennemy.c			\
			src/damage.c				\
			src/damageother.c			\
			src/score.c					\
			src/gold.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	+=	-I ./include

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my/ all
			gcc -o $(NAME) $(OBJ) -L lib/my/ -lmy -lncurses -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
			make -C lib/my/ clean
			rm -f $(OBJ)
			rm -f $(NAME)

fclean:		clean
			rm -f $(NAME)

re:			fclean all