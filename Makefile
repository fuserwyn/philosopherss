NAME = philo

NAME_BONUS = philo_bonus

SRC			=	src/phil.c\
				src/inition.c\
				src/utils.c\
				src/live.c\
				src/actions.c\

CC 			= gcc -Wall -Wextra -Werror

INCLUDES 	= -I.

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME)  $(SRC)

all: $(NAME) $(PH_OBJS) $(INCLUDES)

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
