CC			= gcc
RM			= rm -f
CFLAGS		=  -Wall -Wextra
INCLUDES    = -I ./includes
NAME		= minitalk

all : $(NAME)

$(NAME): server.c client.c utils.c
		$(CC) -g $(INCLUDES) $(CFLAGS) server.c utils.c -o server
		$(CC) -g $(INCLUDES) $(CFLAGS) client.c utils.c -o client

clean:
				${RM} server 

fclean:			clean
				${RM} client


re:				fclean all

.PHONY:			all clean fclean re