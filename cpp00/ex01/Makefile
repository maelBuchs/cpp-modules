NAME =	phonebook

CC = c++
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
# HEAD = push_swap.h
SRCS = 	main.cpp \
		Contact.cpp	\
		PhoneBook.cpp



OBJS = $(SRCS:.c=.o)

TOTAL_FILES = $(words $(SRCS))
 
all:			$(NAME)
				@clear
				@echo "Compilation terminée";

$(NAME):		$(OBJS)
				@$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

# clean:			
# 				@$(RM) $(NAME)
# 				@clear
# 				@echo "Clean OK";


fclean: 		#clean
				@clear
				@echo "Full Clean OK ";

re: 			fclean all

.PHONY:			all clean fclean re