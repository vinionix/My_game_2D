/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:42:42 by vfidelis          #+#    #+#             */
/*   Updated: 2025/03/11 15:04:04 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_matrix *matrix, int dy, int dx)
{
	if (matrix->matrix_map[dx][dy] != '1')
	{
		if (matrix->matrix_map[dx][dy] == 'C'
			|| matrix->matrix_map[dx][dy] != 'E')
		{
			matrix->player_x = dx;
			matrix->player_y = dy;
			if (matrix->matrix_map[dx][dy] == 'C')
			{
				matrix->c--;
				matrix->matrix_map[dx][dy] = '0';
			}
		}
		matrix->number_move++;
		ft_putnbr_fd(matrix->number_move, 1);
		write(1, "\n", 1);
		if (matrix->matrix_map[dx][dy] == 'E' && matrix->c == 0)
			ft_destroy_win(matrix);
	}
}
