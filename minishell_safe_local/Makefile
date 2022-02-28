CC = gcc

FLAGS = -Wall -Werror -Wextra -L ./libft -lft -lreadline -L /Users/nmichael/.brew/opt/readline/lib -I/Users/nmichael/.brew/opt/readline/include

INCLUDES = minishell.h

SRC = /Lexer/lexer.c

LIBFT = $(MAKE) -C ./libft

OBJS = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)
$(NAME):
	$(LIBFT) 
	$(CC) $(FLAGS) $(SRC) $^ -o $@

clean:
	rm -f $(OBJECTS)
	rm -f *.a
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

norm:
	norminette $(SRC) minishell.h