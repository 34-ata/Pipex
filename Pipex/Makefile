SRCS = ft_split.c ft_strchr.c ft_strjoin.c ft_strncmp.c ft_substr.c pipex.c ft_strlen.c ft_strlcpy.c ft_strdup.c

NAME = pipex

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): 
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean
	rm -rf ${NAME}

re:	fclean all