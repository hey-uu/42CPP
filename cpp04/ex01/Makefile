.DEFAULT_GOAL		=	all

# PROGRAM NAME
NAME				=	Animal

# COMPILE FLAGS
CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS				=	main.cpp \
							Animal.cpp \
							Cat.cpp \
							Dog.cpp \
							WrongAnimal.cpp \
							WrongCat.cpp \
							Brain.cpp
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
	$(RM) out
re: 
	make fclean
	make all
test:
	make all
	./Animal &> out

.PHONY: all clean fclean re bonus test