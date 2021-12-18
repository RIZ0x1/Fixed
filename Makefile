CC		=	c++
FLGS	=	-Wall -Wextra -Werror -std=C++98 -pedantic

NAME	=	out
HDRS	=	Fixed.hpp
SRCS	=	Fixed.cpp tests.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

.PHONY: all clean fclean re good

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

good: all clean

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): $(HDRS)

%.o: %.c
	$(CC) $(FLAGS) -c $<
