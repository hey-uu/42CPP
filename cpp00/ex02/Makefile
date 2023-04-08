.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	bank

# COMPILE FLAGS
CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS			=	-I.
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS			=	Account.cpp tests.cpp
OBJS			=	$(SRCS:.cpp=.o)

# BUILD
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

# RULES
all:
	make $(NAME)
bonus:
	make $(NAME)
clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
re: 
	make fclean
	make all
.PHONY: all clean fclean re bonus
