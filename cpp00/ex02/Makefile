.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	bank

# COMPILE FLAGS
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
CFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS		=	-I.
ifdef SANITIZE
CFLAGS			+=	$(CFLAGS_SANITIZE)
endif

# FILES
SRCS			=	Account.cpp tests.cpp
OBJS			=	$(SRCS:.cpp=.o)

# BUILD
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

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
