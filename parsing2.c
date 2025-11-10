/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:46:20 by vfidelis          #+#    #+#             */
/*   Updated: 2025/03/11 14:44:18 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aux_verify_floodf(char **matrix, t_matrix *ft_matrix)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (matrix[x] != NULL)
	{
		while (matrix[x][y] != '\0')
		{
			if (matrix[x][y] == 'C')
			{
				ft_free(matrix);
				free(ft_matrix->matrix_map);
				ft_free_lst(ft_matrix->ft_map);
				ft_error();
			}
			y++;
		}
		y = 0;
		x++;
	}
	ft_free(matrix);
}

void	aux_ft_checker_wall(int op, size_t *i, t_map *receive, t_matrix *matrix)
{
	if (op == 1)
	{
		while (receive->str[(*i)] == '1')
			(*i)++;
		if ((*i) != matrix->len_y)
		{
			ft_free_lst(matrix->ft_map);
			free(matrix->matrix_map);
			ft_error();
		}
	}
	else if (op == 2)
	{
		(*i) = matrix->len_y - 1;
		if (receive->str[0] != '1' || receive->str[(*i)] != '1')
		{
			ft_free_lst(matrix->ft_map);
			free(matrix->matrix_map);
			ft_error();
		}
	}
}

void	aux_ft_checker_pec01(t_matrix *ft_matrix, int *p, int *e, t_map *map)
{
	char	chr_valid[6];
	int		i;

	i = 0;
	ft_strlcpy(chr_valid, "PEC01", 6);
	while (map->next)
	{
		while (map->str[i] && map->str[i + 1] != '\n' && map->str != NULL)
		{
			if (ft_strrchr(chr_valid, map->str[i]) != 0)
			{
				ft_free_lst(ft_matrix->ft_map);
				ft_error();
			}
			if (map->str[i] == 'E')
				(*e)++;
			if (map->str[i] == 'P')
				(*p)++;
			if (map->str[i] == 'C')
				ft_matrix->c++;
			i++;
		}
		i = 0;
		map = map->next;
	}
}

void	aux_ft_parsing(t_matrix *ft_matrix, int fd)
{
	t_map	*receiver;

	receiver = ft_matrix->ft_map;
	while (receiver->str != NULL)
	{
		ft_lstadd_back(&ft_matrix->ft_map, ft_lstnew(get_next_line(fd)));
		receiver = receiver->next;
	}
	receiver = ft_matrix->ft_map;
	ft_matrix->len_y = ft_last_lst(ft_matrix);
	while (receiver->str != NULL)
	{
		if (ft_strlen_newline(receiver->str) != ft_matrix->len_y)
		{
			ft_free_lst(ft_matrix->ft_map);
			ft_error();
		}
		receiver = receiver->next;
	}
	close(fd);
	ft_matrix->len_x = ft_lstsize(ft_matrix->ft_map) - 1;
	ft_checker_wall(ft_matrix);
}
