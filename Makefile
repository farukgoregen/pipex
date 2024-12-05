NAME = pipex
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak
SRCS =libft/ft_strlen.c \
        libft/ft_memset.c \
        libft/ft_bzero.c \
        libft/ft_strlcpy.c \
        libft/ft_strlcat.c \
        libft/ft_strnstr.c \
        libft/ft_calloc.c \
        libft/ft_substr.c \
        libft/ft_strjoin.c \
        libft/ft_split.c \
        libft/ft_memcpy.c\
        libft/ft_strdup.c
PIPE = pipex.c ultis.c

OBJS = $(SRCS:.c=.o)
FT = $(PIPE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT)
	$(CC) -o $(NAME) $(OBJS) $(FT) -fsanitize=address -fsanitize=leak

clean:
	rm -f $(OBJS) $(FT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
