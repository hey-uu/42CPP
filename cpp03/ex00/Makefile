.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	fixedPoint

# COMPILE FLAGS
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
CFLAGS_SANITIZE	=	-fsanitize=address -g3
ifdef SANITIZE
CFLAGS			+=	$(CFLAGS_SANITIZE)
endif

# FILES
SRCS			=	main.cpp
OBJS			=	$(SRCS:.cpp=.o)

# BUILD
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

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