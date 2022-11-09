# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 11:06:33 by nhorta-g          #+#    #+#              #
#    Updated: 2022/11/09 14:52:04 by nhorta-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strcat.c ft_strcmp.c
BSRC = \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

%.o:%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

bonus:	$(NAME) $(BOBJ) $(OBJ)
		ar rcs $(NAME) $(BOBJ) $(OBJ)

clean:
		rm -f $(OBJ) $(BOBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean	$(NAME)

reb:	fclean b

.PHONY:	all clean fclean re
