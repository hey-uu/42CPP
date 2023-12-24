.DEFAULT_GOAL					=	all

# PROGRAM NAME
NAME							=	ex01

# COMPILE FLAGS
CXX								=	c++
CXXFLAGS						=	-Wall -Wextra -Werror
# -std=c++98
CXXFLAGS_SANITIZE				=	-fsanitize=address -g3
ifdef SANITIZE
CXXFLAGS						+=	$(CXXFLAGS_SANITIZE)
endif

# FILES
SRCS							=	main.cpp Serializer.cpp
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
	$(RM) out.txt
fclean: clean
	$(RM) $(NAME)
re: 
	make fclean
	make all
test:
	make
	./ex01 &> out.txt

.PHONY: all clean fclean re bonus test
