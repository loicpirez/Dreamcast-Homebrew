CC	=	kos-cc

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	testing.elf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
