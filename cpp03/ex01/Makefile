.DEFAULT_GOAL		=	all

# PROGRAM NAME
NAME				=	ClapTrap

# COMPILE FLAGS
CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS				=	main.cpp ClapTrap.cpp ScavTrap.cpp AbcTrap.cpp
OBJS				=	$(SRCS:.cpp=.o)

# BUILD
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# RULES
all:
	make $(NAME)
bonus:
	make $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus