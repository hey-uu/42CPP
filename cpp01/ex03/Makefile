.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	humans

# FLAGS
CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS			=	-I.
LDFLAGS				=	
LDLIBS				=	
ifdef SANITIZE
CXXFLAGS			+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS			=	Weapon.cpp \
					HumanA.cpp \
					HumanB.cpp \
					main.cpp
OBJS			=	$(SRCS:.cpp=.o)

# BUILD RULES
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)

# BASIC RULES
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