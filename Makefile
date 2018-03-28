# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 16:57:42 by fdikilu           #+#    #+#              #
#    Updated: 2018/03/28 11:19:29 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_ls

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

GFLAGS = -fsanitize=address -Wall -Wextra -Werror

SRC =\
	ft_content_swap.c \
	ft_sort.c \
	ft_pwd.c \
	ft_grp.c \
	ft_mode.c \
	ft_time.c \
	ft_timecmp.c \
	ft_isnotdir.c \
	ft_readdir.c \
	ft_parse.c \
	main.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re $(LIB) $(NAME)

all: $(LIB) $(NAME)

$(LIB):
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME): $(OBJ)
	@$(CC) $(GFLAGS) -o $@ $^ $(LIB)

%.o: %.c
	@$(CC) $(GFLAGS) -o $@ -c $<

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@rm -f $(OBJ)

fclean: clean
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@rm -f $(NAME)

re: fclean all
