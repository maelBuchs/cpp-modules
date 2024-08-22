NAME = zombies	

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
SRCS = 	main.cpp \
				Zombie.cpp \
				zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all:			$(NAME)
				@echo "Compilation terminée";

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean: 
				$(RM) $(OBJS)

fclean: clean 
				$(RM) $(NAME)

re: 		fclean all

.PHONY:			all clean fclean re
