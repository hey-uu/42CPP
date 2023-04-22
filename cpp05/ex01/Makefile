.DEFAULT_GOAL					=	all

# PROGRAM NAME
NAME							=	ex00

# COMPILE FLAGS
CXX								=	c++
CXXFLAGS						=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS_SANITIZE				=	-fsanitize=address -g3
ifdef SANITIZE
CXXFLAGS						+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS							=	main.cpp Bureaucrat.cpp Form.cpp
OBJS							=	$(SRCS:.cpp=.o)

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
	$(RM) out
fclean: clean
	$(RM) $(NAME)
re: 
	make fclean
	make all
test:
	make && ./ex00 &> out

.PHONY: all clean fclean re bonus test