SRCS = pipex.c pipex_utils_1.c pipex_utils_2.c

BONUS_SRCS = pipex_bonus.c pipex_bonus_utils_1.c pipex_bonus_utils_2.c

NAME = pipex

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): 
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

bonus:
	${CC} ${FLAGS} ${BONUS_SRCS} -o ${NAME}_bonus

clean:
	rm -rf *.txt

fclean: clean
	rm -rf ${NAME}
	rm -rf ${NAME}_bonus

re:	fclean all

.PHONY: all clean fclean re bonus