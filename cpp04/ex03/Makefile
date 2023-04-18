.DEFAULT_GOAL		=	all

# PROGRAM NAME
NAME				=	ex03

# COMPILE FLAGS
CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS				=	main.cpp \
							AMateria.cpp \
							Character.cpp \
							Cure.cpp \
							Ice.cpp \
							MateriaSource.cpp \
							debug_msg.cpp
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
	$(RM) out
	$(RM) $(NAME)
re: 
	make fclean
	make all
test:
	make re -j8
	./ex03 &> out

.PHONY: all clean fclean re bonus test
