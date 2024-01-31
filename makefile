SERVER	=	server.c
CLIENT	=	client.c

OBJ_S	=	$(SERVER:.c=.o)
OBJ_C	=	$(CLIENT:.c=.o)

CC		=	cc 

NAME_S	=	server
NAME_C	=	client

PRINTFA	=	./Ft_printf/libftprintf.a
PRINTFD	=	./Ft_printf

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(PRINTFA) $(OBJ_S)
	$(CC) $(OBJ_S) $(PRINTFA) -o $(NAME_S)

$(NAME_C): $(PRINTFD) $(OBJ_C)
	$(CC) $(OBJ_C) $(PRINTFA) -o $(NAME_C)

clean:
	rm -f $(OBJ_C)
	rm -f $(OBJ_S)
	make clean -C $(PRINTFD)

fclean: clean
	rm -f $(NAME_C)
	rm -f $(NAME_S)	
	make fclean -C $(PRINTFD)

re: fclean all

$(PRINTFA): $(PRINTFD)
	make -C $(PRINTFD)
