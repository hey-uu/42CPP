.DEFAULT_GOAL	=	all

# PROGRAM NAME
NAME			=	zombie

# FLAGS
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS		=	-I.
LDFLAGS			=	
LDLIBS			=	
ifdef SANITIZE
CFLAGS			+=	$(CFLAGS_SANITIZE)
endif

# FILES
SRCS			=	
OBJS			=	$(SRCS:.c=.o)

# BUILD RULES
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)

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