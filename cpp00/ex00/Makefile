NAME=megaphone
CXX=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= megaphone.cpp
OBJS=$(SRCS:.cpp=.o)
$(NAME): $(OBJS)
	$(CCX) $(CFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp
	$(CCX) $(CFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
