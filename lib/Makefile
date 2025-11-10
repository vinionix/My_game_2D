# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 15:51:13 by vfidelis          #+#    #+#              #
#    Updated: 2025/02/13 05:48:49 by vfidelis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = cc
FLAGS = -Wall -Wextra -Werror

FILEC = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_memset.c \
		ft_memmove.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_isprint.c \
		ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c ft_calloc.c \
		ft_bzero.c ft_atoi.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_strjoin.c ft_substr.c ft_itoa.c \
		ft_split.c ft_strtrim.c ft_putchar_fd.c ft_strnstr.c ft_strmapi.c \
		ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FILEB = ft_lstlast_bonus.c ft_lstdelone_bonus.c \
	ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

NAME_BONUS = $(FILEB:.c=.o)
NAME_OBJS = $(FILEC:.c=.o)
REMO = rm -rf
CREATE_LIB = ar -rcs

# Functions

all: $(NAME)
	
$(NAME): $(NAME_OBJS)
	$(CREATE_LIB) $(NAME) $(NAME_OBJS)

%.o: ./%.c 
	$(COMP) $(FLAGS) -I ./ -c $< -o $@
	
bonus: $(NAME_BONUS)
	$(CREATE_LIB) $(NAME) $(NAME_BONUS)
	
clean:
	@$(REMO) $(NAME_OBJS) $(NAME_BONUS)
	
fclean: clean
	@$(REMO) $(NAME)

	
re: fclean all

.PHONY: all clean fclean re bonus
