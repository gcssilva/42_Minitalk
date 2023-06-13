SERVER	=	server

CLIENT	=	client

CC		=	cc

FLAGS	=	-Werror -Wall -Wextra

INC		=	minitalk.h

UTILS	=	utils.c

all:			$(SERVER) $(CLIENT)

$(SERVER):
				$(CC) $(FLAGS) -o $(SERVER) $(SERVER).c $(UTILS)

$(CLIENT):
				$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT).c $(UTILS)

clean:
				rm -f $(SERVER) $(CLIENT)

fclean:			clean


re:				fclean all


.PHONY:			all clean fclean re