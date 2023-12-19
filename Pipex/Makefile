SRCS = pipex.c pipex_utils_1.c pipex_utils_2.c

NAME = pipex

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): 
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf *.txt

fclean: clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re