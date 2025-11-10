/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:51:55 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/27 17:55:28 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	aux_ft_create_matrix(t_matrix *ft_matrix, char **matrix, t_map *map)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (map->next != NULL)
	{
		matrix[i] = malloc(sizeof(char) * (ft_strlen(map->str) + 1));
		while (map->str[j])
		{
			matrix[i][j] = map->str[j];
			j++;
		}
		matrix[i][j] = '\0';
		j = 0;
		i++;
		map = map->next;
	}
}

void	ft_create_matrix(t_matrix *ft_matrix, char **matrix, int options)
{
	t_map	*map;
	size_t	i;

	i = 0;
	map = ft_matrix->ft_map;
	if (options == 1)
	{
		ft_matrix->matrix_map = malloc(sizeof(char *) * ft_lstsize(map));
		while (map->next)
		{
			map->str[ft_strlen(map->str)] = '\0';
			ft_matrix->matrix_map[i] = map->str;
			i++;
			map = map->next;
		}
		ft_matrix->matrix_map[i] = NULL;
	}
	else
		aux_ft_create_matrix(ft_matrix, matrix, map);
}
