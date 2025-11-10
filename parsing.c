/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/26 22:32:12 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/26 22:32:12 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(char **grid, int l, int c, t_matrix *ft_matrix)
{
	if (l < 0 || c < 0 || l >= (int)ft_matrix->len_x
		|| c >= (int)ft_matrix->len_y)
		return ;
	if (grid[l][c] != '0' && grid[l][c] != 'C' && grid[l][c] != 'P')
		return ;
	grid[l][c] = 'F';
	ft_flood_fill(grid, l - 1, c, ft_matrix);
	ft_flood_fill(grid, l + 1, c, ft_matrix);
	ft_flood_fill(grid, l, c - 1, ft_matrix);
	ft_flood_fill(grid, l, c + 1, ft_matrix);
}

void static	ft_verify_floodf(t_matrix *ft_matrix)
{
	char	**matrix;
	int		l;
	int		c;

	l = 0;
	c = 0;
	matrix = malloc(sizeof(char *) * (ft_matrix->len_x + 1));
	matrix[ft_matrix->len_x] = NULL;
	ft_create_matrix(ft_matrix, matrix, 2);
	while (matrix[l] != NULL)
	{
		while (matrix[l][c] != 'P' && (matrix[l][c] != '\0'
				|| matrix[l][c] == '\n'))
			c++;
		if (matrix[l][c] == 'P')
			break ;
		c = 0;
		l++;
	}
	ft_flood_fill(matrix, l, c, ft_matrix);
	aux_verify_floodf(matrix, ft_matrix);
}

static void	ft_checker_pec01(t_matrix *ft_matrix, int i)
{
	t_map	*map;
	int		p;
	int		e;

	p = 0;
	e = 0;
	map = ft_matrix->ft_map;
	ft_matrix->c = 0;
	map = ft_matrix->ft_map;
	aux_ft_checker_pec01(ft_matrix, &p, &e, map);
	if (p != 1 || e != 1 || ft_matrix->c == 0)
	{
		ft_free_lst(ft_matrix->ft_map);
		free(ft_matrix->matrix_map);
		ft_error();
	}
	ft_create_matrix(ft_matrix, NULL, 1);
	ft_verify_floodf(ft_matrix);
}

void	ft_checker_wall(t_matrix *ft_matrix)
{
	t_map	*receiver;
	size_t	i;

	if (ft_matrix->len_x == ft_matrix->len_y)
	{
		ft_free_lst(ft_matrix->ft_map);
		free(ft_matrix->matrix_map);
		ft_error();
	}
	receiver = ft_matrix->ft_map;
	while (receiver->next != NULL)
	{
		i = 0;
		if (receiver->prev == NULL || receiver->next == NULL)
			aux_ft_checker_wall(1, &i, receiver, ft_matrix);
		else if (receiver->str != NULL)
			aux_ft_checker_wall(2, &i, receiver, ft_matrix);
		receiver = receiver->next;
	}
	i = 0;
	ft_checker_pec01(ft_matrix, i);
}

void	ft_parsing(char *argv, t_matrix *ft_matrix)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_error();
	}
	ft_matrix->ft_map = ft_lstnew(get_next_line(fd));
	if (ft_matrix->ft_map->str == NULL)
	{
		ft_free_lst(ft_matrix->ft_map);
		close(fd);
		ft_error();
	}
	aux_ft_parsing(ft_matrix, fd);
}
