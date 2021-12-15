NAME = philo

SRC			=	src/phil.c\
				src/inition.c\
				src/utils.c\
				src/live.c\
				src/actions.c\

CC 			= gcc

FLAGS		= -Wall -Wextra -Werror

INCLUDES 	= includes/philosophers.h

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(INCLUDES)

%.o: %.c $(INCLUDES)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette **/*.c
	norminette src/**/*.c
	norminette **/*.h

.PHONY: all clean fclean re
