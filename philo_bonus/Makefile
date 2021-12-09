NAME_BONUS = philo_bonus

BONUS_SRCS	= src/philo_bonus.c\
				src/utils_bonus.c\
				src/inition_bonus.c\
				src/actions_bonus.c\
				src/live_bonus.c\
				src/be_free.c\

CC 			= gcc -Wall -Wextra -Werror

HEADER_BONUS = philosophers_bonus.h

OBJ_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): 			$(OBJ_SRC)
					$(CC) $(OBJ_SRC) -o $(NAME)


%.o:	%.c $(HEADER)
	$(CC) -c $< -o $@

bonus:
	@make OBJ_SRC="$(OBJ_BONUS)" HEADER="$(HEADER_BONUS)" NAME="$(NAME_BONUS)" all

clean:
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME_BONUS)

re: fclean all

norm:
	norminette **/*.c
	norminette src/**/*.c
	norminette **/*.h

.PHONY: all clean fclean re
