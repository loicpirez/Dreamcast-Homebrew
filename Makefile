CC	=	kos-cc

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	testing.elf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
		sh-elf-objcopy -O binary -R .stack testing.elf 1st_read.bin
clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME) 1st_read.bin

re	:	fclean all
