/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:56:46 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/25 15:58:13 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_assets(t_matrix *matrix)
{
	if (matrix->assets.player != NULL)
		mlx_destroy_image(matrix->mlx, matrix->assets.player);
	if (matrix->assets.wall != NULL)
		mlx_destroy_image(matrix->mlx, matrix->assets.wall);
	if (matrix->assets.collectible != NULL)
		mlx_destroy_image(matrix->mlx, matrix->assets.collectible);
	if (matrix->assets.floor != NULL)
		mlx_destroy_image(matrix->mlx, matrix->assets.floor);
	if (matrix->assets.exit != NULL)
		mlx_destroy_image(matrix->mlx, matrix->assets.exit);
}

void	ft_free(char **matrix)
{
	int		i;

	i = 0;
	if (matrix != NULL)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}
