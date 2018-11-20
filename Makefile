# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 16:57:42 by fdikilu           #+#    #+#              #
#    Updated: 2018/11/20 20:58:52 by fdikilu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_ls

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC =\
	ft_content_swap.c \
	ft_tools.c \
	ft_blocks.c \
	ft_lsizecolonne.c \
	ft_loption.c \
	ft_sort.c \
	ft_pwd.c \
	ft_grp.c \
	ft_mode.c \
	ft_time.c \
	ft_timecmp.c \
	ft_free.c \
	ft_isnotdir.c \
	ft_readdir.c \
	ft_parse.c \
	ft_listdir.c \
	ft_initflag.c \
	ft_printfile.c \
	ft_display.c \
	ft_ls.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re $(LIB) $(NAME)

all: $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all
