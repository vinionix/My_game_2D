/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:11:16 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/26 22:36:48 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_win(t_matrix *matrix)
{
	mlx_destroy_image(matrix->mlx, matrix->assets.player);
	mlx_destroy_image(matrix->mlx, matrix->assets.wall);
	mlx_destroy_image(matrix->mlx, matrix->assets.floor);
	mlx_destroy_image(matrix->mlx, matrix->assets.collectible);
	mlx_destroy_image(matrix->mlx, matrix->assets.exit);
	mlx_destroy_window(matrix->mlx, matrix->win);
	if (matrix->mlx)
		mlx_destroy_display(matrix->mlx);
	free(matrix->mlx);
	if (matrix->matrix_map)
		free(matrix->matrix_map);
	if (matrix->ft_map)
		ft_free_lst(matrix->ft_map);
	exit(0);
	return (0);
}

void	player_pos(t_matrix *matrix)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	matrix->player_x = 0;
	matrix->player_y = 0;
	while (x < (int)matrix->len_x - 1)
	{
		while (y < (int)matrix->len_y - 1)
		{
			if (matrix->matrix_map[x][y] == 'P')
			{
				matrix->player_x = x;
				matrix->player_y = y;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	ft_handle_keypress(int keycode, t_matrix *matrix)
{
	if (keycode == ESC_KEY)
		ft_destroy_win(matrix);
	else if (keycode == W_KEY)
		ft_move_player(matrix, matrix->player_y, matrix->player_x - 1);
	else if (keycode == S_KEY)
		ft_move_player(matrix, matrix->player_y, matrix->player_x + 1);
	else if (keycode == A_KEY)
		ft_move_player(matrix, matrix->player_y - 1, matrix->player_x);
	else if (keycode == D_KEY)
		ft_move_player(matrix, matrix->player_y + 1, matrix->player_x);
	mlx_clear_window(matrix->mlx, matrix->win);
	ft_render_map(matrix);
	mlx_put_image_to_window(matrix->mlx, matrix->win, matrix->assets.player,
		matrix->player_y * 64, matrix->player_x * 64);
	return (0);
}
