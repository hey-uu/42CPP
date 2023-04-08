.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	phonebook

# COMPILE FLAGS
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS			=	-I.
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS			=	PhoneBook.cpp main.cpp Contact.cpp stream_utils.cpp
OBJS			=	$(SRCS:.cpp=.o)

# BUILD
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

# RULES
all:
	make $(NAME)
bonus:
	make $(NAME)
clean:s
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: 
	make fclean
	make all
.PHONY: all clean fclean re bonus