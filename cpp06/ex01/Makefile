NAME = ScalarConverter

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
SRCS = 	main.cpp\
		Serializer.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re