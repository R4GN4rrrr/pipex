NAME = pipex

SOURCES =  pipex.c pipex_utils.c \
		./libft/ft_split.c \
		./libft/ft_strjoin.c \
		./libft/ft_strnstr.c \
		./libft/ft_strlen.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
