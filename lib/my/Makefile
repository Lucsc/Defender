##
## EPITECH PROJECT, 2021
## bsdefender
## File description:
## Makefile
##

SRC 	=	move_rect.c			\
			my_putchar.c		\
			my_putstr.c			\
			create_clock.c		\
			create_music.c		\
			create_sprite.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME) clean

$(NAME):	$(OBJ)
			gcc -c $(SRC)
			ar rc libmy.a $(OBJ)
			cp libmy.a ../

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all