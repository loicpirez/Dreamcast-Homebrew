DEST		=	out/

RAW		=	raw/

CC		=	kos-cc

DIR_SRC		=	src/

SRC		=	$(DIR_SRC)main.c

OBJ		=	$(SRC:.c=.o)

NAME		=	testing.elf

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(DEST)$(NAME)
			sh-elf-objcopy -O binary -R .stack $(DEST)testing.elf $(RAW)1st_read.bin
clean		:
			rm -rf $(OBJ)

fclean		:	clean
			rm -rf $(DEST)$(NAME) $(RAW)1st_read.bin

re		:	fclean all
