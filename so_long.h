/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:58:38 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 08:26:16 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC_KEY 65307
# define W_KEY   119
# define A_KEY   97
# define S_KEY   115
# define D_KEY   100

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "lib/libft.h"

typedef struct j_list
{
	struct j_list	*prev;
	char			*str;
	struct j_list	*next;
}	t_map;

typedef struct s_assets
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
}	t_assets;

typedef struct h_list
{
	void				*mlx;
	void				*win;
	char				**matrix_map;
	size_t				len_x;
	size_t				len_y;
	size_t				c;
	int					player_y;
	int					player_x;
	int					number_move;
	t_map				*ft_map;
	t_assets			assets;
}	t_matrix;

t_map	*ft_lstnew(char *content);

size_t	ft_lstsize(t_map *lst);

size_t	ft_strlen_newline(char *str);

size_t	ft_len_last(t_map *ft_map);

size_t	ft_last_lst(t_matrix *ft_matrix);

size_t	ft_strrchr(const char *str, int c);

void	ft_lstadd_back(t_map **lst, t_map *new);

void	ft_free_lst(t_map *a);

void	ft_parsing(char *argv, t_matrix *matrix);

void	ft_checker_wall(t_matrix *ft_matrix);

void	aux_ft_parsing(t_matrix *ft_matrix, int fd);

void	aux_verify_floodf(char **matrix, t_matrix *ft_matrix);

void	aux_ft_checker_pec01(t_matrix *ft_matrix, int *p, int *e, t_map *map);

void	aux_ft_checker_wall(int op, size_t *i, t_map *receive,
			t_matrix *matrix);

void	ft_ber(char *str);

void	ft_error(void);

void	ft_create_matrix(t_matrix *ft_matrix, char **matrix, int opitions);

void	ft_render_map(t_matrix *matrix);

void	ft_load_assets(t_matrix *matrix);

void	ft_move_player(t_matrix *matrix, int dy, int dx);

void	player_pos(t_matrix *matrix);

void	ft_free(char **matrix);

void	free_assets(t_matrix *matrix);

int		ft_destroy_win(t_matrix *matrix);

int		ft_handle_keypress(int keycode, t_matrix *matrix);

#endif
