NAME		:=	hi
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -MMD -std=c++98
SRCS		:=	main.cpp 
DEPS		:=	$(SRCS:.cpp=.d)
OBJS		:=	$(SRCS:.cpp=.o)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)
$(OBJS): $(SRCS)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
