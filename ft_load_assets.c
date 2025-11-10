/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 05:55:57 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/26 21:57:05 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_assets(t_matrix *matrix)
{
	int		w;
	int		h;

	w = 0;
	h = 0;
	matrix->assets.player = mlx_xpm_file_to_image(matrix->mlx,
			"assets/player.xpm", &w, &h);
	matrix->assets.wall = mlx_xpm_file_to_image(matrix->mlx, "assets/wall.xpm",
			&w, &h);
	matrix->assets.floor = mlx_xpm_file_to_image(matrix->mlx,
			"assets/floor.xpm", &w, &h);
	matrix->assets.collectible = mlx_xpm_file_to_image(matrix->mlx,
			"assets/collectible.xpm", &w, &h);
	matrix->assets.exit = mlx_xpm_file_to_image(matrix->mlx, "assets/exit.xpm",
			&w, &h);
	if (!matrix->assets.player || !matrix->assets.wall || !matrix->assets.floor
		|| !matrix->assets.collectible || !matrix->assets.exit)
	{
		perror("Erro ao carregar os assets");
		exit(1);
	}
}
