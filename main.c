/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:33:05 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/25 15:33:05 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_matrix	matrix;

	matrix.matrix_map = NULL;
	if (argc != 2)
		ft_error();
	ft_ber(argv[1]);
	ft_parsing(argv[1], &matrix);
	matrix.mlx = mlx_init();
	matrix.win = mlx_new_window(matrix.mlx, matrix.len_y * 64, matrix.len_x
			* 64, "so_long");
	player_pos(&matrix);
	ft_load_assets(&matrix);
	ft_render_map(&matrix);
	matrix.number_move = 0;
	mlx_hook(matrix.win, 17, 0, ft_destroy_win, &matrix);
	mlx_key_hook(matrix.win, ft_handle_keypress, &matrix);
	mlx_loop(matrix.mlx);
}
