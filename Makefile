NAME = so_long
SRC = 	src/so_long \
		src/errors\
		src/utils\
		gnl/get_next_line\

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address
LINKS = -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(SRC:=.o) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LINKS) $(LIBFT) -o $(NAME)
	echo "\033[1;36mSo_long is ready!"

%.o: %.c
	$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(SRC:=.o)
	#make clean -C mlx_linux
	make clean -C libft
	echo "\033[1;36mSo_long files removed!"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make fclean -C libft
	echo "\033[1;36mTotally clean!"

re: fclean all

.PHONY: all clean fclean re
