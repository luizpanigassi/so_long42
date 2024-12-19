# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:37:32 by luinasci          #+#    #+#              #
#    Updated: 2024/12/17 18:53:52 by luinasci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIB			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	test_hooks.c\
				test_main.c\
				test_validators.c

OBJS		=	$(SRCS:.c=.o)

MLX_DIR     = mlx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES    = -I$(MLX_DIR) -I/usr/include -I.

INCLUDES	=	ft_so_long.h

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX_LIB)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
			@make -c $(MLX_DIR)

%.o: %.c $(INCLUDES)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) $(OBJS)
			@make -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			@make -C $(MLX_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re
