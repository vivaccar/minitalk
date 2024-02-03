SERVER	=	server.c
CLIENT	=	client.c

OBJ_S	=	$(SERVER:.c=.o)
OBJ_C	=	$(CLIENT:.c=.o)

SERVER_BONUS	=	server_bonus.c
CLIENT_BONUS	=	client_bonus.c

OBJ_BS	=	$(SERVER_BONUS:.c=.o)
OBJ_BC	=	$(CLIENT_BONUS:.c=.o)

CC		=	cc 

NAME_S	=	server
NAME_C	=	client
NAME_SBONUS	=	server_bonus
NAME_CBONUS =	client_bonus

PRINTFA	=	./Ft_printf/libftprintf.a
PRINTFD	=	./Ft_printf

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(PRINTFA) $(OBJ_S)
	$(CC) $(OBJ_S) $(PRINTFA) -o $(NAME_S)

$(NAME_C): $(PRINTFD) $(OBJ_C)
	$(CC) $(OBJ_C) $(PRINTFA) -o $(NAME_C)

bonus: $(NAME_SBONUS) $(NAME_CBONUS)

$(NAME_SBONUS): $(PRINTFA) $(OBJ_BS)
	$(CC) $(OBJ_BS) $(PRINTFA) -o $(NAME_SBONUS)

$(NAME_CBONUS): $(PRINTFA) $(OBJ_BC)
	$(CC) $(OBJ_BC) $(PRINTFA) -o $(NAME_CBONUS)

clean:
	rm -f $(OBJ_C)
	rm -f $(OBJ_S)
	rm -f $(OBJ_BC)
	rm -f $(OBJ_BS)
	make clean -C $(PRINTFD)

fclean: clean
	rm -f $(NAME_C)
	rm -f $(NAME_S)	
	rm -f $(NAME_CBONUS)
	rm -f $(NAME_SBONUS)
	make fclean -C $(PRINTFD)

re: fclean all

$(PRINTFA): $(PRINTFD)
	make -C $(PRINTFD)
