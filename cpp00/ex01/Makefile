NAME		:=	phonebook
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -MMD -std=c++98
SRCS		:=	main.cpp \
				Contact.cpp \
				PhoneBook.cpp
DEPS		:=	$(SRCS:.cpp=.d)
OBJS		:=	$(SRCS:.cpp=.o)
INCS		:= 	Contact.hpp \
        		PhoneBook.hpp


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)
$(OBJS): $(SRCS) $(INCS)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
