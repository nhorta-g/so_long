NAME = so_long
FLAGS = -Wall -Wextra -Werror
SRC =   src/so_long.c

all: $(NAME)

$(NAME):
	cd mlx/ && ./configure
	gcc -g3 -fsanitize=address -o $(NAME) $(SRC)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
