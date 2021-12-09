NAME = philo

NAME_BONUS = philo_bonus

SRC			=	src/phil.c\
				src/inition.c\
				src/utils.c\
				src/live.c\
				src/actions.c\


BONUS_SRCS	= src/main_bonus.c\
				src/utils_bonus.c\
				src/inition_bonus.c\
				src/actions_bonus.c\


CC 			= gcc -Wall -Wextra -Werror

HEADER = philosophers.h

HEADER_BONUS = philosophers_bonus.h

OBJ_SRC 	= $(SRC:.c=.o)

OBJ_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): 			$(OBJ_SRC)
					$(CC) $(OBJ_SRC) -o $(NAME)


%.o:	%.c $(HEADER)
	$(CC) -c $< -o $@

bonus:
	@make OBJ_SRC="$(OBJ_BONUS)" HEADER="$(HEADER_BONUS)" NAME="$(NAME_BONUS)" all

clean:
	rm -rf $(OBJS) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

norm:
	norminette **/*.c
	norminette src/**/*.c
	norminette **/*.h

.PHONY: all clean fclean re
