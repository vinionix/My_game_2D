# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 15:57:43 by vfidelis          #+#    #+#              #
#    Updated: 2025/02/13 08:57:58 by vfidelis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIB = so_long.a
COMP = cc
FLAGS = -Wall -Wextra -Werror
MLX_PATH = minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(MLX_PATH)

FILEC = gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		ft_ber.c \
		parsing.c \
		parsing2.c \
		ft_error.c \
		ft_handle_keypress.c \
		ft_load_assets.c \
		ft_render_map.c \
		ft_move_player.c \
		lib/ft_lstnew_bonus.c \
		lib/ft_lstsize_bonus.c \
		lib/ft_lstadd_back_bonus.c \
		lib/ft_strlen_newline.c \
		lib/ft_free_lst.c \
		lib/ft_strlcpy.c \
		lib/ft_last_lst.c \
		lib/ft_strrchr.c \
		lib/ft_create_matrix.c \
		lib/ft_free.c \
		lib/ft_putnbr_fd.c

NAME_OBJS = $(FILEC:.c=.o)

REMO = rm -rf
CREATE_LIB = ar -rcs
NAME = so_long

all: $(NAME)

$(LIB): $(NAME_OBJS)
	$(CREATE_LIB) $(LIB) $(NAME_OBJS)

$(NAME): $(LIB)
	$(COMP) $(FLAGS) main.c $(LIB) -o $(NAME) $(INCLUDES) $(MLX_FLAGS) 

.o:.c
	$(COMP) -g $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(REMO) $(NAME_OBJS)

fclean: clean
	@$(REMO) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
