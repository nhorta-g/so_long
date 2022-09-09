NAME = so_long
FLAGS = -Wall -Wextra -Werror
SRC =	src/so_long.c \
		src/utils.c \

LIB = -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	cd mlx/ && ./configure
	gcc -g3 -fsanitize=address $(SRC) $(LIB) -o $(NAME)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
