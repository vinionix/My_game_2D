/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 05:49:12 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/26 21:43:57 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_matrix *matrix)
{
	int		x;
	int		y;

	x = 0;
	while (x < (int)matrix->len_x)
	{
		y = 0;
		while (y < (int)matrix->len_y)
		{
			mlx_put_image_to_window(matrix->mlx, matrix->win,
				matrix->assets.floor, y * 64, x * 64);
			if (matrix->matrix_map[x][y] == '1')
				mlx_put_image_to_window(matrix->mlx, matrix->win,
					matrix->assets.wall, y * 64, x * 64);
			else if (matrix->matrix_map[x][y] == 'C')
				mlx_put_image_to_window(matrix->mlx, matrix->win,
					matrix->assets.collectible, y * 64, x * 64);
			else if (matrix->matrix_map[x][y] == 'E')
				mlx_put_image_to_window(matrix->mlx, matrix->win,
					matrix->assets.exit, y * 64, x * 64);
			y++;
		}
		x++;
	}
}
