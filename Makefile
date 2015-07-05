DEST	=	out/

CC	=	kos-cc

DIR_SRC	=	src/

SRC	=	$(DIR_SRC)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	testing.elf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(DEST)$(NAME)
		sh-elf-objcopy -O binary -R .stack $(DEST)testing.elf $(DEST)1st_read.bin

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(DEST)$(NAME) $(DEST)1st_read.bin

re	:	fclean all
