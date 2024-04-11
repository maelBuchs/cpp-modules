NAME =	megaphone

CC = c++
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
# HEAD = push_swap.h
SRCS = 	megaphone.cpp


OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))

all:			$(NAME)
				@clear
				@echo "Compilation terminée";

$(NAME):		$(OBJS)
				@$(CC) -o $(NAME) $(CFLAGS)

clean:			
				@$(RM) $(OBJS)
				@clear
				@echo "Clean OK";


fclean: 		clean
				@clear
				@echo "Full Clean OK ";

re: 			fclean all

.PHONY:			all clean fclean re